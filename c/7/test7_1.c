/*
1．编写一个程序读取输入，读到#字符停止，
然后报告读取的空格数、换行符数和所有其他字符的数量。
*/
#include <stdio.h>
#include <ctype.h>
#define STOP '#'
int main(void)
{
    char ch;
    int n_spaces = 0; // 空格数
    int n_lines = 0;  // 换行符数
    int n_others = 0; // 其他字符数
    while ((ch = getchar()) != STOP)
    {
        switch (ch)
        {
        case ' ':
            n_spaces++;
            break;
        case '\n':
            n_lines++;
            break;
        default:
            n_others++;
            break;
        }
    }
    printf("spaces = %d,lines = %d,others = %d", n_spaces, n_lines, n_others);
    return 0;
}