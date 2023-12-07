#include <stdio.h>
#include <stdlib.h>
#include "accumulator.h"
#include "..\..\..\lib\std_random.h"

int main(int argc,char * argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage: %s integer(cnt)\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    setSeedByTime();
    int t = atoi(argv[1]);
    Accumulator a;
    initAccumulator(&a);
    for(int i = 0; i < t; i++)
        addDataValue(&a,uniformDouble());
    char str[100];
    accumulatorToString(&a,str,100);
    printf("%s\n",str);
    return 0;
}
