#include <stdio.h>
#include <stdlib.h>
#include "Rational.h"

long gcd_sign(long p, long q);

long gcd(long p,long q);

void initRational(Rational * a,long numerator, long denominator)
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

    initRational(r,numerator,denominator);
    return r;
}

Rational * minus(Rational * r, const Rational * a, const Rational * b)
{
    long gcd_num,numerator,denominator;

    numerator = a->numerator * b->denominator - b->numerator * a->denominator;
    denominator = a->denominator * b->denominator;

    initRational(r,numerator,denominator);
    return r;
}

Rational * times(Rational * r, const Rational * a, const Rational * b)
{
    long gcd_num,numerator,denominator;

    numerator = a->numerator * b->numerator;
    denominator = a->denominator * b->denominator;

    initRational(r,numerator,denominator);
    return r;
}

Rational * divides(Rational * r, const Rational * a, const Rational * b)
{
    long gcd_num,numerator,denominator;

    numerator = a->numerator * b->denominator;
    denominator = a->denominator * b->numerator;

    initRational(r,numerator,denominator);
    return r;
}

int rationalEquals(const Rational * a,const Rational * b)
{
    return a->numerator == b->numerator && a->denominator == b->denominator;
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

int main(void)
{
    Rational a,b,r;
    char stra[100];
    char strb[100];
    char strr[100];
    initRational(&a,2,6);
    rationalToString(&a,stra,100);
    printf("%s\n",stra);
    initRational(&b,-6,-15);
    rationalToString(&b,strb,100);
    printf("%s\n",strb);
    
    plus(&r,&a,&b);
    rationalToString(&r,strr,100);
    printf("%s + %s = %s\n",stra,strb,strr);

    minus(&r,&a,&b);
    rationalToString(&r,strr,100);
    printf("%s - %s = %s\n",stra,strb,strr);

    times(&r,&a,&b);
    rationalToString(&r,strr,100);
    printf("%s * %s = %s\n",stra,strb,strr);
    
    divides(&r,&a,&b);
    rationalToString(&r,strr,100);
    printf("%s / %s = %s\n",stra,strb,strr);

    printf("%s is %s : %s", stra, strb, rationalEquals( &a, &b) ? "true" : "false");
    return 0;
}
