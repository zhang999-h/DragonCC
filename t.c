int main(){
     int x,y;
     x=8+9;
     y=x%9;
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