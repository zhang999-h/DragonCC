//const int y=10;
int main(){
    int x=9;
    int a[10][5][5];
     a[5][1][1]=55;
     if(x>0)x=1;
     else x=-1;
     //return a[5][1][1];
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