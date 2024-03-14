#include "codegen.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/raw_ostream.h"

void GenIR::printIR() {
    // 打开一个文件来写入 LLVM IR
    std::error_code EC;
    raw_fd_ostream IRFile("../output.ll", EC);
    TheModule->print(IRFile, nullptr);
}