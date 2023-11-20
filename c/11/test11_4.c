/*
 *  4．设计并测试一个函数，它类似编程练习3的描述，只不过它接受第2个参数指明可读取的最大字符数。
 */
#include<stdio.h>
#include<ctype.h>

char * getword(char * w, int n);

int main(void)
{
    char word[100];
    while(getword(word, 5))
    {
        puts(word);
    }
    return 0;
}

char * getword(char * w,int n)
{
    int in_word = 0,i = 0;
    while((w[i] = getchar()) != EOF && i < n)
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
