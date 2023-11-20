#include<stdio.h>

int main(void)
{
    char name[40];
    float height;
    printf("Please enter your name:");
    scanf("%s",name);
    printf("Please enter your height in inches:");
    scanf("%f",&height);
    printf("%s, you are %0.3f feet tall",name,height);
    return 0;
}