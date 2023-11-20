/*
2．使用嵌套循环，按下面的格式打印字符：
$
$$
$$$
$$$$
$$$$$
*/
#include<stdio.h>
#define SIZE 5
int main(void)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j <= i; j++)
            printf("$");
        printf("\n");
    }
    return 0;
}