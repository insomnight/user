# 11.12 复习题

## 1．下面字符串的声明有什么问题

```c
int main(void)
{
    char name[] = {'F', 'e', 's', 's' };
    ...
}
```

如果希望得到一个字符串，初始化列表中应包含'\0'。当然，也可以用另一种语法自动添加空字符：

```c
int main(void)
{
    char name[] = "Fess";
}
```

## 2．下面的程序会打印什么

```c
#include <stdio.h>
int main(void)
{
    char note[] = "See you at the snack bar.";
    char *ptr;

    ptr = note;
    puts(ptr);
    puts(++ptr);
    note[7] = '\0';
    puts(note);
    puts(++ptr);
    return 0;
}
```

```c
See you at the snack bar.
ee you at the snack bar.
See you
e you
```

## 3．下面的程序会打印什么

```c
#include <stdio.h>
#include <string.h>
int main(void)
{
    char food [] = "Yummy";
    char *ptr;

    ptr = food + strlen(food);
    while (--ptr >= food)
        puts(ptr);
    return 0;
}
```

```c
y
my
mmy
ummy
Yummy
```

## 4．下面的程序会打印什么

```c
#include <stdio.h>
#include <string.h>
int main(void)
{
    char goldwyn[40] = "art of it all ";
    char samuel[40] = "I read p";
    const char * quote = "the way through.";

    strcat(goldwyn, quote);
    strcat(samuel, goldwyn);
    puts(samuel);
    return 0;
}
```

```c
I read part of it all the way through.
```

## 5．下面的练习涉及字符串、循环、指针和递增指针。首先，假设定义了下面的函数

```c
#include <stdio.h>
char *pr(char *str)
{
    char *pc;

    pc = str;
    while (*pc)
        putchar(*pc++);
    do {
        putchar(*--pc);
        } while (pc - str);
    return (pc);
}
```

考虑下面的函数调用

```c
x = pr("Ho Ho Ho!");
```

- a．将打印什么

```c
Ho Ho Ho!!oH oH oH
```

- b．x是什么类型　　

```c
char * //指向char的指针
```

- c．x的值是什么

```c
第1个H的地址。
```

- d．表达式*--pc是什么意思？与--*pc有何不同

```c
*--pc的意思是把指针递减1，并使用存储在该位置上的值。--*pc的意思是解引用pc指向的值，然后把该值减1（例如，H变成G）。
```

- e．如果用*pc--替换*--pc，会打印什么

```c
Ho Ho Ho!!oH oH o
```

- f．两个while循环用来测试什么

```c
while (*pc)检查pc是否指向一个空字符（即，是否指向字符串的末尾）。while的测试条件中使用存储在指针指向位置上的值。

while (pc - str)检查pc是否与str指向相同的位置（即，字符串的开头）。while的测试条件中使用存储在指针指向位置上的值。
```

- g．如果pr()函数的参数是空字符串，会怎样

```c
进入第1个while循环后，pc指向空字符。进入第2个while循环后，它指向空字符前面的存储区（即，str所指向位置前面的位置）。把该字节解释成一个字符，并打印这个字符。然后指针退回到前面的字节处。永远都不会满足结束条件(pc == str)，所以这个过程会一直持续下去。
```

- h．必须在主调函数中做什么，才能让pr()函数正常运行

```c
必须在主调程序中声明pr()：char * pr(char *);
```

## 6．假设有如下声明

```c
char sign = '$';
```

sign占用多少字节的内存？'$'占用多少字节的内存？"$"占用多少字节的内存？

```c
字符变量占用一个字节，所以sign占1字节。但是字符常量存储为int类型，意思是'$'通常占用2或4字节。但是实际上只使用int的1字节存储'$'的编码。字符串"$"使用2字节：一个字节存储'$'的编码，一个字节存储的'\0'编码。
```

## 7．下面的程序会打印出什么

```c
#include <stdio.h>
#include <string.h>
#define M1 "How are ya, sweetie? "
char M2[40] = "Beat the clock.";
char * M3 = "chat";
int main(void)
{
    char words[80];
    printf(M1);
    puts(M1);
    puts(M2);
    puts(M2 + 1);
    strcpy(words, M2);
    strcat(words, " Win a toy.");
    puts(words);
    words[4] = '\0';
    puts(words);
    while (*M3)
        puts(M3++);
    puts(--M3);
    puts(--M3);
    M3 = M1;
    puts(M3);
    return 0;
}
```

