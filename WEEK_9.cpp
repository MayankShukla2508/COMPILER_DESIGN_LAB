#include <stdio.h>
#include <stdlib.h>
void pop(), push(char), display();
char stack[100] = "\0";
char inputbuffer[100];
int top = -1;
char *ip;
int main()
{
  printf("E->E+E\n");
  printf("E->E*E\n");
  printf("E->(E)\n");
  printf("E->d\n");
  printf(" enter the input string followed by $ \n");
  scanf("%s", inputbuffer);
  ip = inputbuffer;
  push('$');
  printf("STACK\t  BUFFER \t  ACTION\n");
  printf("-----\t ------- \t ------\n");
  display();
  do
  {
    if ((stack[top] == 'E' && stack[top - 1] == '$') && (*(ip) == '$'))
      break;
    if (stack[top] == '$')
    {
      push(*ip);
      ip++;
      printf("Shift");
    }
    else if (stack[top] == 'd')
    {
      display();
      pop();
      push('E');
      printf("Reduce E->d\n");
    }
    else if (stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E' && *ip != '*')
    {
      display();
      pop();
      pop();
      pop();
      push('E');
      printf("Reduce E->E+E");
    }
    else if (stack[top] == 'E' && stack[top - 1] == '*' && stack[top - 2] == 'E')
    {
      display();
      pop();
      pop();
      pop();
      push('E');
      printf("Reduce E->E*E");
    }
    else if (stack[top] == ')' && stack[top - 1] == 'E' && stack[top - 2] == '(')
    {
      display();
      pop();
      pop();
      pop();
      push('E');
      printf("Reduce E->(E)");
    }
    else
    {
      display();
      push(*ip);
      if (*ip == '\0' || *ip == '\n')
      {
        printf("Error\n");
        getchar();
        return 0;
      }
      ip++;

      printf("shift");
    }
  } while (1);
  display();
  printf(" Accept\n\n\n");
}
void push(char c)
{
  top++;
  stack[top] = c;
}
void pop()
{
  stack[top] = '\0';
  top--;
}
void display()
{
  printf("\n%s\t%s\t", stack, ip);
}
