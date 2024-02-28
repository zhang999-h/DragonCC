#include <iostream>
#include <memory>
#include "ast.h"
#include "define.h"
using namespace std;
extern unique_ptr<CompUnitAST> root;
extern int yyparse();

int main(int, char**) {
    
    std::cout << "Hello, from DragonCC!\n\n";
    yyparse();
}
