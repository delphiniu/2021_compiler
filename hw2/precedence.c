#include <stdio.h>

int top = -1;
char stack[100];
char ptable[5] = {'|', '&', '>', '+', '*'};

void print_precedence(char c)
{
    if(top != -1)
    {
        int ci, i;
        for(int i = 4; i >= 0; i--)
            if(c == ptable[i])
            {
                ci = i;
                break;
            }
        for(i = 4; i >= ci; i--)
            if(top > -1 && stack[top] == ptable[i])
            {
                printf("%c\n", stack[top--]);
                i = 5;
            }
    }
    stack[++top] = c;
}

int main()
{
    char exp[100];
    int i = 0;
    scanf("%s", exp);
    while(exp[i])
        print_precedence(exp[i++]);
    while(top > -1)
        printf("%c\n", stack[top--]);
}
