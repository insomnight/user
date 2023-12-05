#include <stdio.h>
#include <stdlib.h>
#include "counter.h"
#include "..\..\..\lib\std_random.h"

#define SIDES 6
#define IDLEN 100

int main(int argc,char * argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage: %s integer(t)\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int t;
    int result;
    char *str;
    t = atoi(argv[1]);
    Counter rolls[SIDES + 1];
    for(int i = 1; i <= SIDES; i++)
    {
        str = (char *) malloc(4 * sizeof(char));
        snprintf(str,4,"%d's",i);
        initCounter(&rolls[i], str);
    }

    for(int i = 0; i < t; i++)
    {
        result = uniformIntL2H(1, SIDES + 1);
        increment(&rolls[result]);
    }

    str = (char *) malloc(IDLEN * sizeof(char));
    for(int i = 1; i <= SIDES; i++)
    {
        counterString(&rolls[i], str, IDLEN);
        printf("%s\n",str);
        free(rolls[i].id);
    }
    free(str);
    return 0;
}
