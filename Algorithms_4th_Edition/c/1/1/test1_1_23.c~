/*
 * 1.1.23 为BinarySearch的测试用例添加一个参数：+打印出标准输入中不在白名单上的值；-，则打印出标准输入中在白名单上的值
 */
#include <stdio.h>
#include <stdlib.h>
#include "..\..\lib\in.h"

int rank(int key, int * a,int length);
int intcompar(const void * a,const void *b);

int main(int argc,char * argv[])
{
    if(argc < 3)
    {
        fprintf(stderr,"Usage:%s filename op(+ or -)",argv[0]);
        exit(EXIT_FAILURE);
    }
    if(!(argv[2][0] == '+' || argv[2][0] == '-'))
    {
        fprintf(stderr,"Usage:%s filename op(+ or -),the op is not + or -,now op is %s",argv[0],argv[2]);
        exit(EXIT_FAILURE);
    }
    int key;
    int_arr whitelist;
    readInts(&whitelist,argv[1]);
    qsort(whitelist.data,whitelist.length,sizeof(int),intcompar);

    while(scanf("%d",&key) == 1)
    {
        if(argv[2][0] == '+')
        {
            if(rank(key,whitelist.data,whitelist.length) < 0)
                printf("%d\n",key);
        } else {
            if(rank(key,whitelist.data,whitelist.length) >= 0)
                printf("%d\n",key);
        }
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
