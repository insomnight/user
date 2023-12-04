/*
 * 计数器的API
 */
#ifndef COUNTER_H
#define COUNTER_H

typedef struct counter {
    int data;
    char * id;
} Counter;

/**
 * 初始化一个名为id的计数器
 * param: c - 计数器存储的数据对象
 * param: id - 初始化计数器名字的
 */ 
void initCounter(Counter *c,const char * id);

/**
 * 将计数器的值加1
 * param: c是计数器存储的数据指针
 */ 
void increment(Counter *c);

/**
 * 该对象创建之后计算器被加1的次数
 * param: c是计数器存储的数据指针
 * return: 返回被加1的次数
 */
int tally(const Counter *c);

void counterString(const Counter * c,char * st,int n);

#endif
