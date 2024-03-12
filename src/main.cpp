#include <iostream>
#include <memory>
#include <string>
#include "ast.h"
#include "define.h"
#include "parser.hpp"
#include "tokens.hpp"
#include "codegen.h"
#include "object.h"

using namespace std;
extern unique_ptr<CompUnitAST> root;


int main(int argc, char** argv) {
    std::cout << "Hello, from DragonCC!\n\n";
    char* filename = nullptr;
    filename = argv[1];
    //printf("open : %s\n", filename);
    cout << argc;
    yyin = fopen(filename, "r");
    if (yyin == nullptr) {
        std::cout << "yyin open" << filename << "failed" << std::endl;
        return -1;
    }
    yyparse();
    GenIR genir;
    root->accept(genir);
    errs()<<"print LLVM IR:\n";
    genir.printIR();

    Backend(genir);

}
