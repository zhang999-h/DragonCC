#include <vector>
#include <map>
#include "llvm/IR/Instructions.h"

class Scope{

    private:
        std::vector<map<std::string,llvm::AllocaInst*>> Vars;
    public:
        void Enter();
        void Leave();
        void AddNewVar(std::string id,llvm::AllocaInst* alloca);
        llvm::AllocaInst* FindVar(std::string id);

};