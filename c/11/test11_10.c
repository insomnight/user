/*
 * 10．编写一个函数接受一个字符串作为参数，并删除字符串中的空格。在一个程序中测试该函数，使用循环读取输入行，直到用户输入一行空行。该程序应该应用该函数读取每个输入的字符串，并显示处理后的结果。
 */
#include<stdio.h>
#include<ctype.h>

void remove_spaces(char * s);

int main(void)
{
    char s[100];
    while(gets(s) && *s)
    {
        remove_spaces(s);
        puts(s);
    }
    return 0;
}

void remove_spaces(char * s)
{
    char * news = s;
    while(*s)
    {
        if(!isspace(*s))
        {
            *news = *s;
            news++;
        }
        s++;
    }
    *news = '\0';
}
