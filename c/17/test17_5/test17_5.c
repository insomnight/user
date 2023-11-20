/*
 * 5．编写一个程序，提示用户输入一个字符串。然后该程序把该字符串的字符逐个压入一个栈（参见复习题5），然后从栈中弹出这些字符，并显示它们。结果显示为该字符串的逆序。
 */
#include <stdio.h>
#include <string.h>
#include "stack.h"

char * s_gets(char * st,int n);

int main(void)
{
    char line[MAXSTACK];
    Stack sta;
    char temp;
    InitializeStack(&sta);
    puts("Enter some thing in a line:");
    while(s_gets(line,MAXSTACK) != NULL && line[0] != '\0')
    {
        for(int i = 0 ; line[i] != '\0' && i < MAXSTACK ; i++)
            Push(line[i],&sta);
        if(!EmptyStack(&sta))
            while(Pop(&temp,&sta))
                putchar(temp);
        putchar('\n');
        puts("Enter some thing in a line:");
    }
    return 0;
}

char * s_gets(char * st,int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
