/*
   5．使用switch重写练习4。
*/
#include<stdio.h>
#define STOP '#'

int main(void)
{
    char ch;
    int replace_times = 0;
    while((ch=getchar())!=STOP)
        switch(ch)
        {
            case '.':
            case '!':
                replace_times++;
            default :
                break;
        }
    printf("A total of %d replacements were made",replace_times);
    return 0;
}
