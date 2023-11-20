/*
 * 6．编写一个名为is_within()的函数，接受一个字符和一个指向字符串的指针作为两个函数形参。如果指定字符在字符串中，该函数返回一个非零值（即为真）。否则，返回0（即为假）。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */
#include<stdio.h>

int is_within(char c,const char * s);

int main(void)
{
    char s[100];
    char ch;
    while(scanf("%s %c",s,&ch) == 2)
    {
        printf("The %c is %s in %d.\n",ch,s,is_within(ch,s));
    }
    return 0;
}

int is_within(char c,const char * s)
{
    int i = 0;
    char *p = s;
    while(*s)
    {
        if( *s == c )
        {
            i = s - p + 1;
            break;
        }
        s++;
    }
    return i;
}
