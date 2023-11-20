/*
4．使用嵌套循环，按下面的格式打印字母：
A
BC
DEF
GHIJ
KLMNO
PQRSTU
如果你的系统不使用以数字顺序编码的代码，请参照练习3的方案解决。
*/

#include<stdio.h>
#define SIZE 6

int main(void)
{   
    char ch = 'A';
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j <= i; j++,ch++)
            printf("%c",ch);    
        printf("\n");   
    }
    
    return 0;
}