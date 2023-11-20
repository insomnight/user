/*
 * 7．编写一个函数，从标准输入中读取字符，直到遇到文件结尾。程序要报告每个字符是否是字母。如果是，还要报告该字母在字母表中的数值位置。例如，c和C在字母表中的位置都是3。合并一个函数，以一个字符作为参数，如果该字符是一个字母则返回一个数值位置，否则返回-1。
 */
#include<stdio.h>
#include<ctype.h>

int num_of_alpha(char);

int main(void)
{
    char ch;
    while((ch = getchar()) != EOF)
        if( num_of_alpha(ch) == -1)
            printf("%c is not a alpha.\n",ch);
        else
            printf("%c is in the %d position of the alphabet.\n",ch,num_of_alpha(ch));
    return 0;
}

int num_of_alpha(char ch)
{
    return isalpha(ch) ? (tolower(ch) - 'a') + 1 : -1;
}
