/*
 * 1.1.28 删除重复元素。修改BinarySearch类中的测试用例来删去排序之后白名单中的所有重复元素。
 */
#include <stdio.h>
#include <stdlib.h>
#include "..\..\lib\in.h"

int rank(int key, int * a,int length);
int intcompar(const void * a,const void *b);
int rmduplicate(int * a,int length);

int main(int argc,char * argv[])
{
    int key;
    int_arr whitelist;
    readInts(&whitelist,argv[1]);
    qsort(whitelist.data,whitelist.length,sizeof(int),intcompar);
    whitelist.length = rmduplicate(whitelist.data,whitelist.length);
    while(scanf("%d",&key) == 1)
    {
        if(rank(key,whitelist.data,whitelist.length) < 0)
            printf("%d\n",key);
    }
    free(whitelist.data);
    return 0;
}

int rank(int key, int * a,int length)
{
    int lo = 0;
    int hi = length -1;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
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

int rmduplicate(int * a,int length)
{
    if( length == 0 || length == 1)
        return length;

    int newcount = 0;
    int old = 0;
    for(int i = 1; i < length; i++)
    {
        if(a[old] != a[i])
            old++;
        a[old] = a[i];
    }
    return old + 1;
}
