#include<stdio.h>
#include<string.h>

int main(void)
{
    char name[40];

    printf("Please enter your name:");
    scanf("%s",name);
    printf("a.\"%s\"\n",name);
    printf("b.\"%20s\"\n",name);
    printf("b.\"%-20s\"\n",name);
    printf("b.%*s\n",strlen(name)+3,name);
    return 0;
}