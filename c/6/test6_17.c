/*
17．Chuckie Lucky赢得了100万美元（税后），他把奖金存入年利率8%的账户。
在每年的最后一天，Chuckie取出10万美元。编写一个程序，
计算多少年后Chuckie会取完账户的钱？
*/
#include<stdio.h>

int main(void)
{
    double money =1000000.0;
    int i = 0;
    const double rate = 0.08;
    while (money >0)
    {
        money *= 1 + 0.08;
        money -= 100000.0;
        i++;
        printf("%d:%0.3f\n",i,money);
    }
    return 0;
}