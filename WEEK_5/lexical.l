%{
#include <stdio.h>
%}

%%
"/*"([^*]|"*"[^/])*"*/" ;  // Ignore comments

"int"               { printf("INT\n"); }
"if"                { printf("IF\n"); }
"then"              { printf("THEN\n"); }
"else"              { printf("ELSE\n"); }
"endif"             { printf("ENDIF\n"); }
"while"             { printf("WHILE\n"); }
"do"                { printf("DO\n"); }
"enddo"             { printf("ENDDO\n"); }
"print"             { printf("PRINT\n"); }

[a-zA-Z][a-zA-Z0-9]* { printf("IDENTIFIER\n"); }
[0-9]+              { printf("CONSTANT\n"); }

";"                 { printf("SEMICOLON\n"); }
"="                 { printf("ASSIGNMENT\n"); }
"["                 { printf("LEFT_BRACKET\n"); }
"]"                 { printf("RIGHT_BRACKET\n"); }
"("                 { printf("LEFT_PAREN\n"); }
")"                 { printf("RIGHT_PAREN\n"); }
"+"                 { printf("ADD_OP\n"); }
"-"                 { printf("SUB_OP\n"); }
"*"                 { printf("MUL_OP\n"); }
"/"                 { printf("DIV_OP\n"); }
"<="                { printf("RELOP\n"); }
"<"                 { printf("RELOP\n"); }
"=="                { printf("RELOP\n"); }
">="                { printf("RELOP\n"); }
">"                 { printf("RELOP\n"); }
"!="                { printf("RELOP\n"); }
","                 { printf("COMMA\n"); }
"{"                 { printf("BLOCK_START\n"); }
"}"                 { printf("BLOCK_END\n"); }

[ \t\n]             ;  // Ignore whitespace, tabs, and newlines

.                   { printf("Invalid character: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
