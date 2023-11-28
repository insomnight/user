/*
 * 1.1.14 编写一个静态方法lg()，接受一个整型参数N，返回不大于log2N的最大整数。不要使用Math库
 */
#include <stdio.h>
#include <stdlib.h>

int lg(double n);

int main(void)
{
    int result;
    double n;
    while(scanf("%lf",&n) == 1)
    {
        result = lg(n);
        printf("long2 %lf the biggest integer is %d\n",n,result);
    }
    return 0;
}

int lg(double n)
{
    int result = 0;
    if(n <= 0)
    {
        fprintf(stderr,"%d < 0,Not in the defined field of log\n");
        exit(EXIT_FAILURE);
    }

    if(n >= 1)
        for(int i = 2; i <= n; i *= 2)
            result++;
    else
    {
        result = -1;
        for(double i = 1.0 / 2.0; i > n; i /= 2.0)
            result--;
    }
    return result;
}


