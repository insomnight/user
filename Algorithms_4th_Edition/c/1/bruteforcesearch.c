#include <stdio.h>
#include <stdlib.h>
#include "..\lib\in.h"

int rank(int key, int * a,int length);

int main(int argc,char * argv[])
{
    int key;
    int_arr whitelist;
    readInts(&whitelist,argv[1]);

    while(scanf("%d",&key) == 1)
    {
        if(rank(key,whitelist.data,whitelist.length) < 0)
            printf("%d\n",key);
    }
    free(whitelist.data);
    return 0;
}

int rank(int key, int * a,int length)
{
    for(int i = 0; i < length; i++)
        if(a[i] == key) return i;
    return -1;
}
