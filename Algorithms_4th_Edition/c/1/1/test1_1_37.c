/*
 * 1.1.37 糟糕的打乱。假设在我们的乱序代码中你选择的是一个0到N-1而非i到N-1之间的随机整数。证明得到的结果并非均匀地分布在N！种可能性之间。用上一题中的测试检验这个版本。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void init_a(int a[],int n);
void shuffle(int a[],int n);

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
    
    srand((unsigned int) time(0));
    for(int i = 0; i < n; i++)
    {
        init_a(a,m);
        shuffle(a,m);
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

void shuffle(int a[],int n)
{
    int r;
    int temp;
    for(int i = 0; i < n; i++)
    {
        r = rand() % n;
        temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}
