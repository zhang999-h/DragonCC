#include "codegen.h"
GenIR::GenIR(/* args */)
{
}

GenIR::~GenIR()
{
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

    }
    //recentVal = CONST_INT(ast.intval);

}