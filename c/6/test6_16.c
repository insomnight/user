/*
16．Daphne以10%的单利息投资了100美元（也就是说，
每年投资获利相当于原始投资的10%）。Deirdre以5%的复合利息投资了100美元
（也就是说，利息是当前余额的5%，包含之前的利息）。
编写一个程序，计算需要多少年Deirdre的投资额才会超过Daphne，
并显示那时两人的投资额。
*/
#include<stdio.h>
#include<math.h>

int main(void)
{
    double dap_money = 100.0;
    double dei_money = 100.0;
    double dap_rate = 0.1;
    double dei_rate = 0.05;
    int i = 0;
    do
    {
        dap_money += 100.0 * dap_rate;
        dei_money *= 1 + dei_rate;
        i++;
        printf("%d: dap=%0.3f,dei=%0.3f\n",i,dap_money,dei_money);
    } while (dap_money > dei_money);
    
    return 0;
}