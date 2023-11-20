# C Primer Plus 5.10　复习题

## 1．写出执行完下列各行后quack的值是多少。后5行中使用的是前一行生成的quack的值

```c
int quack = 2; //2
quack += 5;    //7
quack *= 10;   //70
quack -= 6;    //64
quack /= 8;    //8
quack %= 3;    //2
```

## 2．假设value是int类型，下面循环的输出是什么

```c
for ( value = 36; value > 0; value /= 2)
       printf("%3d", value);
```

- 输出

```c
 36 18  9  4  2  1 
```

## 3．用代码表示以下测试条件

- a．x大于5　　

```c
x > 5
```

- b．scanf()读取一个名为x的double类型值且失败
  
```c
scanf("%lf",x) == 0
```

- c．x 的值等于5

```c
x == 5
```

## 4．用代码表示以下测试条件

- a．scanf()成功读入一个整数　　

```c
scanf("%d",x) == 1
```

- b．x 不等于5　　

```c
x != 5
```

- c．x 大于或等于20

```c
x >= 20
```

## 5．下面的程序有点问题，请找出问题所在

```c
#include <stdio.h>
int main(void)
{                                       /* 第3行 */
     int i, j, list(10);                /* 第4行 */

     for (i = 1, i <= 10, i++)          /* 第6行 */
     {                                  /* 第7行 */
          list[i] = 2*i + 3;            /* 第8行 */
          for (j = 1, j > = i, j++)     /* 第9行 */
               printf(" %d", list[j]);  /* 第10行 */
          printf("\n");                 /* 第11行 */
}                                       /* 第12行 */
```

- 以下是正确版本

```c
#include <stdio.h>
int main(void)
{ 　　　　　　　　　                    /* 第3行 */
　　 int i, j, list(10); 　　　        /* 第4行 */

　　 for (i = 1, i <= 10, i++)　　     /* 第6行 */
　　 {　　　　　　　　                  /* 第7行 */
　　　　　list[i] = 2*i + 3;　　　      /* 第8行 */
　　　　　for (j = 1, j > = i, j++)    /* 第9行 */
　　　　　　　 printf(" %d", list[j]);  /* 第10行 */
　　　　　printf("\n");　　　      　   /* 第11行 */
　　 ｝
　　 return 0;
}
```

## 6．编写一个程序打印下面的图案，要求使用嵌套循环

```c
$$$$$$$$
$$$$$$$$
$$$$$$$$
$$$$$$$$
```

- 代码如下

```c
#include <stdio.h>
#define ROWS  4
#define COLUMN 8
int main(void)
{
     for(int i = 0;i < ROWS;i++){
          for (int j = 0; j < COLUMN; j++)
               printf("%c",'$');     
          printf("\n");     
     }
     return 0;
}
```

## 7．下面的程序各打印什么内容

- a．

```c
#include <stdio.h>

int main(void)
{
     int i = 0;

     while (++i < 4)
          printf("Hi! ");
     do
          printf("Bye! ");
     while (i++ < 8);
     return 0;
}

```

```c
Hi! Hi! Hi! Bye! Bye! Bye! Bye! Bye! 
```

- b．

```c
#include <stdio.h>
int main(void)
{
     int i;
     char ch;

     for (i = 0, ch = 'A'; i < 4; i++, ch += 2 * i)
             printf("%c", ch);
     return 0;
}
```

```c
ACGM
```

## 8．假设用户输入的是Go west, young man!，下面各程序的输出是什么？（在ASCII码中，!紧跟在空格字符后面）

### a．Go west, youn

```c
#include <stdio.h>
int main(void)
{
     char ch;

     scanf("%c", &ch);
     while (ch != 'g')
     {
          printf("%c", ch);
          scanf("%c", &ch);
     }
     return 0;
}
```

### b. Hp!xftu-!zpvo

```c
#include <stdio.h>

int main(void)
{
     char ch;

     scanf("%c", &ch);
     while (ch != 'g')
     {
          printf("%c", ++ch);
          scanf("%c", &ch);
     }
     return 0;
}
```

