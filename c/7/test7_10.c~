/*
   10.1988年的美国联邦税收计划是近代最简单的税收方案。它分为4个类别，每个类别有两个等级。下面是该税收计划的摘要（美元数为应征税的收入）：
   类别                     税金
   单身                     17850美元按15%计,超出部分按28%计
   户主                     23900美元按15%计,超出部分按28%计
   已婚,共有                29750美元按15%计,超出部分按28%计
   已婚,离异                14875美元按15%计,超出部分按28%计
例如，一位工资为20000美元的单身纳税人，应缴纳税费0.15×17850+0.28×（20000−17850）美元。编写一个程序，让用户指定缴纳税金的种类和应纳税收入，然后计算税金。程序应通过循环让用户可以多次输入。
*/

#include<stdio.h>
#define TAX_UNMARRIED_RANGE 17850
#define TAX_HOUSEHOLD_RANGE 23900
#define TAX_MARRIED_RANGE 29750
#define TAX_DIVORCED_RANGE 14875
#define BASE_TAX_RATE 0.15
#define OVER_TAX_RATE 0.28
int main(void)
{
    double range,tax,income;
    int kind;
    while(scanf("%lf%d",&income,&kind) == 2){
        switch(kind)
        {
            case 0: range = TAX_UNMARRIED_RANGE;
                    break;
            case 1: range = TAX_HOUSEHOLD_RANGE;
                    break;
            case 2: range = TAX_MARRIED_RANGE;
                    break;
            case 3: range = TAX_DIVORCED_RANGE;
                    break;
            defalut: 
                    printf("The input type is not in the range of 0-3\n");
                    continue;
        }
        if( income <= range)
            tax = income * BASE_TAX_RATE;
        else
            tax = range * BASE_TAX_RATE + ( income - range ) * OVER_TAX_RATE;
        printf("tax = %0.3f\n",tax);
    }
    return 0;
}
