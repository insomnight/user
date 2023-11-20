#include<stdio.h>

int main(void)
{
    int PINT_TO_CUPS = 2;
    int CUP_TO_OUNCES = 8;
    int OUNCE_TO_TABLESPOONS = 2;
    int TABLESPOON_TO_TEASPOONS = 3;

    float cups_num;
    float pints_num;
    float ounces_num;
    float tablespoons_num;
    float teaspoons_num;

    printf("Please enter the number of cups: ");
    scanf("%f", &cups_num);
    pints_num = cups_num /PINT_TO_CUPS;
    ounces_num = cups_num * CUP_TO_OUNCES;
    tablespoons_num = ounces_num * OUNCE_TO_TABLESPOONS;
    teaspoons_num = tablespoons_num * TABLESPOON_TO_TEASPOONS;

    printf("cups is %f\n",cups_num);
    printf("pints is %f\n",pints_num);
    printf("ounces is %f\n",ounces_num);
    printf("tablespoons is %f\n",tablespoons_num);
    printf("teaspoons is %f\n",teaspoons_num);
    return 0;
}