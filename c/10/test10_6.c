/*
 * 6．编写一个函数，把double类型数组中的数据倒序排列，并在一个简单的程序中测试该函数。
 */
#include<stdio.h>
#define ARR_SIZE 5
void reverse(double arr[],int n);

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

    printf("before reverse:\n");
    for(i = 0; i < ARR_SIZE; i++)
        printf("%lf ",arr[i]);
    printf("\n");

    reverse(arr,ARR_SIZE);
    printf("after reverse:\n");
    
    for(i = 0; i < ARR_SIZE; i++)
        printf("%lf ",arr[i]);
    printf("\n");

    return 0;
}

void reverse(double arr[],int n)
{
    double temp;
    for(int i = 0, j = n-1; i  < j; i++,j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

