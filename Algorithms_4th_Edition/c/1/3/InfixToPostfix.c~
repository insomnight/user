/*
 * 1.3.10 编写一个过滤器InfixToPostfix，将算术表达式由中序表达式转为后序表达式。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CLEN 2056

char * s_gets(char * st, int n);

void trans(char * ex,char * str,int n);

int main(void)
{
    char st[CLEN];
    char ex[CLEN];
    while(s_gets(st, CLEN) != NULL && st[0] != '\0')
    {
        trans(ex,st,CLEN);
        printf("%s\n",ex);
    }
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

void trans(char * ex,char *str,int n)
{
    char stack[n];
    char *pc;
    pc = str;
    int top = 0, t = 0;
    while(*pc != '\0')
    {
        switch(*pc)
        {
            case '(':
                stack[top++] = *pc;
                break;
            case ')':
                while(stack[top - 1]!='(')
                {
                    ex[t] = stack[--top];
                    t++;
                }
                top--;
                break;
            case '+':
            case '-':
                while(top != 0 && stack[top - 1] != '(')
                {
                    ex[t] = stack[--top];
                    t++;
                }
                stack[top++] = *pc;
                break;
            case '*':
            case '/':
                while(stack[top - 1] == '*' || stack[top - 1] == '/')
                {
                    ex[t] = stack[--top];
                    t++;
                }
                stack[top++] = *pc;
                break;
            case ' ':
                break;
            default:
                while(*pc >= '0' && *pc <= '9')
                {
                    ex[t] = *pc;
                    t++;
                    pc++;
                }
                pc--;
                ex[t]=' ';
                t++;
        }
        pc++;
    }
    while(top!=0)
    {
        ex[t] = stack[--top];
        t++;
    }
    ex[t] ='\0';
}
