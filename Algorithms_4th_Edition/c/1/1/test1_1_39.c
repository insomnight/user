/*
 * 1.1.39 随机匹配。编写一个使用BinarySearch的程序，它从命令行接受一个整型参数T，并会分别针对N=10e3、10e4、10e5和10e6将以下实验运行T遍：生成两个大小为N的随机6位正整数数组并找出同时存在于两个数组中的整数的数量。打印一个表格，对于每个N，给出T次实验中该数量的平均值。
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3

void initArrRand(int a[],int n);
int rank(int key, int * a,int length);
int intcompar(const void * a,const void *b);

int main(int argc,char * argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage: %s timer\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int * a, * b;
    int testsize[SIZE] = { 1000,10000,100000};
    double total;
    int t,find;
    t = atoi(argv[1]);
    srand((unsigned int) time(0));

    for(int i = 0; i < SIZE; i++)
    {
        a = malloc( testsize[i] * sizeof(int) );
        b = malloc( testsize[i] * sizeof(int) );
        total = 0.0;

        for(int j = 0; j < t; j++)
        {
            initArrRand(a, testsize[i]);
            initArrRand(b, testsize[i]);
            qsort(a, testsize[i], sizeof(int), intcompar);

            for(int k = 0; k < testsize[i]; k++)
            {
                find = rank(b[k], a, testsize[i]);
                if(find != -1)
                    total += 1.0;
            }
        }
        
        printf("n = %d,average = %0.3lf\n",testsize[i], total / t);
        free(a);
        free(b);
    }

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

void initArrRand(int a[],int n)
{
    for(int i = 0; i < n; i++)
        a[i] = 100000 + rand() % 900000;
}
