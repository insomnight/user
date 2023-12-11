#include <stdio.h>
#include <stdlib.h>
#include "Transaction.h"

char * who(Transaction * t)
{
    return t->cust_name;
}

SmartDate * when(Transaction * t)
{
    return t->sd;
}

double amount(Transaction * t)
{
    return t->amount;
}

void transactionToString(Transation * t,char * str,size_t n)
{
    char s[100];
    smartDateToString(t->sd,s,100);
    snprintf(str,n,"%s, %s, %lf",t->cust_name,s,t->amount); 
}
