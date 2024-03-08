#pragma once

#include <vector>
#include <map>
#include "llvm/IR/Instructions.h"
#include <string>
class Scope{

    private:
        std::vector<std::map<std::string,llvm::AllocaInst*>> Vars;
    public:
        void Enter();
        void Leave();
        void AddNewVar(std::string id,llvm::AllocaInst* alloca);
        llvm::AllocaInst* FindVar(std::string id);

};