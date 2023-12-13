#include <stdio.h>
#include <stdlib.h>
#include "..\..\..\lib\stack.h"

void printInt(int n);

int main(void)
{
    Stack sck;
    int num;
    InitializeStack(&sck);
    while(scanf("%d",&num) == 1)
        Push(num,&sck);
    Traverse(&sck,printInt);
    return 0;
}

void printInt(int n)
{
    printf("%d\n",n);
}
