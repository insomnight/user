/*
   11．ABC邮购杂货店出售的洋蓟售价为2.05美元/磅，甜菜售价为1.15美元/磅，胡萝卜售价为1.09美元/磅。在添加运费之前，100美元的订单有5%的打折优惠。少于或等于5磅的订单收取6.5美元的运费和包装费，5磅～20磅的订单收取14美元的运费和包装费，超过20磅的订单在14美元的基础上每续重1磅增加0.5美元。编写一个程序，在循环中用switch语句实现用户输入不同的字母时有不同的响应，即输入a的响应是让用户输入洋蓟的磅数，b是甜菜的磅数，c是胡萝卜的磅数，q是退出订购。程序要记录累计的重量。即，如果用户输入4磅的甜菜，然后输入5磅的甜菜，程序应报告9磅的甜菜。然后，该程序要计算货物总价、折扣（如果有的话）、运费和包装费。随后，程序应显示所有的购买信息：物品售价、订购的重量（单位：磅）、订购的蔬菜费用、订单的总费用、折扣（如果有的话）、运费和包装费，以及所有的费用总额。
*/

#include<stdio.h>
#define ARTICHOKE_UNIT_PRICE 2.05
#define SWEET_UNIT_PRICE 1.15
#define CARROT_UNIT_PRICE 1.09
#define DISCOUNT_THRESHOLD 100
#define DISCOUNT_PERCENT 0.05
#define SHIP_PACKAGE_LEVEL_ONE_THRESHOLD 5
#define SHIP_PACKAGE_LEVEL_ONE_COST 6.5
#define SHIP_PACKAGE_LEVEL_TWO_THRESHOLD 20
#define SHIP_PACKAGE_LEVEL_TWO_COST 14
#define SHIP_PACKAGE_LEVEL_OVER_UNIT_COST 0.5

int main(void)
{
    double artichoke_weight = 0.0;
    double sweet_weight = 0.0;
    double carrot_weight = 0.0;
    double total_weight = 0.0;
    double artichoke_price = 0.0;
    double sweet_price = 0.0;
    double carrot_price = 0.0;
    double order_price = 0.0;
    double discount = 0.0;
    double ship_package_costs = 0.0;
    double total = 0.0;
    char ch;
    double enter_weight;
    while(1)
    {
        printf("Please enter a, b, c to select the product (a = artichoke, b = sweet, c = carrot),enter q eixt!\n");
        fflush(stdin);
        if((ch=getchar())=='q')
        {
            artichoke_price = artichoke_weight * ARTICHOKE_UNIT_PRICE;
            sweet_price = sweet_weight * SWEET_UNIT_PRICE;
            carrot_price = carrot_weight * CARROT_UNIT_PRICE;
            order_price = artichoke_price + sweet_price + carrot_price;
            total_weight = artichoke_weight + sweet_weight + carrot_weight;
            if(order_price>DISCOUNT_THRESHOLD)
                discount = order_price * DISCOUNT_PERCENT;  
            if(total_weight<=0)
                ;
            else if(total_weight <= SHIP_PACKAGE_LEVEL_ONE_THRESHOLD)
                ship_package_costs = SHIP_PACKAGE_LEVEL_ONE_COST;
            else if(total_weight <= SHIP_PACKAGE_LEVEL_TWO_THRESHOLD)
                ship_package_costs = SHIP_PACKAGE_LEVEL_TWO_COST;
            else 
                ship_package_costs = SHIP_PACKAGE_LEVEL_TWO_COST + (total_weight - SHIP_PACKAGE_LEVEL_TWO_THRESHOLD) * SHIP_PACKAGE_LEVEL_OVER_UNIT_COST;

            total = order_price + ship_package_costs - discount ;
            printf("%19s|%17s|%17s|%17s\n"," ","goods unit price","weight","price");
            printf("%19s|%17.3f|%17.3f|%17.3f\n","artichoke",ARTICHOKE_UNIT_PRICE,artichoke_weight,artichoke_price);
            printf("%19s|%17.3f|%17.3f|%17.3f\n","sweet",SWEET_UNIT_PRICE,sweet_weight,sweet_price);
            printf("%19s|%17.3f|%17.3f|%17.3f\n","carrot",CARROT_UNIT_PRICE,carrot_weight,carrot_price);
            printf("%19s|%17s %17s %17.3f\n","order price","","",order_price);
            printf("%19s|%17s %17s %17.3f\n","discount","","",discount);
            printf("%19s|%17s %17s %17.3f\n","ship package costs","","",ship_package_costs);
            printf("%19s|%17s %17s %17.3f\n","total","","",total);
            break;
        }
        if(ch != 'a' && ch != 'b' && ch != 'c')
        {   
            printf("your enter no in the a,b,c range!\n");
            continue;
        }
        printf("Please enter how much weight you want to buy!\n");
        fflush(stdin);
        scanf("%lf",&enter_weight);
        switch(ch)
        {
            case 'a': artichoke_weight += enter_weight;
                      break;
            case 'b': sweet_weight += enter_weight;
                      break;
            case 'c': carrot_weight += enter_weight;
                      break;
            default: break;
        }

    }
    return 0;
}
