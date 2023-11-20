/*
1．编写一个程序，把用分钟表示的时间转换成用小时和分钟表示的时间。
使用#define或const创建一个表示60的符号常量或const变量。
通过while循环让用户重复输入值，直到用户输入小于或等于0的值才停止循环。
*/
#include <stdio.h>
#define MIN_PER_HOUR 60            // 一小时60分钟
int main(void)
{
     int hour, min, left;

     printf("Convert minutes to hours and minutes!\n");
     printf("Enter the number of minutes (<=0 to quit):\n");
     scanf("%d", &min);            // 读取分钟数
     while (min > 0)
     {
          hour = min / MIN_PER_HOUR;    // 截断小时数
          left = min % MIN_PER_HOUR;   // 剩下的分钟数
          printf("%d minutes is %d hours, %d minutes.\n", min,
                   hour , left);
          printf("Enter next value (<=0 to quit):\n");
          scanf("%d", &min);
     }
     printf("Done!\n");

     return 0;
}