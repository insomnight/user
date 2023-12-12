#include <stdio.h>
#include <stdlib.h>
#include "Rational.h"

long gcd_sign(long p, long q);

long gcd(long p,long q);

void initRational(Rational * a,int numerator, int denominator)
{
    if(denominator == 0)
    {
        fprintf(stderr,"the denominator : %d not zero",denominator);
        exit(EXIT_FAILURE);
    }
    long gcd_num;
    gcd_num = gcd_sign(numerator,denominator);
    a->numerator = numerator / gcd_num;
    a->denominator = denominator / gcd_num;
}

Rational * plus(Rational * r, const Rational * a, const Rational * b)
{
    long gcd_num,numerator,denominator;

    numerator = a->numerator * b->denominator + b->numerator * a->denominator;
    denominator = a->denominator * b->denominator;

    gcd_num = gcd_sign(numerator,denominator);
    r->numerator = numerator / gcd_num;
    r->denominator = denominator / gcd_num;
    return r;
}

Rational * minus(Rational * r, const Rational * a, const Rational * b)
{
    long gcd_num,numerator,denominator;

    numerator = a->numerator * b->denominator - b->numerator * a->denominator;
    denominator = a->denominator * b->denominator;

    gcd_num = gcd_sign(numerator,denominator);
    r->numerator = numerator / gcd_num;
    r->denominator = denominator / gcd_num;
    return r;
}

Rational * times(Rational * r, const Rational * a, const Rational * b)
{
    long gcd_num,numerator,denominator;

    numerator = a->numerator * b->numerator;
    denominator = a->denominator * b->denominator;

    gcd_num = gcd_sign(numerator,denominator);
    r->numerator = numerator / gcd_num;
    r->denominator = denominator / gcd_num;
    return r;
}

Rational * divides(Rational * r, const Rational * a, const Rational * b)
{
    long gcd_num,numerator,denominator;

    numerator = a->numerator * b->denominator;
    denominator = a->denominator * b->numerator;

    gcd_num = gcd_sign(numerator,denominator);
    r->numerator = numerator / gcd_num;
    r->denominator = denominator / gcd_num;
    return r;
}

int rationalEquals(const Rational * a,const Rational * b)
{
    return ( (a->numerator / b->numerator) / (a->denominator / b->denominator) ) == 1;
}

char * rationalToString(const Rational * a, char * str, size_t n)
{
    snprintf(str,n,"%ld/%ld",a->numerator,a->denominator);
    return str;
}

long gcd(long p,long q)
{
    if(q == 0) return p;
    long r = p % q;
    return gcd(q,r);
}

long gcd_sign(long p, long q)
{
    long result;
    result = gcd(p > 0 ? p : -p, q > 0 ? q : -q);
    if( p < 0 && q < 0)
        return -result;
    else
        return result;
}
