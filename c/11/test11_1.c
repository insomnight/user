/*
 * 1．设计并测试一个函数，从输入中获取n个字符（包括空白、制表符、换行符），把结果存储在一个数组里，它的地址被传递作为一个参数。
 */
#include<stdio.h>

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
        i++;
        if(i >=n)
            break;
    }
    str[i] = '\0';

    return str;
}

