/*
6．编写一个程序打印一个表格，每一行打印一个整数、该数的平方、该数的立方。
要求用户输入表格的上下限。使用一个for循环。
*/
#include<stdio.h>

int main(void)
{
    int min,max;
    scanf("%d%d",&min,&max);
    printf("integer square    cube\n");
    for (size_t i = min; i <= max; i++)
    {
        printf("%-8d%-10ld%ld\n",i,((long)i)*i,((long)i)*i*i);
    }

    return 0;
}