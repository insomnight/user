#ifndef STATIC_SET_OF_INTS_H
#define STATIC_SET_OF_INTS_H

#include <stdbool.h>

typedef struct staticSETofInts
{
    int * a;
    int length;
} StaticSETofInts;

/**
 * 根据数组a[]中的所有值创建一个集合
 * param: StaticSETofInts * p 要初始化的集合
 * param: a[] , 数组a，用来初始化集合
 * param: n 数组a的长度
 */
void initStaticSETofInts(StaticSETofInts *p,int a[],int n);

/**
 * key是否存在于集合中
 * param: StaticSETofInts * p 集合的指针
 * param: key 要查找的整数
 */
bool contains(StaticSETofInts *p,int key);

void freeStaticSETofInts(StaticSETofInts *p);

#endif
