/*
   9．编写一个程序，只接受正整数输入，后显示所有小于或等于该数的素数。
*/
#include<stdio.h>
#include<stdbool.h>

int main(void)
{
    int num;
    int div;
    bool isPrime;
    while(scanf("%d",&num) && num > 0 )
    {
        for(div=2,isPrime=true;div * div <= num;div++)
            if(num % div == 0)
            {
                isPrime = false;
                break;
            }
        if(isPrime)
            printf("%d is prime.\n",num);
        else
            printf("%d not is prime.\n",num);
    }
    return 0;
}
