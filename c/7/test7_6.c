/*
6．编写程序读取输入，读到#停止，报告ei出现的次数。
注意
该程序要记录前一个字符和当前字符。用“Receive your eieio award”这样的输入来测试。
*/
#include<stdio.h>
#define STOP '#'

int main(void)
{
    char pre_ch='#',cur_ch='#';
    int count = 0;
    while(pre_ch = cur_ch,(cur_ch=getchar())!=STOP)
        if(cur_ch =='i'&&pre_ch=='e')
            count++;
    printf("count=%d",count);
    return 0;
}

    
