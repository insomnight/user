#include <stdio.h>
#include <stdlib.h>
#include "date.h"

void initDate(Date * date, int y, int m, int d)
{
    date->month = m;
    date->day = d;
    date->year = y;
}

int month(Date *date)
{
    return date->month;
}

int day(Date *date)
{
    return date->day;
}

int year(Date *date)
{
    return date->year;
}

void dateToString(Date * date, char * str, int size)
{
    sprintf(str,size,"%d/%d/%d",month(),day(),year());
}

