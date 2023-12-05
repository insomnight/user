#include <stdio.h>
#include <stdlib.h>
#include "..\..\..\lib\std_random.h"
#include "counter.h"
#define CLEN 100

Counter * max(Counter *x,Counter *y);

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage: %s integer(T)\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int t = atoi(argv[1]);
    char str[CLEN];
    setSeedByTime();
    Counter heads,tails;
    initCounter(&heads,"heads");
    initCounter(&tails,"tails");

    for(int i = 0; i < t; i++)
        if(bernoulli(0.5))
            increment(&heads);
        else
            increment(&tails);

    if(tally(&heads) == tally(&tails))
        puts("Tie");
    else
    {
        counterString(max(&heads,&tails),str,CLEN);
        printf("%s wins\n",str);
    }

    return 0;
}

Counter * max(Counter *x,Counter *y)
{
    if(tally(x) > tally(y)) return x;
    else return y;
}
