/*
 * 2．编写一个程序，初始化一个double类型的数组，然后把该数组的内容拷贝至3个其他数组中（在main()中声明这4个数组）。使用带数组表示法的函数进行第1份拷贝。使用带指针表示法和指针递增的函数进行第2份拷贝。把目标数组名、源数组名和待拷贝的元素个数作为前两个函数的参数。第3个函数以目标数组名、源数组名和指向源数组最后一个元素后面的元素的指针。也就是说，给定以下声明，则函数调用如下所示：
 */
#include<stdio.h>

void copy_arr(double target[], double source[], int n);
void copy_ptr(double * target, double * source, int n);
void copy_ptrs(double * target,double * source_start, double * source_end);
void print_arr(double * target_start,double * target_end);

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);

    copy_ptrs(target3, source, source + 5);

    printf("source:\n");
    print_arr(source,source + 5);

    printf("target1:\n");
    print_arr(target1,target1 + 5);
    printf("target2:\n");
    print_arr(target2,target2 + 5);
    printf("target3:\n");
    print_arr(target3,target3 + 5);
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
