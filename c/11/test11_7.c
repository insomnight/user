/*
 * 7．strncpy(s1, s2, n)函数把s2中的n个字符拷贝至s1中，截断s2，或者有必要的话在末尾添加空字符。如果s2的长度是n或多于n，目标字符串不能以空字符结尾。该函数返回s1。自己编写一个这样的函数，名为mystrncpy()。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */
#include<stdio.h>
#include<string.h>

char * mystrncpy(char * s1, char * s2, int n);

int main(void)
{
    char s1[15],s2[10];
    while(scanf("%s%s",s1,s2) == 2)
    {
        printf("%s append %s is",s1,s2);
        mystrncpy(s1,s2,15 - strlen(s1) - 1);
        printf(" %s\n", s1);
    }
    return 0;
}

char * mystrncpy(char * s1, char * s2, int n)
{
    //先找到s1结束位置即'\0'位置
    while(*s1 != '\0')
        s1++;
    while(*s2 != '\0' && n > 0)
    {
        *s1 = *s2;
        s2++;
        s1++;
        n--;
    }
    *s1 = '\0';
    return s1;
}
