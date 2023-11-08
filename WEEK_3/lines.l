%{
	int line_count=0;
%}

%%
\n {line_count++;}
. {}
%%
int yywrap(){}
int main()
{
	printf("Enter the text:");
	yylex();
	printf("Number of lines: %d\n", line_count);
	return 0;
}