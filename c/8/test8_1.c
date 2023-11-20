/*
 1．设计一个程序，统计在读到文件结尾之前读取的字符数。
*/
#include<stdio.h>

int main(void)
{
    int count=0;
    while(getchar()!=EOF)
        count++;
    printf("This file has %d characters",count);
    return 0;
}
