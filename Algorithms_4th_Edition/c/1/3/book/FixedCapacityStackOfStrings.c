#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FixedCapacityStackOfStrings.h"

void initFixedCapacityStackOfStrings(FixedCapacityStackOfStrings *fp, int cap)
{
    fp->a = (char **) malloc(cap * sizeof(char *));
    fp->cap = cap;
    fp->n = 0;
}

void push(FixedCapacityStackOfStrings * fp,char * item)
{
    fp->a[fp->n] = (char *) malloc( strlen(item) * sizeof(char) );
    strcpy(fp->a[fp->n],item);
    fp->n++;
}

char * pop(FixedCapacityStackOfStrings * fp)
{
    return fp->a[--fp->n];
}

int isEmpty(FixedCapacityStackOfStrings * fp)
{
    return fp->n == 0;
}

int size(FixedCapacityStackOfStrings * fp)
{
    return fp->n;
}

int freeAll(FixedCapacityStackOfStrings * fp)
{
    for(int i = 0; i < fp->cap; i++)
        free(fp->a[i]);
    free(fp->a);
}

int isFull( FixedCapacityStackOfStrings * fp)
{
    return f->n == fp->cap;
}

int main(void)
{
    FixedCapacityStackOfStrings s;
    initFixedCapacityStackOfStrings(&s,100);
    char item[100];
    char * pp;
    while(scanf("%s",item) == 1 && item[0] != '\0')
    {
        if(strcmp(item,"-"))
            push(&s,item);
        else if(!isEmpty(&s))
        {
            pp = pop(&s);
            printf("%s ",pp);
            free(pp);
        }
    }
    printf("(%d left on stack)\n",size(&s));
    freeAll(&s);
    return 0;
}

