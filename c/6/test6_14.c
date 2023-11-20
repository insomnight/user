/*
14．编写一个程序，创建两个包含8个元素的double类型数组，
使用循环提示用户为第一个数组输入8个值。
第二个数组元素的值设置为第一个数组对应元素的累积之和。
例如，第二个数组的第4个元素的值是第一个数组前4个元素之和，
第二个数组的第5个元素的值是第一个数组前5个元素之和（用嵌套循环可以完成，
但是利用第二个数组的第5个元素是第二个数组的第4个元素与第一个数组的第5个元素之和，
只用一个循环就能完成任务，不需要使用嵌套循环）。最后，
使用循环显示两个数组的内容，第一个数组显示成一行，
第二个数组显示在第一个数组的下一行，而且每个元素都与第一个数组各元素相对应。
*/
#include<stdio.h>
#define ARR_SIZE 8

int main(void)
{
    double arr1[ARR_SIZE],arr2[ARR_SIZE];
    double sum = 0.0;
    for (size_t i = 0; i < ARR_SIZE; i++)
    {
        scanf("%lf",&arr1[i]);
        sum +=arr1[i];
        arr2[i] = sum;
    }
    
    for (size_t i = 0; i < ARR_SIZE; i++)
    {
        printf("%6.2f",arr1[i]);
    }
    printf("\n");
    for (size_t i = 0; i < ARR_SIZE; i++)
    {
        printf("%6.2f",arr2[i]);
    }
    return 0;
}