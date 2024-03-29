#pragma once
#include "ast.h"
#include "scope.h"
#include <map>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"

using namespace llvm;
class GenIR : public Visitor
{
private:
    /* data */
    Scope scope;
    std::unique_ptr<LLVMContext> TheContext;
    std::unique_ptr<IRBuilder<>> Builder;
    std::unique_ptr<Module> TheModule;
    Function* TheFunction;
    
    Type* curType;//当前解析的变量定义的类型
    AllocaInst* recentAllocaInst;
    Value* recentVal;
    bool isLVal;
    bool isNewFunc;
    BasicBlock* retBB;
    AllocaInst* retAlloca;
public:

    GenIR(/* args */);
    ~GenIR();
    void visit(CompUnitAST& ast) override;
    void visit(DeclDefAST& ast) override;
    void visit(DeclAST& ast) override;
    void visit(DefAST& ast) override;
    void visit(InitValAST& ast) override ;
    void visit(FuncDefAST& ast) override;
    void visit(FuncFParamAST& ast) override {};
    void visit(BlockAST& ast) override;
    void visit(BlockItemAST& ast) override;
    void visit(StmtAST& ast) override ;
    void visit(ReturnStmtAST& ast) override ;
    void visit(SelectStmtAST& ast) override ;
    void visit(IterationStmtAST& ast) override {};
    void visit(AddExpAST& ast) override;
    void visit(LValAST& ast) override ;
    void visit(MulExpAST& ast) override;
    void visit(UnaryExpAST& ast) override;
    void visit(PrimaryExpAST& ast) override;
    void visit(CallAST& ast) override {};
    void visit(NumberAST& ast) override;
    void visit(RelExpAST& ast) override ;
    void visit(EqExpAST& ast) override ;
    void visit(LAndExpAST& ast) override ;
    void visit(LOrExpAST& ast) override ;

    void printIR();

    AllocaInst* CreateEntryBlockAlloca(Function* TheFunction, StringRef VarName,Type* Ty) {
        IRBuilder<> TmpB(&TheFunction->getEntryBlock(),
            TheFunction->getEntryBlock().begin());
        return TmpB.CreateAlloca(Ty, nullptr, VarName);
    }

    Module* getModule(){
        return TheModule.get();
    }

    Type* getLLVMType(TYPE TyENUM);
};




