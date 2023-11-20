/*
 * 1．修改程序清单17.2，让该程序既能正序也能逆序显示电影列表。一种方法是修改链表的定义，可以双向遍历链表。另一种方法是用递归。
 */
#include <stdio.h>
#include <stdlib.h>        /* 提供malloc()原型 */
#include <string.h>        /* 提供strcpy()原型 */
#define TSIZE    45        /* 存储片名的数组大小 */

struct film {
    char title[TSIZE];
    int rating;
    struct film * next;    /* 指向链表中的下一个结构 */
    struct film * prev;    /* 指向链表中的上一个结构 */
};
char * s_gets(char * st, int n);

int main(void)
{
    struct film * head = NULL;
    struct film * end = NULL;
    struct film * prev, *current;
    char input[TSIZE];

/* 收集并存储信息 */
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL)       /* 第1个结构 */
        {
            head = current;
            current -> prev = NULL;
        }
        else                    /* 后续的结构 */
        {
            prev->next = current;
            current->prev = prev;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
        end = current;
    }

    /* 显示电影列表 */
    if (head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s  Rating: %d\n",
            current->title, current->rating);
        current = current->next;
    }

    /* 倒序显示电影列表 */
    if(end == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie revesert list:\n");
    current = end;
    while(current != NULL)
    {
        printf("Movie: %s  Rating: %d\n",
            current->title, current->rating);
        current = current->prev;
    }

    /* 完成任务，释放已分配的内存 */
    current = head;
    while (current != NULL)
    {
        head = current->next;
        free(current);        
        current = head;
    }
    printf("Bye!\n");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');    // 查找换行符
        if (find)                   // 如果地址不是 NULL，
            *find = '\0';          // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;         // 处理剩余输入行
    }
    return ret_val;
}
