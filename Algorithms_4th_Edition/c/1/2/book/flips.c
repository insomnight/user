#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "counter.h"
#include "..\..\..\lib\std_random.h"
#define CLEN 100

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage: %s integer(T)\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int t = atoi(argv[1]);
    char str[CLEN];

    Counter heads,tails;
    initCounter(&heads,"heads");
    initCounter(&tails,"tails");

    for(int i = 0; i < t; i++)
        if(bernoulli(0.5))
            increment(&heads);
        else
            increment(&tails);
    counterString(&heads,str,CLEN);
    printf("%s\n",str);
    counterString(&tails,str,CLEN);
    printf("%s\n",str);

    int d = tally(&heads) - tally(&tails);
    printf("delta: %d", d > 0 ? d : -d);
    return 0;
}
