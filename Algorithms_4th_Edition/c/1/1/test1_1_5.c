/*
 * 1.1.5 编写一段程序，如果double类型的变量x和y都严格位于0和1之间则打印true，否则打印false
 */
#include <stdio.h>

void judgexy(double x,double y);

int main(void)
{
    double x,y;
    while(scanf("%lf%lf",&x,&y) == 2)
        judgexy(x,y);
    return 0;
}

void judgexy(double x,double y)
{
    if(x>=0 && x<=1 && y>=0 && y<=1)
        puts("true");
    else
        puts("false");
}
