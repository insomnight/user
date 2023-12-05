/*
 * 标准的随机数库
 * 功能: 简化c标准库的生成随机数操作
 */
#ifndef STD_RANDOM_H_
#define STD_RANDOM_H_

/*
 * 通过时间来作为随机数生成算法种子
 */
void setSeedByTime(void);

/*
 * 设置伪随机数生成算法种子
 */
void setSeed(unsigned int seed);

/*
 * Return a random real number uniformly in [0,1).
 * Returns: a random real number uniformly in [0,1).
 */
double uniformDouble();

/*
 * Returns a random real number uniformly in [a,b).
 * Params: low   - the left endpoint
 *         hight - the right endpoint
 * Returns: a random real number uniformly in [a,b)
 * Throws: IllegalArgumentRxception - unless a < b
 */
double uniformDoubleL2H(double low,double hight);

/*
 * returns a random integer uniformly in [0,n).
 * params: n - number of possible integers
 * return: a random integer uniformly between 0 (inclusive) and n (exclusive)
 */
int uniformInt(int n);

/*
 * Rearranges the elements of the specified array in uniformly random order
 * params: a - the array to shuffle
 */
void shuffleDoubles(double a[],int n);

/*
 * Rearranges the elements of the specified array in uniformly random order
 * params: a - the array to shuffle
 */
void shuffleInts(int a[],int n);

/**
 * returns a random boolean from Bernoulli distribution with success probability p.
 * params: p - the probability of returning true
 * returns: 1 with probability p and 0 with probability 1 - p;
 * Threows: IlleagelArgumentException - unless 0 <= p <= 1.0
 */ 
int bernoulli(double p);

#endif
