#ifndef INTERVAL1D_H
#define INTERVAL1D_H

typedef struct interval1d
{
    double min;
    double max;
} Interval1D;

/**
 * Initializes a closed interval [min,max].
 * Params: min - the smaller endpoint
 *         max - the larger endpoint
 */
void initInterval1D(Interval1D * i, double min, double max);

/**
 * Params: i - the interval
 * Returns the min endpoint of this interval.
 * Returns: the min endpoint of this interval.
 */
double min(Interval1D * i);

/**
 * Params: i - the interval
 * Returns the max endpoint of this interval.
 * Returns: the max endpoint of this interval.
 */
double max(Interval1D * i);

/**
 * Returns true if this interval intersects the specified interval.
 * Params: a - the interval
 *         b - the other interval
 * Returns: true if a intersects the b;false otherwise
 */
int intersects(Interval1D * a,Interval1D * b);

/**
 * Returns true if this interval contains the specified value.
 * Params: i - the interval
 *         x - the value
 * Returns: true if this interval contains the value x;false otherwise
 */
int contains(Interval1D * i, double x);

/**
 * Returns the length of this interval.
 * Params: i - the terval
 * Returns: the length of this interval(max - min)
 */
double length(Interval1D * i);

/**
 * init the char arr with interval1d.
 */
void interval1DtoString(Interval1d * i,char * str,size_t n);

#endif
