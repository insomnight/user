/*
 * 4．编写一个函数，返回存储在double类型数组中最大值的下标，并在一个简单的程序中测试该函数。 
 */
#include<stdio.h>
#define ARR_SIZE 5
int max_index(double arr[],int n);

int main(void)
{
    double arr[ARR_SIZE];

    int i = 0;

    while(scanf("%lf",&arr[i]) == 1)
    {    
        i++;
        if(i == ARR_SIZE)
            break;
    }

    for(i = 0; i < ARR_SIZE; i++)
        printf("%lf ",arr[i]);

    printf("The max_index is %d.\n", max_index(arr,ARR_SIZE));

    return 0;
}

int max_index(double arr[],int n)
{
    int max_index = 0;
    for(int i = 1; i < n; i++)
        if(arr[i] > arr[max_index])
            max_index = i;

    return max_index;
}
