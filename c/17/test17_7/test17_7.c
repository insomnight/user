/*
 * 7．编写一个程序，打开和读取一个文本文件，并统计文件中每个单词出现的次数。用改进的二叉查找树存储单词及其出现的次数。程序在读入文件后，会提供一个有3个选项的菜单。第1个选项是列出所有的单词和出现的次数。第2个选项是让用户输入一个单词，程序报告该单词在文件中出现的次数。第3个选项是退出。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void showwords(const Tree * pt);
void findword(const Tree *pt);
void printtitem(Item item);
char * s_gets(char *st,int n);

int main(void)
{
    FILE * fp;
    Item temp;
    char choice;
    Tree words;

    InitializeTree(&words);

    if((fp = fopen("data","r"))==NULL)
    {
        fprintf(stderr,"The file data can't open");
        exit(EXIT_FAILURE);
    }

    while(fscanf(fp,"%s",temp.word) == 1 && temp.word[0] != '\0') 
    {
        if(TreeIsFull(&words))
            puts("The Tree is Full");
        else
            AddItem(&temp,&words);
    }

    while((choice = menu())!='q')
    {
        switch (choice)
        {
            case 'a': showwords(&words);
                break;
            case 'b': findword(&words);
                break;
            default:
                break;
        }
    }
    return 0;
}

char menu(void)
{
    int ch;

    puts("File word total Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) show list of word   b)find word");
    puts("q) quit");
    while((ch = getchar()) != EOF)
    {
        while(getchar()!='\n')
            continue;
        ch = tolower(ch);
        if(strchr("abq",ch) == NULL)
            puts("Please enter an a, b, or q:");
        else
            break;
    }
    if(ch == EOF)
        ch = 'q';

    return ch;
}

void showwords(const Tree * pt)
{
    if(TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt,printtitem);
}

void printtitem(Item item)
{
    printf("Word: %-19s Count: %-19d\n",item.word,item.count);
}

void findword(const Tree *pt)
{
    Item temp;
    Trnode * find;

    if(TreeIsEmpty(pt))
    {
        puts("No enteries!");
        return ;
    }

    puts("Please enter a word youw wish to find:");
    s_gets(temp.word,SLEN);
    printf("The %s ",temp.word);
    if((find = InTree(&temp,pt))!=NULL)
        printf("is a member.The count is %d\n",find->item.count);
    else
        printf("is not a memver.\n");
}

char * s_gets(char *st,int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
            *find = '\0';
        else
            while(getchar()!= '\n')
                continue;
    }
    return ret_val;
}
