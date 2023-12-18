/*
 * 1.3.9 编写一段程序，从标准输入得到一个缺少左括号的表达式并打印出补全括号之后的中序表达式
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "..\..\lib\stack.h"
#include "..\..\lib\LinkedString.h"
#define CLEN 2056

char * s_gets(char * st, int n);
void putch(char ch);

int main(void)
{
    char st[CLEN];
    char *pc;
    Stack nums;
    Stack ops;
    while(s_gets(st, CLEN) != NULL && st[0] != '\0')
    {
        InitializeStack(&nums);
        InitializeStack(&ops);
        pc = st;
        String num;
        initString(&num);
        String op;
        initString(&op);
        while(*pc != '\0')
        {
            if(isspace(*pc))
                ;
            else if(isdigit(*pc))
                appendChar(&num,*pc);
            else if(*pc == '+' || *pc == '-' || *pc == '/' || *pc == '*')
            {
                if(!stringIsEmpty(&num))
                {
                    Push(num,&nums);
                    initString(&num);
                } 
                appendChar(&op,*pc);
                Push(op,&ops);
                initString(&op);
            }else if (*pc == ')')
            {
                if(!stringIsEmpty(&num))
                {
                    Push(num,&nums);
                    initString(&num);
                }
                String a;
                initString(&a);
                String b;
                initString(&b);
                Pop(&b,&nums);
                Pop(&a,&nums);
                addFirst(&a,'(');
                appendChar(&b,')');
                Pop(&op,&ops);
                append(&a,&op);
                append(&a,&b);
                Push(a,&nums);
                initString(&op);
            }else if (*pc == '}')
            {
                if(!stringIsEmpty(&num))
                {
                    Push(num,&nums);
                    initString(&num);
                }
                String a;
                initString(&a);
                String b;
                initString(&b);
                Pop(&b,&nums);
                Pop(&a,&nums);
                addFirst(&a,'{');
                appendChar(&b,'}');
                Pop(&op,&ops);
                append(&a,&op);
                initString(&op);
                append(&a,&b);
                Push(a,&nums);
            }else if (*pc == ']')
            {
                if(!stringIsEmpty(&num))
                {
                    Push(num,&nums);
                    initString(&num);
                }
                String a;
                initString(&a);
                String b;
                initString(&b);
                Pop(&b,&nums);
                Pop(&a,&nums);
                addFirst(&a,'[');
                appendChar(&b,']');
                Pop(&op,&ops);
                append(&a,&op);
                initString(&op);
                append(&a,&b);
                Push(a,&nums);
            }
            pc++;
        }
        
        peek(&num,&nums);
        stringTraverse(&num,putch);
        putchar('\n');
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

void putch(char ch)
{
    putchar(ch);
}
