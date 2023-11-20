/*
 * 7．编写一个程序，初始化一个double类型的二维数组，使用编程练习2中的一个拷贝函数把该数组中的数据拷贝至另一个二维数组中（因为二维数组是数组的数组，所以可以使用处理一维数组的拷贝函数来处理数组中的每个子数组）。
 */
#include<stdio.h>
#define ROWS 4
#define COLS 5

void copy_arr(double target[], double source[], int n);
void copy_ptr(double * target, double * source, int n);
void copy_ptrs(double * target,double * source_start, double * source_end);
void print_arr(double * target_start,double * target_end);

int main(void)
{
    double source[ROWS][COLS] = {{1,2,3,4,5},{1,4,2,5,5},{3,3,3,3,3},{6,6,1,2,3}};
    double target[ROWS][COLS];
    for(int i = 0; i < ROWS; i++)
        copy_arr(target[i],source[i],COLS);

    for(int i = 0; i < ROWS; i++)
        print_arr(target[i],target[i] + COLS);
    return 0;
}

void copy_arr(double target[], double source[], int n)
{
    for(int i = 0; i < n; i++)
        target[i] = source[i];
}

void copy_ptr(double * target, double * source, int n)
{
    for(int i = 0; i< n; i++)
        *(target + i) = *(source +i);
}

void copy_ptrs(double * target, double * source_start, double * source_end)
{
    while(source_start < source_end)
    {
        * target = * source_start;
        target++;
        source_start++;
    }
}

void print_arr(double * target_start,double * target_end)
{
    while(target_start < target_end)
    {
        printf("%f ",* target_start);
        target_start++;
    }
    printf("\n");
}
