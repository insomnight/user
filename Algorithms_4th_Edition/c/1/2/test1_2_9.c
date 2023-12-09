/*
 * 1.2.9 修改BinarySearch（请见1.1.10.1节中的二分查找代码），使用Counter统计在有查找中被检查的键的总数并在查找全部结束后打印该值。提示：在main()中创建一个Counter对象并将它作为参数传递给rank()。
 */
#include <stdio.h>
#include <stdlib.h>
#include "..\..\lib\in.h"
#include "book\counter.h"

int rank(int key, int * a,int length,Counter * c);
int intcompar(const void * a,const void *b);

int main(int argc,char * argv[])
{
    int key;
    int_arr whitelist;
    readInts(&whitelist,argv[1]);
    qsort(whitelist.data,whitelist.length,sizeof(int),intcompar);

    Counter c;
    char str[100];
    while(scanf("%d",&key) == 1)
    {
        initCounter(&c,"count");
        if(rank(key,whitelist.data,whitelist.length,&c) < 0)
        {
            counterString(&c,str,100);
            printf("%d\n%s\n",key,str);
        }
    }
    free(whitelist.data);
    return 0;
}

int rank(int key, int * a,int length,Counter * c)
{
    int lo = 0;
    int hi = length -1;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        increment(c);
        if(key < a[mid]) hi = mid - 1;
        else if (key > a[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}

int intcompar(const void * a,const void * b)
{
    int * ia = (int *) a;
    int * ib = (int *) b;
    return *ia - *ib;
}
