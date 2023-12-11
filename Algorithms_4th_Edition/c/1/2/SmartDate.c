#include <stdio.h>
#include <stdlib.h>
#include "SmartDate.h"
#define DEFULT_YEAR 2000
#define DEFAULT_MONTH 1
#define DEFAULT_DAY 1

static int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
static int day_of_weeks[6] = { 6, 7, 1, 2, 3, 4, 5}
static int day_of_weeks_r[6] = { 6, 5, 4, 3, 2, 1, 7}

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

int dayOfTheWeek(SmartDate * sd)
{
    int daysdiff = 0;
    if(year(sd) >= DEFULT_YEAR )
    {
        for(int i = DEFULT_YEAR; i < year(sd); i++) 
            daysdiff += isLeapYear(i) ? 366 : 365;
        for(int i = 1; i < month(sd); i++)
            daysdiff += isLeapYear(year(sd)) && i == 2 ? monthDay[i] + 1 : monthDay[i];
        daysdiff += day(sd);
        daysdiff -= 1;
        return day_of_weeks[daysdiff % 7];
    } else {
        for(int i = year(sd) + 1; i < DEFULT_YEAR; i++)
            daysdiff += isLeapYear(i) ? 366 : 365;
        for(int i = month(sd) + 1; i <= 12; i++)
            daysdiff += isLeapYear(year(sd)) && i == 2 ? monthDay[i] + 1 : monthDay[i];
        int i = month(sd);
        daysdiff += isLeapYear(year(sd)) && i == 2 ? monthDay[i] + 1 - day(sd) : monthDay[i] - day(sd);
        daysdiff++;
        return day_of_weeks_r[daysdiff % 7];
    }
}

int isLeapYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}
