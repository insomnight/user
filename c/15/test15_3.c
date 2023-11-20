/*
 * 3．编写一个函数，接受一个int类型的参数，并返回该参数中打开位的数量。在一个程序中测试该函数。
 */
#include <stdio.h>

#define MARK 0x1

int openbitcount(int n);

int main(void)
{
    int n;
    int count;
    while(scanf("%d",&n))
    {
        count = openbitcount(n);
        printf("%d have %d bit open\n",n,count);
    }
    return 0;
}


int openbitcount(int n)
{
    int count = 0;

    for(; n != 0; n >>= 1)
    {
        count += n & MARK;
    }        
    return count;
}
