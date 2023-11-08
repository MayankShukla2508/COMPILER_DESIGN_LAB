#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100

struct Symbol
{
    char name[MAX];
};

bool matchesRegularExpression(const char *input)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            return false; // Check if each character is a digit
        }
    }
    return true;
}

int isKeyword(char *string)
{
    char keywords[][10] =
        {
            "if", "else", "while", "for", "int", "float", "char", "struct", "return", "switch"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++)
    {
        if (strcmp(string, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    FILE *inputfile = fopen("input.txt", "r");
    if (inputfile == NULL)
    {
        printf("Error opening input file\n");
        return 1;
    }
    FILE *outputfile = fopen("output.txt", "w");
    if (outputfile == NULL)
    {
        printf("Error opening output file\n");
        fclose(inputfile);
        return 1;
    }

    struct Symbol symboltable[MAX];
    int symbolcount = 0;
    char c;
    char string[MAX];
    int stringIndex = 0;

    while ((c = fgetc(inputfile)) != EOF)
    {
        if (isspace(c) || c == '(' || c == ')')
        {
            if (stringIndex > 0)
            {
                string[stringIndex] = '\0';

                if (isKeyword(string))
                {
                    fprintf(outputfile, "Keyword: %s\n", string);
                }
                else if (strcmp(string, "(") == 0 || strcmp(string, ")") == 0)
                {
                    fprintf(outputfile, "Parenthesis: %s\n", string);
                }
                else if (isalpha(string[0]))
                {
                    int validIdentifier = 1;
                    for (int i = 1; i < strlen(string); i++)
                    {
                        if (!isalnum(string[i]))
                        {
                            validIdentifier = 0;
                            break;
                        }
                    }
                    if (validIdentifier)
                    {
                        fprintf(outputfile, "Identifier: %s\n", string);
                        strcpy(symboltable[symbolcount].name, string);
                        symbolcount++;
                    }
                    else
                    {
                        fprintf(outputfile, "Invalid Identifier: %s\n", string);
                    }
                }
                else if (isdigit(string[0]))
                {
                    int validInteger = 1;
                    for (int i = 1; i < strlen(string); i++)
                    {
                        if (!isdigit(string[i]))
                        {
                            validInteger = 0;
                            break;
                        }
                    }
                    if (validInteger)
                    {
                        fprintf(outputfile, "Integer: %s\n", string);
                    }
                    else
                    {
                        fprintf(outputfile, "Not an Integer: %s\n", string);
                    }
                }
                else if (strcmp(string, "<") == 0 || strcmp(string, ">") == 0 || strcmp(string, "==") == 0 || strcmp(string, "<=") == 0 || strcmp(string, ">=") == 0 || strcmp(string, "!=") == 0)
                {
                    fprintf(outputfile, "Relational Operator: %s\n", string);
                }
                else if (matchesRegularExpression(string))
                {
                    fprintf(outputfile, "Regular Expression: %s\n", string);
                }
                else if (!matchesRegularExpression(string))
                {
                    fprintf(outputfile, "Not a Regular Expression: %s\n", string);
                }
                stringIndex = 0;
            }
        }
        else
        {
            string[stringIndex++] = c;
        }
    }

    fprintf(outputfile, "\nSymbol Table:\n");
    for (int i = 0; i < symbolcount; i++)
    {
        fprintf(outputfile, "%d: %s\n", i + 1, symboltable[i].name);
    }

    fclose(inputfile);
    fclose(outputfile);
    printf("Results updated to output.txt\n");
    return 0;
}
