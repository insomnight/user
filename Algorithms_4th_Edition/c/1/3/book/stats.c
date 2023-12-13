#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Bag.h"

int main(void)
{
    Bag numbers;
    double num,sum,std,mean;
    initBag(&numbers);
    while(scanf("%lf",&num) == 1)
        add(&numbers,num);
    sum = 0.0;
    
    Node * h;
    h = numbers.items;
    while( h != NULL)
    {
        sum += h -> item;
        h = h -> next;
    }
    int n = size(&numbers);
    mean = sum / n;
    h = numbers.items;
    sum = 0.0;
    while(h != NULL)
    {
        sum += (h -> item - mean) * (h->item - mean);
        h = h -> next;
    }
    std = sqrt(sum / (n-1));
    printf("Mean: %.2f\n",mean);
    printf("Std dev: %.2f\n",std);
    return 0;
}
