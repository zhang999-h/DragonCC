#include "codegen.h"
#include "scope.h"

#define INT32_TYPE (Type::getInt32Ty(*TheContext))
#define FLOAT_TYPE (Type::getFloatTy(*TheContext))
#define VOID_TYPE (Type::getVoidTy(*TheContext))

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
  auto ret_type = INT32_TYPE;
  FunctionType* FT =
    FunctionType::get(ret_type, false);

  Function* F =
    Function::Create(FT, Function::ExternalLinkage, *(ast.id.get()), TheModule.get());
  TheFunction = F;
  BasicBlock* BB = BasicBlock::Create(*TheContext, "entry", F);
  // 创建统一return分支
  retBB = BasicBlock::Create(*TheContext, "label_ret", F);

  retAlloca = CreateEntryBlockAlloca(TheFunction, "ret_alloca",ret_type);
  Builder->SetInsertPoint(retBB);
  auto ret_load = Builder->CreateLoad(retAlloca->getType(), retAlloca, "ret_val");
  Builder->CreateRet(ret_load);
  // if (retType == VOID_T) {//TODO
  //   // void类型无需返回值
  //   builder->BB_ = retBB;
  //   builder->create_void_ret();
  // } else {
  //   retAlloca = builder->create_alloca(retType); // 在内存中分配返回值的位置
  //   builder->BB_ = retBB;
  //   auto retLoad = builder->create_load(retAlloca);
  //   builder->create_ret(retLoad);
  // }
  Builder->SetInsertPoint(BB);
  ast.block->accept(*this);
  retBB->moveAfter(&TheFunction->back());
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
  AllocaInst* Alloca = CreateEntryBlockAlloca(TheFunction, *(ast.id.get()),curType);
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
  case SEL:
    ast.selectStmt->accept(*this);
    break;
  case RET:
    ast.returnStmt->accept(*this);
    break;
  }
}

void GenIR::visit(ReturnStmtAST& ast) {
  if (ast.exp == nullptr) {
    Builder->CreateStore(0, retAlloca);
    recentVal = Builder->CreateBr(retBB);
  }
  else {
    // 先把返回值store在retAlloca中，再跳转到统一的返回入口
    ast.exp->accept(*this);
    Builder->CreateStore(recentVal, retAlloca);
    // TODO:类型转换
    // if (recentVal->type_ == FLOAT_T &&
    //   currentFunction->get_return_type() == INT32_T) {
    //   auto temp = builder->create_fptosi(recentVal, INT32_T);
    //   builder->create_store(temp, retAlloca);
    // }
    // else if (recentVal->type_ == INT32_T &&
    //   currentFunction->get_return_type() == FLOAT_T) {
    //   auto temp = builder->create_sitofp(recentVal, FLOAT_T);
    //   builder->create_store(temp, retAlloca);
    // }
    // else
    //   builder->create_store(recentVal, retAlloca);
    recentVal = Builder->CreateBr(retBB);
  }
}

