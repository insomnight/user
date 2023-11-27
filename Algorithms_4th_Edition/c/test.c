#include <stdio.h>
#include <math.h>

int main(void)
{
    int sum = 0;
    for(int i = 1; i< 1000; i *=2)
        for(int j = 0; j < 1000; j++)
            sum++;
    printf("%d",sum);
    return 0;
}
