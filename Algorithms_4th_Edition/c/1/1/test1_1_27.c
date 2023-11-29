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

int main(void)
{
    double result;
    result = binomial(100, 50, 0.25);
    printf("binomial(100, 50, 0.25) = %lf\n",result);
    return 0;
}

double binomial(int n, int k, double p)
{
    printf("n = %d, k = %d, p = %lf, blarr[%d][%d] = %lf\n",n,k,p,n,k,blarr[n + 1][k + 1]);
    if(n == 0 && k == 0) return 1.0;
    if(n < 0 || k < 0) return 0.0;
    if(blarr[n + 1][k + 1] != 0.0) return blarr[n + 1][k + 1] - 1;
    blarr[n + 1][k + 1] = (1.0 - p) * binomial(n - 1,k,p) + p * binomial(n - 1, k - 1, p);
    blarr[n + 1][k + 1] += 1;
    return blarr[n + 1][k + 1] - 1;
}
