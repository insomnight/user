/*
 * 4．在一个循环中编写并测试一个函数，该函数返回它被调用的次数。
 */
#include<stdio.h>

int call_count(void);

int main(void)
{
    int count;
    while(getchar()!=EOF) {
        count = call_count();
        printf("%d.\n",count);
    }
    puts("done!\n");
    printf("call time is %d\n",count);
    return 0;
}

int call_count(void)
{
    static int count = 0;
    count ++;
    return count;
}
