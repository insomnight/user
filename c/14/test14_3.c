/*
 * 3．修改程序清单14.2中的图书目录程序，使其按照输入图书的顺序输出图书的信息，然后按照书名的字母顺序输出图书的信息，最后按照价格的升序输出图书的信息。
 */
#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);
#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100         /* 书籍的最大数量  */

struct book {                /* 建立 book 模板     */
     char title[MAXTITL];
     char author[MAXAUTL];
     float value;
};

void sort(struct book **base,int nitems,int (*compar)(const struct book *,const struct book *));
int compar_title(const struct book * a,const struct book *b);
int compar_price(const struct book * a,const struct book *b);

int main(void)
{
    struct book library[MAXBKS];    /*  book 类型结构的数组 */
    struct book *p_library[MAXBKS];   /*  book 类型结构指针的数组 */
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
        && library[count].title[0] != '\0')
    {
        p_library[count] = &library[count];
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;        /* 清理输入行*/
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                    library[index].author, library[index].value);

        printf("After sort by title, your books:\n");
        sort(p_library,count,compar_title);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", p_library[index]->title,
                    p_library[index]->author, p_library[index]->value);

        printf("After sort by price, your books:\n");
        sort(p_library,count,compar_price);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", p_library[index]->title,
                    p_library[index]->author, p_library[index]->value);
    }
    else
        printf("No books? Too bad.\n");

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
                continue;         // 处理输入行中剩余的字符
    }
    return ret_val;
}

void sort(struct book **base,int nitems,int (*compar)(const struct book *,const struct book *))
{
    int i,j;
    struct book *temp;

    for(i = 0; i < nitems -1; i++)
    {
        int index = i;
        for(j = i + 1; j < nitems; j++)
            if((*compar)(base[index],base[j]))
                index = j;
        if(index != i)
        {
            temp = base[index];
            base[index] = base[i];
            base[i] = temp;
        }
    }
}

int compar_title(const struct book * a,const struct book *b)
{
    return strcmp(a->title,b->title) > 0;
}

int compar_price(const struct book * a,const struct book *b)
{
    return a->value > b->value;
}

