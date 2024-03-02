int main(){
    int x;
    x=8;
    return x;
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