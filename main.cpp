#include <iostream>

extern int yyparse();

int main(int, char**){
    std::cout << "Hello, from DragonCC!\n";
    yyparse();
}
