#include<stdio.h>
#include "pe12-3a.h"

void set_mode(int * mode,int * premode)
{
    if( *mode > 1 )
    {
        *mode = *premode;
        printf("Inavalid mode specified. Mode %d(%s) userd.\n",*mode, *mode ? "US" : "metric");
    }
    else
        *premode = *mode;
}

void get_info(int mode, double * distance , double *fuel)
{
    printf("Enter distance traveled in %s: ", mode ? "miles" : "kilometers");
    scanf("%lf",distance);
    printf("Enter fuel consumed in %s: ", mode ? "gallons" : "liters");
    scanf("%lf",fuel);
}

void show_info(int mode, double distance, double fuel)
{
    if(mode)
        printf("Fuel consumption is %0.1f miles per gallon.\n", distance / fuel );
    else
        printf("Fuel consumption is %0.2f liters per 100 km.\n", fuel / distance * 100 );
}

