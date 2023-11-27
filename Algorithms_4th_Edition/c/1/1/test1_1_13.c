/*
 * 1.1.13 编写一段代码，打印出一个M行N列的二维数组的转置（交换行和列)
 */
#include <stdio.h>

#define ROW 3
#define COL 9

void printreverse(int row,int col,int arr[row][col]);

int main(void)
{
    int arr[ROW][COL];

    for(int i = 0;i < ROW; i++)
        for(int j = 0; j < COL; j++)
            arr[i][j] = (i + 1) * 10 + j;

    printreverse(ROW,COL,arr);
    return 0;
}

void printreverse(int row,int col,int arr[row][col])
{
    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
            printf("%d ",arr[j][i]);
        putchar('\n');
    }
}
