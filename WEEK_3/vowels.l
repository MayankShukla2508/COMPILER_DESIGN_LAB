%{
	int vow_count=0;
%}

%%
[aeiouAEIOU] {printf("%c ", yytext[0]); vow_count++;}
[a-zA-Z] {; /* Do nothing */}
%%
int yywrap(){}
int main()
{
	printf("Enter the string of vowels and consonants:");
	yylex();
	printf("\n");
	printf("Number of vowels are: %d\n", vow_count);
	return 0;
}