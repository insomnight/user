#include<stdio.h>

int main(void)
{
    char lastname[40];
    char firstname[40];

    printf("Please enter your name:");
    scanf("%s %s",lastname,firstname);
    printf("Your name is %s %s",lastname,firstname);
    return 0;
}