/*
 * 6．编写一个函数接受3个参数：一个数组名（内含已排序的整数）、该数组的元素个数和待查找的整数。如果待查找的整数在数组中，那么该函数返回1；如果该数不在数组中，该函数则返回0。用二分查找法实现。
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 9999

int initdata(int list[],int n);
int findN(const int list[],int size,int n);

int main(void)
{
    int arr[MAXSIZE],n,result;
    initdata(arr,MAXSIZE);
    while(scanf("%d",&n))
    {
       result = findN(arr,MAXSIZE,n);
       printf("%d is %s arr\n",n,result ? "in" : "not in");
    }
    return 0;
}

int initdata(int list[],int n)
{
    for(int i=0;i < n;i++)
        list[i] = i;
}

int findN(const int list[],int size,int n)
{
    int mid,flag = 0;
    int start = 0;
    int end = size - 1;
    while(end > start)
    {
       mid = ( start + end ) / 2;
       if(list[mid] == n)
       {
           flag = 1;
           break;
       }
       if(list[mid] > n)
           end = mid -1;
       else 
           start = mid +1;
    }
    return flag;
}
