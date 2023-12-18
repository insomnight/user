#include <stdio.h>
#include <stdlib.h>
#include "LinkedString.h"

static void copyToNode(char ch,Node * pnode);

void initString(String *str)
{
    str->head = NULL;
    str->last = NULL;
    str->length = 0;
}

bool stringIsEmpty(const String * str)
{
    return str->head == NULL;
}

bool stringLength(const String * str)
{
    return str->length;
}

bool appendChar(String * str,char ch)
{
    Node * pnew;
    pnew = (Node *) malloc(sizeof(Node));
    if(pnew == NULL)
        return false;

    copyToNode(ch,pnew);
    pnew->next = NULL;
    if(str->head == NULL)
    {
        str->head = pnew;
        str->last = pnew;
    } else 
    {
        str->last->next = pnew;
        str->last = pnew;
    }
    str->length++;
    return true;
}

bool addFirst(String * str, char ch)
{
    Node * pnew;
    pnew = (Node *) malloc(sizeof(Node));
    if(pnew == NULL)
        return false;

    copyToNode(ch,pnew);
    pnew->next = NULL;
    if(str->head == NULL)
    {
        str->head = pnew;
        str->last = pnew;
    } else 
    {
        pnew->next = str->head;
        str->head = pnew;
    }
    str->length++;
    return true;
}

String * append(String *dest,const String * sour)
{
    dest->last->next = sour->head;
    dest->last = sour->last;
    dest->length += sour->length;
    return dest;
}

void stringTraverse(const String * str,void(*pfun)(char item))
{
    Node * pnode = str->head;

    while(pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

void emptyTheString(String * str)
{
    Node * psave;

    while(str->head != NULL)
    {
        psave = str->head->next;
        free(str->head);
        str->head = psave;
    }
    str->head = NULL;
    str->last = NULL;
    str->length = 0;
}

static void copyToNode(char item,Node * pnode)
{
    pnode->item = item;
}
