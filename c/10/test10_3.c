/*
 * 3．编写一个函数，返回存储在int类型数组中的最大值，并在一个简单的程序中测试该函数。
 */
#include<stdio.h>
#define ARR_SIZE 5
int max(int arr[],int n);

int main(void)
{
    int arr[ARR_SIZE], i;

    i = 0;

    while(scanf("%d",&arr[i]) == 1)
    {    
        i++;
        if(i == ARR_SIZE)
            break;
    }

    for(i = 0; i < ARR_SIZE; i++)
        printf("%d ",arr[i]);

    printf("The max is %d.\n", max(arr,ARR_SIZE));

    return 0;
}

int max(int arr[],int n)
{
    int max=arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];

    return max;
}
