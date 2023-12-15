/*
 * 1.3.4 编写一个Stack的用例Parentheses，从标准输入中读取一个文本流并使用栈判定其中的括号是否配对完整。例如，对于[()]{}{[()()]()}程序应该打印true，对于[(])则打印false
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "..\..\lib\stack.h"
#define CLEN 2056

char * s_gets(char *st, int n);
int isParentheses(char *st);

int main(void)
{
    char line[CLEN];
    while(s_gets(line,CLEN) != NULL && line[0] != '\0')
        printf("%s %s parentheses\n",line, isParentheses(line) ? "is" : "not");
    return 0;
}

char * s_gets(char *st, int n)
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

int isParentheses(char *st)
{
    Stack cs;
    InitializeStack(&cs);

    char * ps;
    char popitem;
    ps = st;
    while(*ps != '\0')
    {
        if(*ps == '(' || *ps == '[' || *ps == '{')
            Push(*ps,&cs);
        else if(*ps == ')' && Pop(&popitem, &cs) && popitem != '(')
            return 0;
        else if(*ps == ']' && Pop(&popitem, &cs) && popitem != '[')
            return 0;
        else if(*ps == '}' && Pop(&popitem, &cs) && popitem != '{')
            return 0;
        ps++;
    }
    return EmptyStack(&cs);
}
