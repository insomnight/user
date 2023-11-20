#include<stdio.h>

int main(void)
{
    int age;
    long ageSeconds;


    printf("Please enter your age: ");
    scanf("%d",&age);
    ageSeconds = age*365*24*60*60;
    printf("You've lived %ld seconds\n",ageSeconds);

    return 0;
}