#include "codegen.h"
#include "scope.h"

#define INT32_TYPE (Type::getInt32Ty(*TheContext))
#define FLOAT_TYPE (Type::getFloatTy(*TheContext))

GenIR::GenIR(/* args */)
{
    TheContext = std::make_unique<LLVMContext>();
    TheModule = std::make_unique<Module>("DragonCC", *TheContext);
    //TheModule->setDataLayout(TheJIT->getDataLayout());

    // Create a new builder for the module.
    Builder = std::make_unique<IRBuilder<>>(*TheContext);

    isNewFunc = false;
}

GenIR::~GenIR()
{
}

void GenIR::visit(CompUnitAST& ast) {
    for (const auto& def : ast.declDefList) {
        def->accept(*this);
    }
}

void GenIR::visit(DeclDefAST& ast) {
    if (ast.Decl != nullptr) {
        ast.Decl->accept(*this);
    }
    else {
        ast.funcDef->accept(*this);
    }
}

void GenIR::visit(FuncDefAST& ast) {
    // Make the function type:  double(double,double) etc.
    // std::vector<Type*> Doubles(Args.size(),
    //     Type::getDoubleTy(*TheContext));
    scope.Enter();
    FunctionType* FT =
        FunctionType::get(Type::getInt32Ty(*TheContext), false);

    Function* F =
        Function::Create(FT, Function::ExternalLinkage, *(ast.id.get()), TheModule.get());
    TheFunction = F;
    BasicBlock* BB = BasicBlock::Create(*TheContext, "entry", F);
    Builder->SetInsertPoint(BB);
    ast.block->accept(*this);

}

void GenIR::visit(DeclAST& ast) {
    //   isConst = ast.isConst;
    curType = ast.bType == TYPE_INT ? INT32_TYPE : FLOAT_TYPE;
    for (auto& def : ast.defList) {
        def->accept(*this);
    }
}

void GenIR::visit(DefAST& ast) {
    string var_name = *(ast.id.get());
    AllocaInst* Alloca = CreateEntryBlockAlloca(TheFunction, *(ast.id.get()));
    //NamedValues[*(ast.id.get())] = Alloca;
    scope.AddNewVar(var_name, Alloca);
    if (ast.initVal) {
        ast.initVal->accept(*this);
        Builder->CreateStore(recentVal, Alloca);
    }


}

void GenIR::visit(InitValAST& ast) {
    // 不是数组则求exp的值，若是数组不会进入此函数
    if (ast.exp != nullptr) {
        ast.exp->accept(*this);
    }
}

void GenIR::visit(BlockAST& ast) {
    // 如果是一个新的函数，则不用再进入一个新的作用域
    if (isNewFunc)
        isNewFunc = false;
    // 其它情况，需要进入一个新的作用域
    else {
        scope.Enter();
    }

    // 遍历每一个语句块
    for (auto& item : ast.blockItemList) {
        item->accept(*this);
    }

    scope.Leave();
}

void GenIR::visit(BlockItemAST& ast) {
    if (ast.decl != nullptr) {
        ast.decl->accept(*this);
    }
    else {
        ast.stmt->accept(*this);
    }
}

void GenIR::visit(StmtAST& ast) {
    switch (ast.sType) {
    case SEMI:
        break;
    case ASS: {
        // Visit lVal
        isLVal = true;
        ast.lVal->accept(*this);
        // Get lVal
        auto lVal = recentAllocaInst;

        // Visit expression
        ast.exp->accept(*this);
        auto rVal = recentVal;
        // if lVal.type != rVal.type
        // Forge a cast
        // if (lValType != recentVal->type_) {
        //     if (lValType == FLOAT_TYPE) {
        //         rVal = builder->create_sitofp(recentVal, FLOAT_TYPE);
        //     }
        //     else {
        //         rVal = builder->create_fptosi(recentVal, INT32_TYPE);
        //     }
        // }
        // Create a store primitive
        Builder->CreateStore(rVal, lVal);
        break;
    }
    case EXP:
        ast.exp->accept(*this);
    case BLK:
        ast.block->accept(*this);
        break;

    }
}

void GenIR::visit(LValAST& ast) {
    string var_name = *(ast.id);
    AllocaInst* A = scope.FindVar(var_name);
    // right value.
    if (!isLVal) {
        Value* t = Builder->CreateLoad(A->getAllocatedType(), A, (*(ast.id)).c_str());
        recentVal = t;

    }
    // left value
    else {
        recentAllocaInst = A;
    }
    isLVal = false;

}


void GenIR::visit(AddExpAST& ast) {
    if (ast.addExp == nullptr) {
        ast.mulExp->accept(*this);
        return;
    }

    Value* val[2]; // lVal, rVal
    ast.addExp->accept(*this);
    val[0] = recentVal;
    ast.mulExp->accept(*this);
    val[1] = recentVal;
    //TODO ： 类型转换
    switch (ast.op) {
    case AOP_ADD:
        recentVal = Builder->CreateAdd(val[0], val[1]);
        break;
    case AOP_MINUS:
        recentVal = Builder->CreateSub(val[0], val[1]);
        break;
    }
}

