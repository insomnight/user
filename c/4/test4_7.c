#include<stdio.h>
#include<float.h>

int main(void)
{
    double d = 1.0/3.0;
    float f = 1.0/3.0;
    printf("%0.6f %0.6f\n",d,f);
    printf("%0.12f %0.12f\n",d,f);
    printf("%0.16f %0.16f\n",d,f);
    printf("%d %d",DBL_DIG,FLT_DIG);
    return 0;
}