/*
15．编写一个程序，读取一行输入，然后把输入的内容倒序打印出来。
可以把输入存储在char类型的数组中，假设每行字符不超过255。回忆一下，
根据%c转换说明，scanf()函数一次只能从输入中读取一个字符，
而且在用户按下Enter键时scanf()函数会生成一个换行字符（\n）。
*/
#include<stdio.h>

#define MAX_SIZE 255

int main(void)
{
    char str[MAX_SIZE],ch;
    int i=0;
    while (scanf("%c",&ch))
    {
        str[i] = ch;
        if(ch == '\n')
            break;
        i++;
    }
    for (; i >= 0; i--)
    {
        printf("%c",str[i]);
    }
    return 0;
}