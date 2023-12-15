#ifndef FIXEDCAPACITYSTACKOFSTRINGS_H
#define FIXEDCAPACITYSTACKOFSTRINGS_H

typedef struct fixedCapacityStackOfStrings
{
    char ** a;
    int n;
    int cap;
} FixedCapacityStackOfStrings;

void initFixedCapacityStackOfStrings(FixedCapacityStackOfStrings *fp, int cap);

void push(FixedCapacityStackOfStrings * fp,char * item);

char * pop(FixedCapacityStackOfStrings * fp);

int isEmpty(FixedCapacityStackOfStrings * fp);

int size(FixedCapacityStackOfStrings * fp);

int freeAll(FixedCapacityStackOfStrings * fp);

int isFull(FixedCapacityStackOfStrings * fp)

#endif
