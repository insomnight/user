/* stack.h –– 栈的接口 */
#include <stdbool.h>
/* 在这里插入 Item 类型 */
/* 例如： typedef int Item; */
typedef char Item;

#define MAXSTACK 100

typedef struct stack
{
    Item items[MAXSTACK];/*存储信息*/
    int top;/*第1个空位的索引*/
} Stack;

/*操作:初始化栈*/
/*前提条件:ps 指向一个栈*/
/*后置条件:该栈被初始化为空*/
void InitializeStack(Stack * ps);

/*操作:检查栈是否已满*/
/*前提条件:ps 指向之前已被初始化的栈*/
/*后置条件:如果栈已满,该函数返回true;否则,返回false*/
bool FullStack(const Stack * ps);

/*操作:检查栈是否为空*/
/*前提条件:ps指向之前已被初始化的栈*/
/*后置条件:如果栈为空,该函数返回true;否则,返回false*/
bool EmptyStack(const Stack *ps);

/*操作:把项压入栈顶*/
/*前提条件:ps 指向之前已被初始化的栈*/
/*item是待压入栈顶的项*/
/*后置条件:如果栈不满,把 item 放在栈顶,该函数返回ture;*/
/*否则,栈不变,该函数返回false*/
bool Push(Item item, Stack * ps);

/*操作:从栈顶删除项*/
/*前提条件:ps 指向之前已被初始化的栈*/
/*后置条件:如果栈不为空,把栈顶的item拷贝到*pitem,*/
/*删除栈顶的item,该函数返回ture;*/
/*如果该操作后栈中没有项,则重置该栈为空*/
/*如果删除操作之前栈为空,栈不变,该函数返回false*/
bool Pop(Item *pitem, Stack * ps);

/* 访问每个节点并执行pfun指向的函数 */
void Traverse(const Stack * ps, void(*pfun)(Item item));

/* 访问最新加入栈的元素,不删除 */
bool peek(Item *pitem,const Stack * ps);
