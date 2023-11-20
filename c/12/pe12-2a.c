#include<stdio.h>
#include "pe12-2a.h"

static int mode = 0;
static double distance;
static double fuel;

void set_mode(int m)
{
    if( m > 1 )
        printf("Inavalid mode specified. Mode %d(%s) userd.\n",mode, mode ? "US" : "metric");
    else
        mode = m;
}

void get_info(void)
{
    printf("Enter distance traveled in %s: ", mode ? "miles" : "kilometers");
    scanf("%lf",&distance);
    printf("Enter fuel consumed in %s: ", mode ? "gallons" : "liters");
    scanf("%lf",&fuel);
}

void show_info(void)
{
    if(mode)
        printf("Fuel consumption is %0.1f miles per gallon.\n", distance / fuel );
    else
        printf("Fuel consumption is %0.2f liters per 100 km.\n", fuel / distance * 100 );
}

