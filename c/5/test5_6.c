/*
6．修改编程练习5的程序，使其能计算整数的
平方和（可以认为第1天赚$1、第2天赚$4、第3天赚$9，以此类推，这看起来很不错）。
C没有平方函数，但是可以用n * n来表示n的平方。
*/
#include <stdio.h>
int main(void)                
{
    int count, sum,n;           
    
    count = 0;               
    sum = 0;  
    scanf("%d",&n);            
    while (count++ < n)       
        sum = sum + count * count;
    printf("sum = %d\n", sum);  

    return 0;               
}