```c
How are ya, sweetie? How are ya, sweetie? 
Beat the clock.
eat the clock.
Beat the clock. Win a toy.
Beat
chat
hat
at
t
t
at
How are ya, sweetie? 
```

## 8．下面的程序会打印出什么

```c
#include <stdio.h>
int main(void)
{
    char str1 [] = "gawsie"; 
    char str2 [] = "bletonism";
    char *ps;
    int i = 0;
    for (ps = str1; *ps != '\0'; ps++) {
        if (*ps == 'a' || *ps == 'e')
            putchar(*ps);
        else
            (*ps)--;
        putchar(*ps);
    }
    putchar('\n');
    while (str2[i] != '\0') {
        printf("%c", i % 3 ? str2[i] : '*');
        ++i;
    }
    return 0;
}
```

```c
faavrhee
*le*on*sm
```

## 9．本章定义的s_gets()函数，用指针表示法代替数组表示法便可减少一个变量i。请改写该函数

```c
#include <stdio.h> // 提供fgets()和getchar()的原型
char * s_gets(char * st, int n)
{
　　 char * ret_val;

　　 ret_val = fgets(st, n, stdin);
　　 if (ret_val)
　　 {
　　　　　while (*st != '\n' && *st != '\0')
　　　　　　　 st++;
　　　　　if (*st == '\n')
　　　　　　　 *st = '\0';
　　　　　else
　　　　　　　 while (getchar() != '\n')
　　　　　　　　　　continue;
　　 }
　　 return ret_val;
}
```

## 10．strlen()函数接受一个指向字符串的指针作为参数，并返回该字符串的长度。请编写一个这样的函数

```c
size_t strlen(const char * str)
{
    size_t len = 0;
    while(*str++)
    {
        len++;
    }
    return len;
}
```

## 11．本章定义的s_gets()函数，可以用strchr()函数代替其中的while循环来查找换行符。请改写该函数

```c
#include <stdio.h>　　// 提供 fgets()和getchar()的原型
#include <string.h>　 // 提供 strchr()的原型
char * s_gets(char * st, int n)
{
　　 char * ret_val;
　　 char * find;
　　 ret_val = fgets(st, n, stdin);
　　 if (ret_val)
　　 {
　　　　　find = strchr(st, '\n');　// 查找换行符
　　　　　if (find)　　　　　        // 如果地址不是 NULL,
　　　　　　　 *find = '\0';　　　   // 在此处放置一个空字符
　　　　　else
　　　　　　　 while (getchar() != '\n')
　　　　　　　　　　continue;
　　 }
　　 return ret_val;
}
```

## 12．设计一个函数，接受一个指向字符串的指针，返回指向该字符串第1个空格字符的指针，或如果未找到空格字符，则返回空指针

```c
#include <stdio.h>　　/*提供 NULL 的定义*/
char * strblk(const char * string)
{
　　 while (*string != ' ' && *string != '\0')
　　　　　string++;　　 　/*在第1个空白或空字符处停止*/
　　 if (*string == '\0')
　　　　　return NULL;　　/* NULL 指空指针*/
　　 else
　　　　　return (char *)string;
}
```

## 13．重写程序清单11.21，使用ctype.h头文件中的函数，以便无论用户选择大写还是小写，该程序都能正确识别答案

```c
/* compare.c -- 该程序可以正常运行 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>   // strcmp()函数的原型在该头文件中

#define ANSWER "GRANT"
#define SIZE 40
char * s_gets(char * st, int n);
void ToUpper(char * str);

int main(void)
{
    char try[SIZE];

    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    ToUpper(try);
    while (strcmp(try, ANSWER) != 0)
    {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
        ToUpper(try);
    }
    puts("That's right!");

    return 0;
}

void ToUpper(char * str)
{
    while(*str != '\0')
    {
        *str = touper(*str);
        str++;
    }
}

char * s_gets(char * st, int n)
{
     char * ret_val;
     int i = 0;

     ret_val = fgets(st, n, stdin);
     if (ret_val)
     {
          while (st[i] != '\n' && st[i] != '\0')
               i++;
          if (st[i] == '\n')
               st[i] = '\0';
          else 
               while (getchar() != '\n')
                     continue;
     }
     return ret_val;
}
```
