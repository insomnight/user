#include<stdio.h>

int main(void)
{
    int ascii_code;
    char ch;
    printf("Please enter an ASCII code value:");
    scanf("%d",&ascii_code);
    ch = ascii_code;
    printf("ASCII code value: %d, char is %c \n",ascii_code,ch);
    return 0;
}