/*
 * 12．编写一个程序，读取输入，直至读到EOF，报告读入的单词数、大写字母数、小写字母数、标点符号数和数字字符数。使用ctype.h头文件中的函数。
 */
#include<stdio.h>
#include<ctype.h>

int main(void)
{
    int word = 0;
    int upper = 0;
    int lower = 0;
    int punct = 0;
    int digit = 0;
    int in_word = 0;
    char ch;

    while((ch = getchar()) != EOF)
    {
        if(isupper(ch))
            upper++;
        if(islower(ch))
            lower++;
        if(isdigit(ch))
            digit++;
        if(ispunct(ch))
            punct++;
        
        if(!in_word)
        {
            if(isspace(ch))
                continue;
            else
                in_word = 1;
        }else
        {
            if(isspace(ch))
            {
                in_word = 0;
                word++;
            }
        }
    }

    printf("upper = %d.\n",upper);
    printf("lower = %d.\n",lower);
    printf("digit = %d.\n",digit);
    printf("punct = %d.\n",punct);
    printf("word = %d.\n",word);
    return 0;
}
