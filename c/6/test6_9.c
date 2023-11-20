/*
9．修改练习8，使用一个函数返回计算的结果。
*/

#include<stdio.h>

double fun(double x,double y);
int main(void)
{
    double x,y;
    while(scanf("%lf%lf",&x,&y)==2){
        printf("= %0.6f\n",fun(x,y));
    }
    return 0;
}

double fun(double x,double y)
{
    return (x-y)/(x * y);
}