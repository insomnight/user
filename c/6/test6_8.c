/*
8．编写一个程序，要求用户输入两个浮点数，并打印两数之差除以两数乘积的结果。
在用户输入非数字之前，程序应循环处理用户输入的每对值。
*/
#include<stdio.h>

int main(void)
{
    double x,y;
    while(scanf("%lf%lf",&x,&y)==2){
        printf("= %0.6f\n",(x-y)/(x * y));
    }
    return 0;
}