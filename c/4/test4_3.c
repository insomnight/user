#include<stdio.h>

int main(void)
{
    float f;
    scanf("%f",&f);
    printf("The input is %0.1f or %0.1e\n",f,f);
    printf("The input is %+0.3f or %0.3E\n",f,f);

    return 0;
}