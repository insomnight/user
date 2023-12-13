#ifndef BAG_H
#define BAG_H

#define BAG_MAX

typedef int Item;

typedef struct bag
{
    Item items[BAG_MAX];
    int size;
} Bag;

/**
 * 创建一个空背包
 */
void initBag(Bag * b);

/**
 * 添加一个元素
 */
void add(Bag * b,Item item);

/**
 * 背包是否为空
 */
int isEmpty(const Bag * b);

/*
 * 背包中的元素数量
 */
int size(const Bag * b);

#endif
