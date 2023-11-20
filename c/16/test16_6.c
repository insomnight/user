/*
 * 6．修改程序清单16.17，使用struct names元素（在程序清单16.17后面的讨论中定义过），而不是double类型的数组。使用较少的元素，并用选定的名字显式初始化数组。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 40

struct name {
    char first[NUM];
    char last[NUM];
};

void fillarray(struct name ar [], int n);
void showarray(const struct name ar [], int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
    struct name vals[NUM];
    fillarray(vals, NUM);
    puts("Random list:");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(struct name), mycomp);
    puts("\nSorted list:");
    showarray(vals, NUM);
    return 0;
}

void fillarray(struct name ar [], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            ar[i].first[j] = 'a' + rand() % 26;
            ar[i].last[j] = 'a' + rand() % 26;
        }
        ar[i].first[7] = '\0';
        ar[i].last[7] = '\0';
    }
}

void showarray(const struct name ar [], int n)
{
    int index;

    for (index = 0; index < n; index++)
    {
        printf("%s %s, ", ar[index].first,ar[index].last);
        if (index % 6 == 5)
            putchar('\n');
    }
    if (index % 6 != 0)
        putchar('\n');
}

/* 按从小到大的顺序排序 */
int mycomp(const void * p1, const void * p2)
{
    /* 要使用指向double的指针来访问这两个值 */
    const struct name * a1 = (const struct name *) p1;
    const struct name * a2 = (const struct name *) p2;
    
    int res;
    res = strcmp(a1->last,a2->last);
    if (res != 0)
        return res;
    else 
        return strcmp(a1->first,a2->first);
}
