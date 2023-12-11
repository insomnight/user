#ifndef SMARTDATE_H
#define SMARTDATE_H

typedef struct smartDate
{
    int value;
} SmartDate;

void initDate(SmartDate * sd,int y,int m,int d);

int month(SmartDate * sd);

int day(SmartDate * sd);

int year(SmartDate * sd);

void smartDateToString(SmartDate * sd,char * str,size_t n);

#endif
