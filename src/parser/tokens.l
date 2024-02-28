/*TODO:?*/
%option noyywrap 
%option yylineno

%{
    #include<string>
    #include "ast.h"
    #include "parser.hpp"
    void yyerror(char *);
    using namespace std;
%}

ID [a-z_A-Z][a-z_A-Z0-9]*
DEC_INT_LIT ([1-9][0-9]*)
OCT_INT_LIT (0[0-7]*)
HEX_INT_LIT ((0x|0X)[0-9a-fA-F]+)


FLOAT_SUFFIX [fFlL]

DEC_EXP ([Ee][-+]?[0-9]+)
DEC_FLOAT_LIT_HAVE_POINT_HAVE_RIGHT ([0-9]*\.[0-9]+{DEC_EXP}?{FLOAT_SUFFIX}?)
DEC_FLOAT_LIT_HAVE_POINT_NO_RIGHT ([0-9]+\.{DEC_EXP}?{FLOAT_SUFFIX}?)
DEC_FLOAT_LIT_NO_POINT ([0-9]+{DEC_EXP}{FLOAT_SUFFIX}?)
DEC_FLOAT_LIT ({DEC_FLOAT_LIT_HAVE_POINT_HAVE_RIGHT}|{DEC_FLOAT_LIT_HAVE_POINT_NO_RIGHT}|{DEC_FLOAT_LIT_NO_POINT})

/*暂时不考虑非十进制浮点数*/
HEX_EXP ([Pp][-+]?[0-9]+)
HEX_FLOAT_LIT_HAVE_POINT_HAVE_RIGHT ((0[xX])[a-fA-F0-9]*\.[a-fA-F0-9]+{HEX_EXP}{FLOAT_SUFFIX}?)
HEX_FLOAT_LIT_HAVE_POINT_NO_RIGHT ((0[xX])[a-fA-F0-9]+\.{HEX_EXP}{FLOAT_SUFFIX}?)
HEX_FLOAT_LIT_NO_POINT ((0[xX])[a-fA-F0-9]+{HEX_EXP}{FLOAT_SUFFIX}?)
HEX_FLOAT_LIT ({HEX_FLOAT_LIT_HAVE_POINT_HAVE_RIGHT}|{HEX_FLOAT_LIT_HAVE_POINT_NO_RIGHT}|{HEX_FLOAT_LIT_NO_POINT})

FLOAT_LIT ({DEC_FLOAT_LIT}|{HEX_FLOAT_LIT})

SingleLineComment "//".*
MultilineComment "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"

%%
{DEC_INT_LIT}       {yylval.int_val = strtol(yytext, nullptr, 10); return INT;}
{OCT_INT_LIT}       {yylval.int_val = strtol(yytext, nullptr, 8); return INT;}
{HEX_INT_LIT}       {yylval.int_val = strtol(yytext, nullptr, 16); return INT;}

{DEC_FLOAT_LIT}     {yylval.float_val = strtof(yytext, nullptr); return FLOAT;}


"int"               {return INTTYPE;}
"float"             {return FLOATTYPE;}
"void"              {return VOID;}
"const"             {return CONST;}
"return"            {return RETURN;}
"if"                {return IF;}
"else"              {return ELSE;}
"while"             {return WHILE;}
"break"             {return BREAK;}
"continue"          {return CONTINUE;}

{ID}                {yylval.id_name = new string(yytext); return ID;}
">="                {return GTE;}
"<="                {return LTE;}
">"                 {return GT;}
"<"                 {return LT;}
"=="                {return EQ;}
"!="                {return NEQ;}

"("                 {return LP;}
")"                 {return RP;}
"["                 {return LB;}
"]"                 {return RB;}
"{"                 {return LC;}
"}"                 {return RC;}
","                 {return COMMA;}
";"                 {return SEMICOLON;}

"!"                 {return NOT;}
"="                 {return ASSIGN;}
"-"                 {return MINUS;}
"+"                 {return ADD;}
"*"                 {return MUL;}
"/"                 {return DIV;}
"%"                 {return MOD;}
"&&"                {return AND;}
"||"                {return OR;}
{SingleLineComment} 
{MultilineComment} 

[ \r\t]             {/* Ignore useless whitespaces */}
.                   {printf("Error type A :Mysterious character \"%s\"\n\t at Line %d\n", yytext, yylineno);}
%%