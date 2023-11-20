/*
 * 1．设计一个函数min(x, y)，返回两个double类型值的较小值。在一个简单的驱动程序中测试该函数。
 */
#include<stdio.h>

double min(double,double);

int main(void)
{
    double a;
    double b;
    while(scanf("%lf%lf",&a,&b) == 2)
        printf("%f,%f,min is %f.\n",a,b,min(a,b));
    return 0;
}

double min(double x,double y)
{
    return x < y ? x : y ;
}
