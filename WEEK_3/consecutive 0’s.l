%{
%}

%%
[0]{3} {printf("%s\n", yytext);}
. {}
%%
int yywrap(){}
int main()
{
	printf("Enter the strings:");
	yylex();
	return 0;
}