void GenIR::visit(SelectStmtAST& ast) {
  ast.cond->accept(*this);
  auto cond_val = recentVal;
  BasicBlock* ThenBB = BasicBlock::Create(*TheContext, "if.then", TheFunction);
  BasicBlock* EndBB = BasicBlock::Create(*TheContext, "if.end");
  BasicBlock* NextBB, * ElseBB;
  if (ast.elseStmt) {
    ElseBB = BasicBlock::Create(*TheContext, "if.else", TheFunction);
    NextBB = ElseBB;
  }
  else {
    NextBB = EndBB;
  }
  Builder->CreateCondBr(cond_val, ThenBB, NextBB);
  Builder->SetInsertPoint(ThenBB);
  ast.ifStmt->accept(*this);
  Builder->CreateBr(EndBB);

  if (ast.elseStmt) {
    Builder->SetInsertPoint(ElseBB);
    ast.elseStmt->accept(*this);
    Builder->CreateBr(EndBB);
  }
  TheFunction->insert(TheFunction->end(), EndBB);
  Builder->SetInsertPoint(EndBB);


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

void GenIR::visit(RelExpAST& ast) {
  if (ast.relExp == nullptr) {
    ast.addExp->accept(*this);
    return;
  }
  Value* val[2];
  ast.relExp->accept(*this);
  val[0] = recentVal;
  ast.addExp->accept(*this);
  val[1] = recentVal;
  //checkCalType(val);
  //TODO : 不同类型比较
  if (val[0]->getType()->isIntegerTy(32) && val[1]->getType()->isIntegerTy(32)) {
    switch (ast.op) {
    case ROP_LTE:
      recentVal = Builder->CreateICmpSLT(val[0], val[1]);
      break;
    case ROP_LT:
      recentVal = Builder->CreateICmpSLT(val[0], val[1]);
      break;
    case ROP_GT:
      recentVal = Builder->CreateICmpSGT(val[0], val[1]);
      break;
    case ROP_GTE:
      recentVal = Builder->CreateICmpSGE(val[0], val[1]);
      break;
    }
  }
  // else {
  //   switch (ast.op) {
  //   case ROP_LTE:
  //     recentVal = builder->create_fcmp_le(val[0], val[1]);
  //     break;
  //   case ROP_LT:
  //     recentVal = builder->create_fcmp_lt(val[0], val[1]);
  //     break;
  //   case ROP_GT:
  //     recentVal = builder->create_fcmp_gt(val[0], val[1]);
  //     break;
  //   case ROP_GTE:
  //     recentVal = builder->create_fcmp_ge(val[0], val[1]);
  //     break;
  //   }
  // }
}

void GenIR::visit(EqExpAST& ast) {
  if (ast.eqExp == nullptr) {
    ast.relExp->accept(*this);
    return;
  }
  Value* val[2];
  ast.eqExp->accept(*this);
  val[0] = recentVal;
  ast.relExp->accept(*this);
  val[1] = recentVal;
  //checkCalType(val);
  if (val[0]->getType()->isIntegerTy(32) && val[1]->getType()->isIntegerTy(32)) {
    switch (ast.op) {
    case EOP_EQ:
      recentVal = Builder->CreateICmpEQ(val[0], val[1]);
      break;
    case EOP_NEQ:
      recentVal = Builder->CreateICmpNE(val[0], val[1]);
      break;
    }
  }
  // else {
  //   switch (ast.op) {
  //   case EOP_EQ:
  //     recentVal = builder->create_fcmp_eq(val[0], val[1]);
  //     break;
  //   case EOP_NEQ:
  //     recentVal = builder->create_fcmp_ne(val[0], val[1]);
  //     break;
  //   }
  // }
}

void GenIR::visit(LAndExpAST& ast) {
  if (ast.lAndExp == nullptr) {
    ast.eqExp->accept(*this);
    return;
  }
  // auto tempTrue = trueBB; // 防止嵌套and导致原trueBB丢失。用于生成短路模块
  // trueBB = new BasicBlock(module.get(), to_string(id++), currentFunction);
  // ast.lAndExp->accept(*this);

  // if (recentVal->type_ == INT32_T) {
  //   recentVal = builder->create_icmp_ne(recentVal, CONST_INT(0));
  // }
  // else if (recentVal->type_ == FLOAT_T) {
  //   recentVal = builder->create_fcmp_ne(recentVal, CONST_FLOAT(0));
  // }
  // builder->create_cond_br(recentVal, trueBB, falseBB);
  // builder->BB_ = trueBB;
  // has_br = false;
  // trueBB = tempTrue; // 还原原来的true模块

  // ast.eqExp->accept(*this);
}

void GenIR::visit(LOrExpAST& ast) {
  if (ast.lOrExp == nullptr) {
    ast.lAndExp->accept(*this);
    return;
  }
  // auto tempFalse = falseBB; // 防止嵌套and导致原trueBB丢失。用于生成短路模块
  // falseBB = new BasicBlock(module.get(), to_string(id++), currentFunction);
  // ast.lOrExp->accept(*this);
  // if (recentVal->type_ == INT32_T) {
  //   recentVal = builder->create_icmp_ne(recentVal, CONST_INT(0));
  // }
  // else if (recentVal->type_ == FLOAT_T) {
  //   recentVal = builder->create_fcmp_ne(recentVal, CONST_FLOAT(0));
  // }
  // builder->create_cond_br(recentVal, trueBB, falseBB);
  // builder->BB_ = falseBB;
  // has_br = false;
  // falseBB = tempFalse;

  // ast.lAndExp->accept(*this);
}
