
%{
    #include<string>
    #include <stdio.h>
    #include <stdlib.h>
    using namespace std;
    extern int yylex(void);
    void yyerror(char *);
%}

%union{
    std::string* id_name;
    double float_val;
    int int_val;
}
// %token 定义终结符的语义值类型
%token <int_val> INTCONST           // 指定INTCONST字面量的语义值是type_int，有词法分析得到的数值
%token <float_val> FLOATCONST       // 指定FLOAT字面量的语义值是type_float，有词法分析得到的数值
%token <id_name> IDENT              // 指定ID
%token <float_val> FLOAT       // 指定FLOAT字面量的语义值是type_float，有词法分析得到的数值
%token GTE LTE GT LT EQ NEQ    // 关系运算
%token INTTYPE FLOATTYPE VOID  // 数据类型
%token CONST RETURN IF ELSE WHILE BREAK CONTINUE
%token LP RP LB RB LC RC COMMA SEMICOLON
// 用bison对该文件编译时，带参数-d，生成的exp.tab.h中给这些单词进行编码，可在lex.l中包含parser.tab.h使用这些单词种类码
%token NOT ASSIGN MINUS ADD MUL DIV MOD AND OR

%type  <int_val> expression term single
%%

       line_list: line
                | line_list line
                ;
				
	       line : expression SEMICOLON  {printf(">>%d\n",$1);}

      expression: term 
                | expression ADD term   {$$=$1+$3;}
				| expression MINUS term   {$$=$1-$3;}
                ;

            term: single
				| term MUL single		{$$=$1*$3;}
				| term DIV single		{$$=$1/$3;}
				;
				
		  single: INTCONST
				;


%%

void yyerror(char* fmt) {
  //printf("%s:%d ", filename, yylloc.first_line);
  printf("%s\n", fmt);
}