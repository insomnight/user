/*
 * 2．修改并编程练习1的函数，在n个字符后停止，或在读到第1个空白、制表符或换行符时停止，哪个先遇到哪个停止。不能只使用scanf()。 
 */
#include<stdio.h>
#include<ctype.h>

char * c_getsn(char * str, int n);

int main(void)
{
    char st[11];
    char * s = c_getsn( st, 10);
    puts(s);
    return 0;
}

char * c_getsn(char * str, int n)
{
    int i = 0;
    while( (str[i] = getchar())!=EOF)
    {
        if(isspace(str[i]))
            break;
        i++;
        if(i >=n)
            break;
    }
    str[i] = '\0';

    return str;
}

