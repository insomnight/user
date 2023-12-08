/**
 * 1.2.2 编写一个Interval1D的用例，从命令行接受一个整数N。从标准输入中读取N个间隔（每个间隔由一对double值定义）并打印出所有相交的间隔对。
 */
#include <stdio.h>
#include <stdlib.h>
#include "..\..\lib\interval1D.h"

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage: %s integer(n)\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    double x,y;
    char str[100];
    Interval1D lis[n];
    for(int i = 0; i < n; i++)
    {
        while(!scanf("%lf%lf",&x,&y) == 2)
            continue;
        initInterval1D(&lis[i],x > y ? y : x,x > y ? x : y);
        if(i > 0)
            for(int j = 0; j < i; j++)
                if(intersects(&lis[j],&lis[i]))
                {
                    interval1DtoString(&lis[j],str,100);
                    printf("%s intersects ",str);
                    interval1DtoString(&lis[i],str,100);
                    printf("%s\n",str);
                }
    }
    return 0;
}

