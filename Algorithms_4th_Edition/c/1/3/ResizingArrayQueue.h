#ifndef RESIZING_ARRAY_QUEUE_H_
#define RESIZING_ARRAY_QUEUE_H_
#include <stdbool.h>

// 在这里插入Item类型的定义，例如
// typedef int Item;        // 用于use_q.c
// 或者 typedef struct item {int gumption; int charisma;} Item;
#define MAXQUEUE 16

typedef int Item;

typedef struct resizingArrayQueue
{
    Item * a;
    int arrayLength;
    int end;
    int head;
} ResizingArrayQueue;

/* 操作：        初始化队列                                       */
/* 前提条件：    pq 指向一个队列                                  */
/* 后置条件：    队列被初始化为空                                 */
void InitializeQueue(ResizingArrayQueue * pq);

/* 操作：        检查队列是否已满                                 */
/* 前提条件：    pq 指向之前被初始化的队列                         */
/* 后置条件：    如果队列已满则返回true，否则返回false             */
bool QueueIsFull(const ResizingArrayQueue * pq);

/* 操作：        检查队列是否为空                                 */
/* 前提条件：    pq 指向之前被初始化的队列                         */
/* 后置条件：    如果队列为空则返回true，否则返回false             */
bool QueueIsEmpty(const ResizingArrayQueue *pq);

/* 操作：        确定队列中的项数                                 */
/* 前提条件：    pq 指向之前被初始化的队列                         */
/* 后置条件：    返回队列中的项数                                 */
int QueueItemCount(const ResizingArrayQueue * pq);

/* 操作：        在队列末尾添加项                                 */
/* 前提条件：    pq 指向之前被初始化的队列                         */
/*              item是要被添加在队列末尾的项                      */
/* 后置条件：    如果队列不为空，item将被添加在队列的末尾，         */
/*              该函数返回true；否则，队列不改变，该函数返回false  */
bool EnQueue(Item item, ResizingArrayQueue * pq);

/* 操作：        从队列的开头删除项                              */
/* 前提条件：    pq 指向之前被初始化的队列                        */
/* 后置条件：    如果队列不为空，队列首端的item将被拷贝到*pitem中  */
/*              并被删除，且函数返回true；                      */
/*              如果该操作使得队列为空，则重置队列为空            */
/*              如果队列在操作前为空，该函数返回false            */
bool DeQueue(Item *pitem, ResizingArrayQueue * pq);

/* 操作：        清空队列                                      */
/* 前提条件：    pq 指向之前被初始化的队列                      */
/* 后置条件：    队列被清空                                    */
void EmptyTheQueue(ResizingArrayQueue * pq);

#endif
