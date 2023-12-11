#ifndef TRANSACTION_h
#define TRANSACTION_h

#include "SmartDate.h"

typedef struct transaction
{
    char * cust_name;
    SmartDate * sd;
    double amount;
} Transaction;

char * who(Transaction * t);

SmartDate * when(Transaction * t);

double amount(Transaction * t);

void transactionToString(Transation * t,char * str,size_t n);

#endif
