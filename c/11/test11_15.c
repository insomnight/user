/*
 * 15．使用字符分类函数实现atoi()函数。如果输入的字符串不是纯数字，该函数返回0。
 */
#include<stdio.h>
#include<ctype.h>

int myatoi(const char * str);

int main(void)
{
    char str[100];
    int result;

    while(scanf("%s",str) == 1 )
    {
        result = myatoi(str);
        printf("%d\n",result);
    }

    return 0;
}


int myatoi(const char * str)
{
    int result = 0;

    while(str != NULL && *str){
        if(!isdigit(*str))
            return 0;
       result = result * 10 + (*str - '0'); 
       str++; 
    }

    return result;
}
