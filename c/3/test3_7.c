#include<stdio.h>

int main(void)
{
    float INCHES_ARE_CONVERTED_TO_CENTIMETERS = 2.54;
    float heightOfInches;
    float heightOfCm;
    printf("Please enter your height in inches: ");
    scanf("%f",&heightOfInches);
    heightOfCm = heightOfInches *INCHES_ARE_CONVERTED_TO_CENTIMETERS;
    printf("Your %f-inch height is %f cm \n",heightOfInches,heightOfCm);
    return 0;
}