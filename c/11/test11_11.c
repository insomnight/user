/*
 * 11．编写一个程序，读入10个字符串或者读到EOF时停止。该程序为用户提供一个有5个选项的菜单：打印源字符串列表、以ASCII中的顺序打印字符串、按长度递增顺序打印字符串、按字符串中第1个单词的长度打印字符串、退出。菜单可以循环显示，除非用户选择退出选项。当然，该程序要能真正完成菜单中各选项的功能。
 */
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define LIM 10
#define SIZE 100
char menu(void);
char get_first(void);
void print_source_arr(char *arr[],int n);
void print_sort_ascii(char *arr[],int n);
void print_sort_length(char *arr[],int n);
void print_sort_first_word_len(char *arr[],int n);
char * s_get_s(char * st, int n);
int strfirstlen(char * st);

int main(void)
{
    char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct = 0;
    char cho;

    printf("Input ip to %d lines,and I will save them.\n",LIM);
    printf("To stop, press the Enter key at a line's start.\n");
    while(ct < LIM && s_get_s(input[ct], SIZE) != NULL && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }

    while((cho = menu()) != 'q')
    {
        switch(cho)
        {
            case 'a': print_source_arr(ptstr,ct);
                      break;
            case 's': print_sort_ascii(ptstr,ct);
                      break;
            case 'd': print_sort_length(ptstr,ct);
                      break;
            case 'f': print_sort_first_word_len(ptstr,ct);
                      break;
            default:  break;
        }
    }
    return 0;
}

char menu(void)
{
    char ch;
    printf("Enter the operation of your choice:\n");
    printf("a. print the source           s. print sort by ascii\n");
    printf("d. print sort by length       f. print sort by first word's length\n");
    printf("q. quit\n");

    ch = get_first();
    while(ch != 'a' && ch != 's' && ch != 'd' && ch != 'f' && ch != 'q')
    {
        printf("Please respond with a,s,m,d or q.\n");
        ch = getchar();
    }

    return ch;
}

char get_first(void)
{
    char ch;

    while(isspace(ch = getchar()))
        continue; 
    while(!isspace(getchar()))
        continue;
    return ch; 
}

void print_source_arr(char *arr[],int n)
{
    for(int i = 0; i < n; i++)
        puts(arr[i]);
}

void print_sort_ascii(char *arr[],int n)
{
    char *sort[n],*temp;
    for(int i = 0; i < n; i++)
        sort[i] = arr[i];
    for(int top = 0; top < n - 1 ; top++)
        for(int seek = top + 1; seek < n; seek++)
            if(strcmp(sort[top],sort[seek]) > 0)
            {
                temp = sort[top];
                sort[top] = sort[seek];
                sort[seek] = temp;
            }
    puts("\nHere's the sorted list:\n");
    for(int i = 0; i < n; i++)
        puts(sort[i]);
}

void print_sort_length(char *arr[],int n)
{
    char *sort[n],*temp;
    for(int i = 0; i < n; i++)
        sort[i] = arr[i];
    for(int top = 0; top < n - 1 ; top++)
        for(int seek = top + 1; seek < n; seek++)
            if( strlen(sort[top]) > strlen(sort[seek]) )
            {
                temp = sort[top];
                sort[top] = sort[seek];
                sort[seek] = temp;
            }
    puts("\nHere's the sorted list:\n");
    for(int i = 0; i < n; i++)
        puts(sort[i]);
}

void print_sort_first_word_len(char *arr[],int n)
{
    char *sort[n],*temp;
    for(int i = 0; i < n; i++)
        sort[i] = arr[i];
    for(int top = 0; top < n - 1 ; top++)
        for(int seek = top + 1; seek < n; seek++)
            if( strfirstlen(sort[top]) > strfirstlen(sort[seek]) )
            {
                temp = sort[top];
                sort[top] = sort[seek];
                sort[seek] = temp;
            }
    puts("\nHere's the sorted list:\n");
    for(int i = 0; i < n; i++)
        puts(sort[i]);
}

char * s_get_s(char * st, int n)
{
    char * ret_val;
    int i = 0;
    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        while(st[i] != '\n' && st[i] != '\0')
            i++;
        if(st[i] == '\n')
            st[i] = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

int strfirstlen(char * st)
{
    int in_word = 0;
    int count = 0;
    while(*st)
    {
       
       if(!in_word && isspace(*st))
       {
           st++;
           continue;
       }
       if(in_word && isspace(*st))
       {
           st++;
           break;
       }
       if(!in_word && !isspace(*st))
           in_word++;
       st++;
       count++;
    }
    return count;
}
