/*
 * 11．编写并测试Fibonacci()函数，该函数用循环代替递归计算斐波那契数
 */
#include<stdio.h>

int Fibonacci(int n);

int main(void)
{
    int n;
    while(scanf("%d",&n))
        printf("%d the fibonacci is %d.\n",n,Fibonacci(n));
    return 0;
}

int Fibonacci(int n)
{
    int result[500];
    result[0] = 1;
    result[1] = 1;
    if(n > 2)
        for(int i = 2; i < n; i++)
            result[i] = result[i -1] + result[i - 2];
    return result[n - 1];
}
