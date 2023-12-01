#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/**
 * 向量点乘
 * param x[] 向量x数组,x与y长度必须相等
 * param y[] 向量x数组,x与y长度必须相等
 * param n 向量x与y的长度
 * return 返回矢量x和矢量y的內积
 */
double dot(double x[],double y[],int n)
{
    double result = 0.0;
    for(int i = 0; i < n; i++)
        result += x[i] * y[i];
    return result;
}

/**
 * 矩阵和矩阵之积
 * param arow 矩阵a的行数
 * param acol 矩阵a的列数
 * param a arow行,acol列的二维数组(代表矩阵)
 * param brow 矩阵b的行数
 * param bcol 矩阵b的列数
 * param b brow行,bcol列的二维数组(代表矩阵)
 * param result 提供存放结果的二维数组(代表矩阵),行等于arow,列等于bcol
 */
void mult(int arow,int acol,const double a[arow][acol],int brow,int bcol,const double b[brow][bcol],double result[arow][bcol])
{
    if(arow != bcol)
    {
        fprintf(stderr,"arow要等于brow,%d != %d",arow,bcol);
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < arow; i++)
        for(int j = 0; j < bcol; j++)
        {
            result[i][j] = 0.0;
            for(int k = 0; k < acol; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
}

/**
 * 转置矩阵
 * param arow 矩阵a的行数
 * param acol 矩阵a的列数
 * param a 要转置的矩阵a
 * param result 提供存放结果的二维数组(代表矩阵),行等于acol,列等于brow
 */
void transpose(int arow,int acol,const double a[arow][acol],double result[acol][arow])
{
    for(int i = 0; i < acol; i++)
        for(int j = 0; j < arow; j++)
            result[i][j] = a[j][i];
}

/**
 * 矩阵和向量之积
 * param arow 矩阵a的行数
 * param acol 矩阵a的列数
 * param a 矩阵a
 * param x 向量x,长度等于a的行数acol
 * param result 存放结果的向量,长度为arow;
 * return 返回指向相乘后结果一维数组的指针
 */
double * matr_vect_mult(int arow,int acol,const double a[arow][acol],const double * x,double * result)
{
    for(int i = 0; i < arow;i++)
    {
        result[i] = 0.0;
        for(int j = 0; j < acol; j++)
            result[i] += a[i][j] * x[j];
    }
    return result;
}

/**
 * 向量和矩阵之积
 * param arow 矩阵a的行数
 * param acol 矩阵a的列数
 * param y 向量y,长度等于a的列数acol
 * param a 矩阵a
 * param result 存放结果的向量,长度为acol;
 * return 返回指向相乘后结果一维数组的指针
 */
double * vect_matr_mult(int arow,int acol,const double * y,const double a[arow][acol],double * result)
{
    for(int i = 0; i < acol; i++)
    {
        result[i] = 0.0;
        for(int j = 0; j < arow; j++)
            result[i] += y[j] * a[j][i];
    }
    return result;
}

int main(void)
{
    double x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double y[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //测试x与y点乘
    double r1;
    r1 = dot(x,y,10);
    printf("r1 = %lf\n\n",r1);

    //测试a,b之积
    double a[3][10] = {
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        { 21, 22, 23, 24, 25, 26, 27, 28, 29, 210},
        { 31, 32, 33, 34, 35, 36, 37, 38, 39, 310}
    };
    double b[10][3] = {
        { 11, 21, 31 },
        { 12, 22, 32 },
        { 13, 23, 33 },
        { 14, 24, 34 },
        { 15, 25, 35 },
        { 16, 26, 36 },
        { 17, 27, 37 },
        { 18, 28, 38 },
        { 19, 29, 39 },
        { 10, 20, 30 }
    };
    double r2[3][3];
    mult(3,10,a,10,3,b,r2);
    for(int i = 0; i < 3;i++)
    {
        for(int j = 0; j < 3;j++)
            printf("%lf ",r2[i][j]);
        putchar('\n');
    }
    putchar('\n');

    //测试矩阵转置
    double r3[3][10];
    transpose(10,3,b,r3);
    for(int i = 0; i < 3;i++)
    {
        for(int j = 0; j < 10;j++)
            printf("%lf ",r3[i][j]);
        putchar('\n');
    }
    putchar('\n');

    //测试矩阵和向量之积
    double r4[3];
    matr_vect_mult(3,10,a,x,r4);
    for(int i = 0; i < 3; i++)
        printf("%lf ",r4[i]);
    putchar('\n');

    //测试向量和矩阵之积
    double r5[3];
    vect_matr_mult(10,3,y,b,r5);
    for(int i = 0; i < 3; i++)
        printf("%lf ",r5[i]);
    putchar('\n');

    return 0;
}

