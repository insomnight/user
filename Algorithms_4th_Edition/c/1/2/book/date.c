#include <stdio.h>
#include <stdlib.h>
#include "date.h"

void initDate(Date * d, int y, int m, int day)
{
#ifdef ONE
    d->value = y * 512 + m * 32 + d;
#else
    d->month = m;
    d->day = day;
    d->year = y;
#endif
}

int month(Date *d)
{
#ifdef ONE
    return ( d->value / 32 ) % 16;
#else
    return d->month;
#endif
}

int day(Date *d)
{
#ifdef ONE
    return d->day % 32;
#else
    return d->day;
#endif
}

int year(Date *d)
{
#ifdef ONE
    return d->value / 512;
#else
    return d->year;
#endif
}

void dateToString(Date * d, char * str, int n)
{
    snprintf(str,n,"%d/%d/%d",month(d),day(d),year(d));
}
