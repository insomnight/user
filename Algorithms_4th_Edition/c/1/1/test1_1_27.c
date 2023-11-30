/*
 * 1.1.27 二项分布。估计用以下代码计算binomial(100, 50, 0.25)将会产生的递归调用次数：
 * public static double binomial(int N, int k, double p)
 * {
 *     if (N == 0 && k == 0) return 1.0;
 *         if (N ＜ 0 || k ＜ 0) return 0.0;
 *             return (1.0- p)＊binomial(N-1, k, p) + p＊binomial(N-1, k-1, p);
 *             }
 * 将已经计算过的值保存在数组中并给出一个更好的实现。
 */
#include <stdio.h>

double blarr[200][200] = {0.0};

double binomial(int n, int k, double p);
double binomial1(int n, int k, double p);

int main(void)
{
    double result,p;
    int n,k;
    while(scanf("%d%d%lf",&n,&k,&p) == 3)
    {
        result = binomial(n, k, p);
        printf("binomial(%d, %d, %lf) = %lf\n",n,k,p,result);
        result = binomial1(n, k, p);
        printf("binomial1(%d, %d, %lf) = %lf\n",n,k,p,result);
    }
    return 0;
}

double binomial(int n, int k, double p)
{
    if(n == 0 && k == 0) return 1.0;
    if(n < 0 || k < 0) return 0.0;
    if(blarr[n + 1][k + 1] != 0.0) return blarr[n + 1][k + 1] - 1;
    blarr[n + 1][k + 1] = (1.0 - p) * binomial(n - 1,k,p) + p * binomial(n - 1, k - 1, p) + 1;
    return blarr[n + 1][k + 1] - 1;
}

double binomial1(int n, int k, double p)
{
    if(n == 0 && k == 0) return 1.0;
    if(n < 0 || k < 0) return 0.0;
    return (1.0 - p) * binomial(n - 1,k,p) + p * binomial(n - 1, k - 1, p);
 
}
