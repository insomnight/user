/*
 * 2．两数的调和平均数这样计算：先得到两数的倒数，然后计算两个倒数的平均值，最后取计算结果的倒数。使用#define指令定义一个宏“函数”，执行该运算。编写一个简单的程序测试该宏。
 */
#include "test16_1.h"

#define HARMONIC_MEAN(X,Y) ( 2 * (X) * (Y) / ( (X) + (Y) ) )

int main(void)
{
    double x,y,result;
    while(scanf("%lf%lf",&x,&y) == 2)
    {
        result = HARMONIC_MEAN(x,y);
        printf("%lf and %lf marmonic mean is %lf\n",x,y,result);
    }
    return 0;
}
