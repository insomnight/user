#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

typedef struct accumulator
{
    int n;
    double total;
} Accumulator;

/**
 * 添加一个新的数据值
 * param: a 指向累加器的指针
 * param: val 要添加的数据值
 */
void addDataValue(Accumulator * a,double val);

/**
 * 所有数据值得平均值
 * return: 所有数据的平均值
 */
double mean(Accumulator * a);

/**
 * 对象的字符串表示
 * param: a 指向累加器的指针
 * param: str 保存字符串的字符数组
 * param: n 字符数组的长度
 */
void accumulatorToString(Accumulator * a, char * str, size_t n);

#endif
