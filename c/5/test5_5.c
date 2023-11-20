/*
5．修改程序addemup.c（程序清单5.13），你可以认为addemup.c是计算20天里赚多少钱
的程序（假设第1天赚$1、第2天赚$2、第3天赚$3，以此类推）。修改程序，使其可以与
用户交互，根据用户输入的数进行计算（即，用读入的一个变量来代替20）。
*/
#include <stdio.h>
int main(void)                
{
    int count, sum,n;           
    
    count = 0;               
    sum = 0;  
    scanf("%d",&n);            
    while (count++ < n)       
        sum = sum + count;
    printf("sum = %d\n", sum);  

    return 0;               
}