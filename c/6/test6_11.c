/*
11．编写一个程序，在数组中读入8个整数，然后按倒序打印这8个整数。
*/
#include<stdio.h>
#define ARR_SIZE 8
int main(void)
{
    int arr[ARR_SIZE];
    for (size_t i = 0; i < ARR_SIZE; i++)
        scanf("%d",&arr[i]);
    for (int i = ARR_SIZE - 1; i >= 0; i--)
        printf("%d ",arr[i]);    
    return 0;
}