/*
3．编写一个程序，在遇到EOF之前，把输入作为字符流读取。该程序要报告输入中的大写字母和小写字母的个数。假设大小写字母数值是连续的。或者使用ctype.h库中合适的分类函数更方便。 
*/
#include<stdio.h>
#include<ctype.h>

int main(void)
{
    int upperNum = 0 , lowerNum = 0;
    char ch;
    while((ch = getchar())!=EOF)
        if(islower(ch))
            lowerNum++;
        else if(isupper(ch))
            upperNum++;
    printf("uppper num is %d , lower num is %d.\n",upperNum,lowerNum);
    return 0;
}
