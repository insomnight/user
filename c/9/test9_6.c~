/*
 * 6．编写并测试一个函数，该函数以3个double变量的地址作为参数，把最小值放入第1个变量，中间值放入第2个变量，最大值放入第3个变量。
 */
#include<stdio.h>

void sort(double *,double *,double *);

int main(void)
{
    double x,y,z;
    scanf("%lf%lf%lf",&x,&y,&z);
    printf("before:x=%f,y=%f,z=%f.\n",x,y,z);
    sort(&x,&y,&z);
    printf("after:x=%f,y=%f,z=%f.\n",x,y,z);
    return 0;
}

void sort(double * px, double * py, double * pz)
{
    double temp;
    if(*px > *py)
    {
        temp = *px;
        *px = *py;
        *py = temp;
    }
    
    if(*py > *pz)
    {
        temp = *py;
        *py = *pz;
        *pz = temp;
    }

    if(*px > *py)
    {
        temp = *px;
        *px = *py;
        *py = temp;
    }
    
 
    
}

