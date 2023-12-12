#ifndef RATIONAL_H
#define RATIONAL_H

typedef struct rational
{
    long numerator;
    long denominator;
} Rational;

void initRational(Rational * a,int numerator, int denominator);

Rational * plus(Rational * r, const Rational * a, const Rational * b); 

Rational * minus(Rational * r, const Rational * a, const Rational * b); 

Rational * times(Rational * r, const Rational * a, const Rational * b); 

Rational * divides(Rational * r, const Rational * a, const Rational * b); 

int rationalEquals(const Rational * a,const Rational * b);

char * rationalToString(const Rational * a, char * str, size_t n);

#endif
