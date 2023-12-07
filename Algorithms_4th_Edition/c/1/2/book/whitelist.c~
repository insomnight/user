#include <stdio.h>
#include <stdlib.h>
#include "static_set_of_ints.h"
#include "..\..\..\lib\in.h"

int main(int argc,char * argv[])
{
    int key;
    int_arr w;
    readInts(&w,argv[1]);
    StaticSETofInts set;
    initStaticSETofInts(&set,w.data,w.length);
    free(w.data);
    while(scanf("%d",&key) == 1)
    {
        if(contains(&set,key))
            printf("%d\n",key);
    }
    freeStaticSETofInts(&set);
    return 0;
}
