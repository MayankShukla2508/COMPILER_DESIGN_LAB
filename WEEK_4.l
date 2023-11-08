%{
#include <stdio.h>
%}

%option noyywrap

%%
"/*"[\s\S]*?"*/"   ; // Ignore comments

"<"                 { printf("Less Than Operator: %s\n", yytext); }
">"                 { printf("Greater Than Operator: %s\n", yytext); }
"<="                { printf("Less Than or Equal Operator: %s\n", yytext); }
">="                { printf("Greater Than or Equal Operator: %s\n", yytext); }
"=="                { printf("Equal Operator: %s\n", yytext); }
"!="                { printf("Not Equal Operator: %s\n", yytext); }
.                   ; // Ignore all other characters

%%

int main() {
    yylex();
    return 0;
}
