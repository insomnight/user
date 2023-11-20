#include<stdio.h>

int main(void)
{
    int age;
    printf("Input a your age: \n");
    scanf("%d", &age);
    printf("Your age is %d.You have lived %d days!",age, 365 * age);
    return 0;
}