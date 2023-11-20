/*
3．编写一个程序，读取整数直到用户输入0。输入结束后，程序应报告用户输入的偶数
（不包括0）个数、这些偶数的平均值、输入的奇数个数及其奇数的平均值。
*/
#include<stdio.h>
#define STOP 0

int main(void)
{
    int odd_nums = 0; 
    double odd_sum = 0.0;
    int even_nums = 0;
    double even_sum = 0.0;
    int num;
    while(scanf("%d",&num)){
        if(num == 0)
            break;
        if(num % 2 != 0)
        {
            odd_nums++;
            odd_sum += num;
        }else{
            even_nums++;
            even_sum += num;
        }
    }
    printf("odd nums = %d ,odd average = %0.3f ,even nums = %d ,even average = %0.3f.\n",odd_nums,odd_sum/odd_nums,even_nums,even_sum/even_nums);

    return 0;
}
