/*
 * 1.3.12 编写一个可迭代的Stack用例，它含有一个静态的copy()方法，接受一个字符串的栈作为参数并返回该栈的一个副本。注意：这种能力是迭代器价值的一个重要体现，因为有了它我们无需改变基本API就能够实现这种功能。
 */
#include <stdio.h>
#include <stdlib.h>
#include "..\..\lib\stack.h"

Stack * copy(Stack * dest, Stack * sour);

int main(void)
{
    Stack one;
    InitializeStack(&one);
    Stack two;
    InitializeStack(&two);
    Push(0.0,&one);
    Push(0.1,&one);
    Push(2.0,&one);
    Push(0.3,&one);
    Iterator i;
    initIterator(&i, &one);
    while(hasNext(&i))
        printf("%lf\n",next(&i));

    copy(&two,&one);

    initIterator(&i, &two);
    while(hasNext(&i))
        printf("%lf\n",next(&i));

    return 0;
}

Stack * copy(Stack * dest, Stack * sour)
{
    Stack temp;
    InitializeStack(&temp);
    Iterator i;
    initIterator(&i, sour);
    InitializeStack(dest);
    while(hasNext(&i))
        Push(next(&i),&temp);
    initIterator(&i, &temp);
    while(hasNext(&i))
        Push(next(&i),dest);
    return dest;
}
