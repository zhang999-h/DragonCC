int main(){
     int x,y;
     x=8;
     y=x;
    // return x;
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