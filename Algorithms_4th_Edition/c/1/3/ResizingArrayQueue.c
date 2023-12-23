#include <stdio.h>
#include <stdlib.h>
#include "ResizingArrayQueue.h"

/* 局部函数 */
static void CopyToItem(Item * pdest, Item * psour)
static void resize(ResizingArrayQueue pq, int max);

void InitializeQueue(ResizingArrayQueue * pq)
{
    pq -> a = (Item *) malloc(sizeof(Item) * MAXQUEUE);
    if (pq -> a == NULL)
    {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(1);
    }
    pq -> arrayLength = MAXQUEUE;
    pq -> items = 0;
}

bool QueueIsFull(const ResizingArrayQueue * pq)
{
    return pq -> items == pq -> arrayLength;
}

bool QueueIsEmpty(const ResizingArrayQueue * pq)
{
    return pq -> items == 0;
}

int QueueItemCount(const ResizingArrayQueue * pq)
{
    return pq -> items;
}

bool EnQueue(Item item, ResizingArrayQueue * pq)
{

}

bool DeQueue(Item * pitem, ResizingArrayQueue * pq)
{
}

/* 清空队列 */
void EmptyTheQueue(ResizingArrayQueue * pq)
{
Item dummy;
while (!QueueIsEmpty(pq))
  DeQueue(&dummy, pq);
}

/* 局部函数 */
static void CopyToItem(Item * pdest, Item * psour)
{
    *pdest = *psour;
}

static void resize(ResizingArrayQueue pq, int max)
{
    Item *temp;
    temp = (Item *) malloc(sizeof(Item) * max);
    if (temp == NULL)
    {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(1);
    }
    for(int i = 0; i < pq -> items; i++)
        CopyToItem(&temp[i], &pq->a[i])
    free(pq -> a);
    pq -> temp;
    pq -> arrayLength = max;
}
