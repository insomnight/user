/*
 * 4．ANSI库这样描述clock()函数的特性：
 * #include <time.h>
 * clock_t clock (void);
 * 这里，clock_t是定义在time.h中的类型。该函数返回处理器时间，其单位取决于实现（如果处理器时间不可用或无法表示，该函数将返回-1）。然而，CLOCKS_PER_SEC（也定义在time.h中）是每秒处理器时间单位的数量。因此，两个clock()返回值的差值除以CLOCKS_PER_SEC得到两次调用之间经过的秒数。在进行除法运算之前，把值的类型强制转换成double类型，可以将时间精确到小数点以后。编写一个函数，接受一个double类型的参数表示时间延迟数，然后在这段时间运行一个循环。编写一个简单的程序测试该函数。
 */
#include <stdio.h>
#include <time.h>

void sleep_time(double time);

int main(void)
{
    double t;
    time_t curtime;
    while(scanf("%lf",&t) == 1)
    {
        time(&curtime);
        printf("sleep start %s",ctime(&curtime));
        sleep_time(t);
        time(&curtime);
        printf("sleep start %s",ctime(&curtime));
    }
    return 0;
}

void sleep_time(double time)
{
    double start;
    double end;
    double cost;
    start = (double) clock();
    end = (double) clock();
    while((end - start)/CLOCKS_PER_SEC < time)
        end = clock();
}

