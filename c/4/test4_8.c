#include<stdio.h>

#define GALLONS_TO_LITERS 3.785
#define MILE_TO_KM 1.609

int main(void)
{
    float mileage;
    float amount;
    printf("Enter the mileage for your trip\n");
    scanf("%f",&mileage);
    printf("Enter the amount of gas consumed for the trip\n");
    scanf("%f",&amount);
    printf("%0.1f/n",mileage/amount);
    printf("%0.1f/n",amount*GALLONS_TO_LITERS / mileage * MILE_TO_KM * 100);
    return 0;
}