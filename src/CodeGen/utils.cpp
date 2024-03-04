#include "codegen.h"


void GenIR::printIR(){
    TheModule->print(errs(),nullptr);
}