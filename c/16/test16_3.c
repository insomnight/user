/*
 * 3．极坐标用向量的模（即向量的长度）和向量相对x轴逆时针旋转的角度来描述该向量。直角坐标用向量的x轴和y轴的坐标来描述该向量（见图16.3）。编写一个程序，读取向量的模和角度（单位：度），然后显示x轴和y轴的坐标。相关方程如下：
 * 　　 x = r*cos A y = r*sin A
 * 需要一个函数来完成转换，该函数接受一个包含极坐标的结构，并返回一个包含直角坐标的结构（或返回指向该结构的指针）。
 */
#include "test16_1.h"

#define DEG_TO_RAD (4 * atan(1)/180)

typedef struct poloar_v {
    double magnitude;
    double angle;
} Polar_V;

typedef struct rect_v {
    double x;
    double y;
} Rect_V;

Rect_V polar_to_rect(Polar_V);

int main(void)
{
    Rect_V result;
    Polar_V input;

    puts("Enter magnitude and agnle polar coordinates; enter q to quit:");
    while(scanf("%lf%lf",&input.magnitude,&input.angle) == 2)
    {
        result = polar_to_rect(input);
        printf("x = %0.2f, y = %0.2f\n",result.x,result.y);
    }
    puts("Bye.");

    return 0;
}

Rect_V polar_to_rect(Polar_V p)
{
    Rect_V r;
    r.x = p.magnitude * cos(p.angle * DEG_TO_RAD);
    r.y = p.magnitude * sin(p.angle * DEG_TO_RAD);
    return r;
}
