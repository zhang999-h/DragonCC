#include "codegen.h"
GenIR::GenIR(/* args */)
{
    TheContext = std::make_unique<LLVMContext>();
    TheModule = std::make_unique<Module>("DragonCC", *TheContext);
    //TheModule->setDataLayout(TheJIT->getDataLayout());

    // Create a new builder for the module.
    Builder = std::make_unique<IRBuilder<>>(*TheContext);
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
    FunctionType* FT =
        FunctionType::get(Type::getInt32Ty(*TheContext), false);

    Function* F =
        Function::Create(FT, Function::ExternalLinkage, *(ast.id.get()), TheModule.get());
    ast.block->accept(*this);
}

void GenIR::visit(DeclAST& ast) {
    //   isConst = ast.isConst;
    //   curType = ast.bType == TYPE_INT ? INT32_T : FLOAT_T;
    for (auto& def : ast.defList) {
        def->accept(*this);
    }
}

void GenIR::visit(BlockAST& ast) {
    //   // 如果是一个新的函数，则不用再进入一个新的作用域
    //   if (isNewFunc)
    //     isNewFunc = false;
    //   // 其它情况，需要进入一个新的作用域
    //   else {
    //     scope.enter();
    //   }
    //   // 遍历每一个语句块
    //   for (auto &item : ast.blockItemList) {
    //     if (has_br)
    //       break; // 此BB已经出现了br，后续指令无效
    //     item->accept(*this);
    //   }

    //   scope.exit();
}

void GenIR::visit(BlockItemAST& ast) {
    if (ast.decl != nullptr) {
        ast.decl->accept(*this);
    }
    else {
        ast.stmt->accept(*this);
    }
}


void GenIR::visit(AddExpAST& ast) {
    if (ast.addExp == nullptr) {
        ast.mulExp->accept(*this);
        return;
    }
}

void GenIR::visit(MulExpAST& ast) {
    if (ast.mulExp == nullptr) {
        ast.unaryExp->accept(*this);
        return;
    }
}
void GenIR::visit(UnaryExpAST& ast) {

    if (ast.primaryExp != nullptr) {
        ast.primaryExp->accept(*this);
    }
}

void GenIR::visit(PrimaryExpAST& ast) {

    ast.number->accept(*this);

}

void GenIR::visit(NumberAST& ast) {
    if (ast.isInt) {
        //ConstantInt::get(*TheContext, APInt(ast.intval));
    }
    //recentVal = CONST_INT(ast.intval);

}