#ifndef DATE_H
#define DATE_H

#ifdef ONE
typedef struct date{
    int year;
    int month;
    int day;
} Date;
#endif

void initDate(Date * date, int y, int m, int d);

int month(Date *date);

int day(Date *date);

int year(Date *date);

void dateToString(Date * date, char * str, int size);

#endif
