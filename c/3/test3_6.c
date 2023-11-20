#include<stdio.h>

int main(void)
{
    float WATER_MOLECULAR_MASS = 3.0E-23f;
    int QUART_OF_WATER = 950;
    int warterQuart;
    float numberOfWaterMolecules;

    printf("Please enter the quart of water: ");
    scanf("%d",&warterQuart);
    numberOfWaterMolecules = warterQuart * QUART_OF_WATER / WATER_MOLECULAR_MASS;
    printf("The number of water molecules in %d quart of water is: %e",warterQuart,numberOfWaterMolecules);
    return 0;
}