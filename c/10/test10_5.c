/*
 * 5．编写一个函数，返回存储在double类型数组中最大值和最小值的差值，并在一个简单的程序中测试该函数。
 */
#include<stdio.h>
#define ARR_SIZE 5
double diff(double arr[],int n);

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

    printf("The diff is %lf.\n", diff(arr,ARR_SIZE));

    return 0;
}

double diff(double arr[],int n)
{
    double max = arr[0];
    double min = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
        else
            min = arr[i];

    return max - min;
}
