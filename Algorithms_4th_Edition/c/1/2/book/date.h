#ifndef DATE_H
#define DATE_H

#ifdef ONE

typedef struct date{
    int value;
} Date;

#else

typedef struct date{
    int year;
    int month;
    int day;
} Date;

#endif

void initDate(Date * d, int y, int m, int day);

int month(Date *d);

int day(Date *d);

int year(Date *d);

void dateToString(Date * d, char * str, int n);

#endif
