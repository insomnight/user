/*
 * 9．编写一个程序，初始化一个double类型的3×5二维数组，使用一个处理变长数组的函数将其拷贝至另一个二维数组中。还要编写一个以变长数组为形参的函数以显示两个数组的内容。这两个函数应该能处理任意N×M数组（如果编译器不支持变长数组，就使用传统C函数处理N×5的数组）。
 */
#include<stdio.h>

void copy_arr(int rows,int cols,double source[rows][cols],double target[rows][cols]);
void print_arr(int rows,int cols,double arr[rows][cols]);

int main(void)
{
    double source[3][5] = {1.1,1.2,1.3,1.4,1.5,2.1,2.2,2.3,2.4,2.5,3.1,3.2,3.3,3.4,3.5};
    double target[3][5];

    printf("source:\n");
    print_arr(3,5,source);

    printf("target:\n");
    copy_arr(3,5,source,target);
    print_arr(3,5,target);
    return 0;
}

void copy_arr(int rows,int cols,double source[rows][cols],double target[rows][cols])
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            target[i][j] = source[i][j];
}

void print_arr(int rows,int cols,double arr[rows][cols])
{
    for(int i =0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            printf("%8.3f ",arr[i][j]);
        printf("\n");
    }
}
