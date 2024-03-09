int main(){
    int x=1;
    float f=1;
    if(x>1){
        x=1;
    }
    else{
        x=2;
    }
    //return x;
    //8;
}
/*************************

 CompUnitAST
    DeclDefAST
        FuncDefAST
            funcFParamList
            BlockAST
                BlockItemAST
                    DeclAST
                        DefAST
                    StmtAST
                        LValAST
                        AddExpAST
                    StmtAST
                        ReturnStmtAST
                            AddExpAST
                                MulExp

 *************************/