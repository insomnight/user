#include <stdio.h>
#include <stdlib.h>
#include "lib/std_random.h"

int main(int argc,char * argv[])
{
    int n = atoi(argv[1]);
    double lo = atoi(argv[2]);
    int hi = atoi(argv[3]);
    setSeedByTime();
    for(int i = 0; i < n; i++)
    {
        double x = uniformDoubleL2H(lo,hi);
        printf("%lf\n",x);
    }
    return 0;
}

