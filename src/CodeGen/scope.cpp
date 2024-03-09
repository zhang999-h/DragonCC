#include "scope.h"

void Scope::Enter(){
    Vars.push_back(std::map<std::string,llvm::AllocaInst*>());
}
void Scope::Leave(){
    Vars.pop_back();
};
void Scope::AddNewVar(std::string id, llvm::AllocaInst* alloca){
    int size=Vars.size();
    if(Vars[size-1].find(id)!=Vars[size-1].end()){
        printf("error!!!\n");
        exit(-1);
    }
    Vars[size-1][id]=alloca;
};
llvm::AllocaInst* Scope::FindVar(std::string id){
    int size=Vars.size();
    for(int i=size-1;i>0;i--){
        auto tmp=Vars[i].find(id);
        if(tmp!=Vars[i].end()){
            return tmp->second;
        }
    }
};