/*
 * 5．设计并测试一个函数，搜索第1个函数形参指定的字符串，在其中查找第2个函数形参指定的字符首次出现的位置。如果成功，该函数返指向该字符的指针，如果在字符串中未找到指定字符，则返回空指针（该函数的功能与strchr()函数相同）。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */
#include<stdio.h>

const char * str_find_char(const char * str, int c);

int main(void)
{
    char ch;
    while(scanf("%c",&ch))
    {
        if(ch =='\n')
            continue;
        printf("The %c in asdfghjkl is %d.\n",ch,str_find_char("asdfghjkl",ch)-"asdfghjkl");
    }
    return 0;
}

const char * str_find_char(const char * str, int c)
{
    while(*str)
    {
        if(*str == c)
            return str;
        str++;
    }
    return NULL;
}

