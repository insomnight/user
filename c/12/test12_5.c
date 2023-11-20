/*
 * 5．编写一个程序，生成100个1～10范围内的随机数，并以降序排列（可以把第11章的排序算法稍加改动，便可用于整数排序，这里仅对整数排序）。
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 100

void sortint(int * arr, int size);
void print_arr(int * arr, int size);

int main(void)
{
    int arr[SIZE];
    
    srand((unsigned int) time(0));
    for(int i = 0; i < SIZE; i++)
        arr[i] = rand() % 10 + 1;

    puts("before sort:");
    print_arr(arr,SIZE);

    sortint(arr,SIZE);

    puts("after sort:");
    print_arr(arr,SIZE);

    return 0;
}


void sortint(int * arr, int size)
{
    int temp;
    for(int top = 0; top < size - 1; top++)
        for(int seek = top + 1; seek < size; seek++)
            if(arr[top] < arr[seek])
            {
                temp = arr[top];
                arr[top] = arr[seek];
                arr[seek] = temp;
            }
}

void print_arr(int * arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%3d%c",arr[i], (size + 1) % 10 ? ' ' : '\n');
    putchar('\n');
}


