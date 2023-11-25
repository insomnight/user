/*
 * 标准的随机数库实现
 * 功能: 简化c标准库的生成随机数操作
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "std_random.h"

/*
 * 通过时间来作为随机数生成算法种子
 */
void setSeedByTime(void)
{
    srand((unsigned int) time(0));
    //刷新一下，防止种子在一时间第一个数比较接近
    rand();
}

/*
 * 设置伪随机数生成算法种子
 */
void setSeed(unsigned int seed)
{
    srand(seed);
    rand();
}

/*
 * Return a random real number uniformly in [0,1).
 * Returns: a random real number uniformly in [0,1).
 */
double uniformDouble()
{
    int rand_num = rand();
    return (double) rand_num / ((double) RAND_MAX + 1) ;
}

/*
 * Returns a random real number uniformly in [a,b).
 * Params: low   - the left endpoint
 *         hight - the right endpoint
 * Returns: a random real number uniformly in [a,b)
 * Throws: IllegalArgumentRxception - unless a < b
 */
double uniformDoubleL2H(double low,double hight)
{
    if(low >= hight)
    {
        fprintf(stderr,"invalid range: [ \"%lf\", \"%lf\")",low,hight);
        exit(EXIT_FAILURE);
    }
    return low + uniformDouble() * (hight - low);
}
