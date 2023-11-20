/*
 * 3．设计并测试一个函数，从一行输入中把一个单词读入一个数组中，并丢弃输入行中的其余字符。该函数应该跳过第1个非空白字符前面的所有空白。将一个单词定义为没有空白、制表符或换行符的字符序列。
 */
#include<stdio.h>
#include<ctype.h>

char * getword(char * w);

int main(void)
{
    char word[100];
    while(getword(word))
    {
        puts(word);
    }
    return 0;
}

char * getword(char * w)
{
    int in_word = 0,i = 0;
    while((w[i] = getchar()) != EOF)
    {
        if(in_word)
        {
            if(isspace(w[i]))
            {
                in_word = 0;
                if(w[i] != '\n')
                    while(getchar()!='\n')
                        continue;
                break;
            }else
            {
                i++;
            }
        }else
        {
            if(isspace(w[i]))
                continue;
            else
            {
                in_word = 1;
                i++;
            }
        }
    }
    w[i] = '\0';
    return w;
}
