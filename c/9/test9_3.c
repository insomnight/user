/*
 * 3．编写一个函数，接受3个参数：一个字符和两个整数。字符参数是待打印的字符，第1个整数指定一行中打印字符的次数，第2个整数指定打印指定字符的行数。编写一个调用该函数的程序。
 */
#include<stdio.h>

void display(char,int,int);

int main(void)
{
    char ch;
    int col,row;
    scanf("%c%d%d",&ch,&row,&col);
    display(ch,col,row);
    return 0;
}

void display(char ch,int column,int row)
{
    for(int i = 0 ; i < row; i++)
    {
        for(int j = 0 ; j < column; j++)
            putchar(ch);
        putchar('\n');
    }
}
