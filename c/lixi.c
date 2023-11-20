#include<stdio.h>

int main(void)
{
    double tongzhang = 0.1;
    double now = 1;
    for(int i = 0;i<50;i++)
        printf("i = %d,now is %lf\n",i,now = now * (1 - tongzhang));
    return 0;
}
        
