/*
 * 1.1.20 编写一个递归的静态方法计算ln(N! )的值
 */
#include <stdio.h>
#include <math.h>

double lnN(int n);

int main(void)
{
    for(int i = 1; i < 100; i++)
        printf("%d %lf\n",i,lnN(i));
    return 0;
}

double lnN(int n)
{
    if(n == 1) return log((double) 1);
    return log((double)n) + lnN(n - 1);
}
