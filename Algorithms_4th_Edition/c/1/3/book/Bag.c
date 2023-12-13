#include <stdio.h>
#include <stdlib.h>
#include "Bag.h"

/**
 * 创建一个空背包
 */
void initBag(Bag * b)
{
    InitializeList(&(b->items));
    b->size = 0;
}

/**
 * 添加一个元素
 */
void add(Bag * b,Item item)
{
    if(AddItem(item, &(b -> items)))
        b->size++;
    else
    {
        fprintf(stderr,"add the item exception");
        exit(EXIT_FAILURE);
    }
}

/**
 * 背包是否为空
 */
int isEmpty(const Bag * b)
{
    return b->size == 0;
}

/*
 * 背包中的元素数量
 */
int size(const Bag * b)
{
    return b->size;
}