### c. Go west, young

```c
#include <stdio.h>

int main(void)
{
     char ch;

     do {
          scanf("%c", &ch);
          printf("%c", ch);
     } while (ch != 'g');
     return 0;
}
```

### d

```c $o west, youn
#include <stdio.h>
int main(void)
{
     char ch;

     scanf("%c", &ch);
     for (ch = '$'; ch != 'g'; scanf("%c", &ch))
          printf("%c", ch);
     return 0;
}
```

## 9．下面的程序打印什么内容

```c
#include <stdio.h>
int main(void)
{
     int n, m;

     n = 30;
     while (++n <= 33)
          printf("%d|", n);

     n = 30;
     do
          printf("%d|", n);
     while (++n <= 33);

     printf("\n***\n");

     for (n = 1; n*n < 200; n += 4)
          printf("%d\n", n);

     printf("\n***\n");

     for (n = 2, m = 6; n < m; n *= 2, m += 2)
          printf("%d %d\n", n, m);

     printf("\n***\n");

     for (n = 5; n > 0; n--)
     {
          for (m = 0; m <= n; m++)
               printf("=");
          printf("\n");
     }
     return 0;
}
```

```c
31|32|33|30|31|32|33|
***
1
5
9
13

***
2 6
4 8
8 10

***
======
=====
====
===
==

```

## 10．考虑下面的声明

```c
double mint[10];
```

### a.数组名是什么？

- mint

### b.该数组有多少个元素?

- 10

### c.每个元素可以存储什么类型的值?

- double

### d. 下面的哪一个scanf()的用法正确？ ii

- i．scanf("%lf", mint[2])
- ii．scanf("%lf", &mint[2])
- iii．scanf("%lf", &mint)

## 11．Noah先生喜欢以2计数，所以编写了下面的程序，创建了一个存储2、4、6、8等数字的数组。这个程序是否有错误之处？如果有，请指出

```c
#include <stdio.h>
#define SIZE 8
int main(void)
{
     int by_twos[SIZE];
     int index;

     for (index = 1; index <= SIZE; index++)
           by_twos[index] = 2 * index;
     for (index = 1; index <= SIZE; index++)
           printf("%d ", by_twos);
     printf("\n");
     return 0;
}
```

- 因为第1个元素的索引是0，所以循环的范围应该是0～SIZE - 1，而不是1～SIZE。但是，如果只是这样更改会导致赋给第1个元素的值是0，不是2。所以，应重写这个循环：

```c
for (index = 0; index < SIZE; index++)
　　 by_twos[index] = 2 * (index + 1);
```

- 与此类似，第2个循环的范围也要更改。另外，应该在数组名后面使用数组索引：

```c
for( index = 0; index < SIZE; index++)
　　 printf("%d ", by_twos[index]);
```

- 错误的循环条件会成为程序的定时炸弹。程序可能开始运行良好，但是由于数据被放在错误的位置，可能在某一时刻导致程序不能正常工作。

## 12．假设要编写一个返回long类型值的函数，函数定义中应包含什么

- 该函数应声明为返回类型为long，并包含一个返回long类型值的return语句。

## 13．定义一个函数，接受一个int类型的参数，并以long类型返回参数的平方值

```c
long square(int num)
{
　　 return ((long) num) * num;
}
```

## 14．下面的程序打印什么内容？

```c
#include <stdio.h>
int main(void)
{
     int k;
     for (k = 1, printf("%d: Hi!\n", k); printf("k = %d\n", k),
          k*k < 26; k += 2, printf("Now k is %d\n", k))
               printf("k is %d in the loop\n", k);
     return 0;
}
```

```c
1: Hi!
k = 1
k is 1 in the loop
Now k is 3
k = 3
k is 3 in the loop
Now k is 5
k = 5
k is 5 in the loop
Now k is 7
k = 7
```
