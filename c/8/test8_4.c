/*
4．编写一个程序，在遇到EOF之前，把输入作为字符流读取。该程序要报告平均每个单词的字母数。不要把空白统计为单词的字母。实际上，标点符号也不应该统计，但是现在暂时不同考虑这么多（如果你比较在意这点，考虑使用ctype.h系列中的ispunct()函数）。
*/
#include<stdio.h>
#include<ctype.h>

int main(void)
{
    int word_num = 0;
    char word[300];
    char ch;
    while((ch = getchar())!=EOF)
    {
        if(isalpha(ch))
        {
            word[word_num] = ch;
            word_num++;
            continue;
        }
        if(!isalpha(ch) && word_num > 0)
        {
            for(int i = 0;i < word_num;i++)
                printf("%c",word[i]);
            printf(" has %d letters.\n", word_num);
            word_num = 0;
        }
    }
    return 0;
}