void GenIR::visit(MulExpAST& ast) {
    if (ast.mulExp == nullptr) {
        ast.unaryExp->accept(*this);
        return;
    }

    Value* val[2]; // lVal, rVal
    ast.mulExp->accept(*this);
    val[0] = recentVal;
    ast.unaryExp->accept(*this);
    val[1] = recentVal;
    //TODO ： 类型转换
    switch (ast.op) {
    case MOP_MUL:
        recentVal = Builder->CreateAdd(val[0], val[1]);
        break;
    case MOP_DIV:
        recentVal = Builder->CreateSub(val[0], val[1]);
        break;
    case MOP_MOD:
        recentVal = Builder->CreateSRem(val[0], val[1]);
        break;
    }

}
void GenIR::visit(UnaryExpAST& ast) {

    if (ast.primaryExp != nullptr) {
        ast.primaryExp->accept(*this);
    }
}

void GenIR::visit(PrimaryExpAST& ast) {

    if (ast.exp) {
        ast.exp->accept(*this);

    }
    else if (ast.lval) {
        ast.lval->accept(*this);
    }
    else if (ast.number) {
        ast.number->accept(*this);
    }

}

void GenIR::visit(NumberAST& ast) {
    if (ast.isInt) {
        recentVal = ConstantInt::get(INT32_TYPE, ast.intval);
    }
    //recentVal = CONST_INT(ast.intval);

}

void GenIR::visit(RelExpAST &ast) {
  if (ast.relExp == nullptr) {
    ast.addExp->accept(*this);
    return;
  }
  Value *val[2];
  ast.relExp->accept(*this);
  val[0] = recentVal;
  ast.addExp->accept(*this);
  val[1] = recentVal;
  checkCalType(val);
  if (val[0]->type_ == INT32_T) {
    switch (ast.op) {
    case ROP_LTE:
      recentVal = builder->create_icmp_le(val[0], val[1]);
      break;
    case ROP_LT:
      recentVal = builder->create_icmp_lt(val[0], val[1]);
      break;
    case ROP_GT:
      recentVal = builder->create_icmp_gt(val[0], val[1]);
      break;
    case ROP_GTE:
      recentVal = builder->create_icmp_ge(val[0], val[1]);
      break;
    }
  } else {
    switch (ast.op) {
    case ROP_LTE:
      recentVal = builder->create_fcmp_le(val[0], val[1]);
      break;
    case ROP_LT:
      recentVal = builder->create_fcmp_lt(val[0], val[1]);
      break;
    case ROP_GT:
      recentVal = builder->create_fcmp_gt(val[0], val[1]);
      break;
    case ROP_GTE:
      recentVal = builder->create_fcmp_ge(val[0], val[1]);
      break;
    }
  }
}

void GenIR::visit(EqExpAST &ast) {
  if (ast.eqExp == nullptr) {
    ast.relExp->accept(*this);
    return;
  }
  Value *val[2];
  ast.eqExp->accept(*this);
  val[0] = recentVal;
  ast.relExp->accept(*this);
  val[1] = recentVal;
  checkCalType(val);
  if (val[0]->type_ == INT32_T) {
    switch (ast.op) {
    case EOP_EQ:
      recentVal = builder->create_icmp_eq(val[0], val[1]);
      break;
    case EOP_NEQ:
      recentVal = builder->create_icmp_ne(val[0], val[1]);
      break;
    }
  } else {
    switch (ast.op) {
    case EOP_EQ:
      recentVal = builder->create_fcmp_eq(val[0], val[1]);
      break;
    case EOP_NEQ:
      recentVal = builder->create_fcmp_ne(val[0], val[1]);
      break;
    }
  }
}

void GenIR::visit(LAndExpAST &ast) {
  if (ast.lAndExp == nullptr) {
    ast.eqExp->accept(*this);
    return;
  }
  auto tempTrue = trueBB; // 防止嵌套and导致原trueBB丢失。用于生成短路模块
  trueBB = new BasicBlock(module.get(), to_string(id++), currentFunction);
  ast.lAndExp->accept(*this);

  if (recentVal->type_ == INT32_T) {
    recentVal = builder->create_icmp_ne(recentVal, CONST_INT(0));
  } else if (recentVal->type_ == FLOAT_T) {
    recentVal = builder->create_fcmp_ne(recentVal, CONST_FLOAT(0));
  }
  builder->create_cond_br(recentVal, trueBB, falseBB);
  builder->BB_ = trueBB;
  has_br = false;
  trueBB = tempTrue; // 还原原来的true模块

  ast.eqExp->accept(*this);
}

void GenIR::visit(LOrExpAST &ast) {
  if (ast.lOrExp == nullptr) {
    ast.lAndExp->accept(*this);
    return;
  }
  auto tempFalse = falseBB; // 防止嵌套and导致原trueBB丢失。用于生成短路模块
  falseBB = new BasicBlock(module.get(), to_string(id++), currentFunction);
  ast.lOrExp->accept(*this);
  if (recentVal->type_ == INT32_T) {
    recentVal = builder->create_icmp_ne(recentVal, CONST_INT(0));
  } else if (recentVal->type_ == FLOAT_T) {
    recentVal = builder->create_fcmp_ne(recentVal, CONST_FLOAT(0));
  }
  builder->create_cond_br(recentVal, trueBB, falseBB);
  builder->BB_ = falseBB;
  has_br = false;
  falseBB = tempFalse;

  ast.lAndExp->accept(*this);
}
