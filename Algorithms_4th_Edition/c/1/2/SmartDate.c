#include <stdio.h>
#include <stdlib.h>
#include "SmartDate.h"

static int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

int isLeapYear(int y);

void initDate(SmartDate * sd,int y,int m,int d)
{
    if(m < 1 || m > 12)
    {
        fprintf(stderr,"the month %d not in the 1 to 12 range",m);
        exit(EXIT_FAILURE);
    }

    if(isLeapYear(y) && m == 2 && (d < 1 || d > 29))
    {
        fprintf(stderr,"the day %d not in the 1 to 29 range",m);
        exit(EXIT_FAILURE);
    }

    if(d < 1 || d > monthDay[m])
    {
        fprintf(stderr,"the day %d not in the 1 to %d range",m,monthDay[m]);
        exit(EXIT_FAILURE);
    }

    sd -> value = y * 512 + m * 32 + d;
}

int month(SmartDate * sd)
{
    return (sd->value / 32) % 16;
}

int day(SmartDate * sd)
{
    return sd->value % 32;
}

int year(SmartDate * sd)
{
    return sd->value / 512;
}

void smartDateToString(SmartDate * sd,char * str,size_t n)
{
    snprintf(str, n,"%d/%d/%d",month(sd),day(sd),year(sd));
}

int isLeapYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || year % 400 == 0;
}
