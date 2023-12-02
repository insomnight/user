/*
 * 1.1.36 乱序检查。通过实验检查表1.1.10中的乱序代码是否能够产生预期的效果。编写一个程序ShuffleTest，接受命令行参数M和N，将大小为M的数组打乱N次且在每次打乱之前都将数组重新初始化为a[i] = i。打印一个M×M的表格，对于所有的列j，行i表示的是i在打乱后落到j的位置的次数。数组中的所有元素的值都应该接近于N/M。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\lib\std_random.h"

void init_a(int a[],int n);

int main(int argc,char * argv[])
{
    if(argc < 3)
    {
        fprintf(stderr,"Usage: %s integerM integerN",argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int m,n;
    m = atoi(argv[1]);
    n = atoi(argv[2]);

    int result[m][m];
    int a[m];

    memset(result,0,sizeof(result));
    
    for(int i = 0; i < n; i++)
    {
        init_a(a,m);
        shuffleInts(a,m);
        for(int j = 0; j < m; j++)
            result[a[j]][j]++;
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%d ", result[i][j]);
        putchar('\n');
    }
    return 0;
}

void init_a(int a[],int n)
{
    for(int i = 0; i < n; i++)
        a[i] = i;
}
