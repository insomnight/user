/*
 * 9．编写一个函数，把字符串中的内容用其反序字符串代替。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */
#include<stdio.h>

void * reverse(char * s);

int main(void)
{
    char str[100];
    while(gets(str))
    {
        reverse(str);
        puts(str);
    }
    return 0;
}

void * reverse(char * s)
{
    char temp, * start;
    start = s;
    while(*s)
        s++;
    s--;
    while(s > start)
    {
        temp = *s;
        *s = *start;
        *start = temp;
        s--;
        start++;
    }
}
