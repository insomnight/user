# 7.11　复习题

## 1．判断下列表达式是true还是false

### a．100 > 3 && 'a'>'c'

```c
false
```

### b．100 > 3 || 'a'>'c'

```c
true
```

### c．!(100>3)

```c
false
```

## 2．根据下列描述的条件，分别构造一个表达式

### a．number等于或大于90，但是小于100

```c
number >=90 && number < 100;
```　
### b．ch不是字符q或k
```c
ch != 'q' || ch != 'k';
```

### c．number在1～9之间（包括1和9），但不是5

```c
number != 5 && number >= 1 && number <= 9;
```

### d．number不在1～9之间

```c
number < 1 || number > 9;
```

## 3．下面的程序关系表达式过于复杂，而且还有些错误，请简化并改正

```c
#include <stdio.h>
int main(void)                                           /* 1 */
{                                                        /* 2 */
     int weight, height; /* weight以磅为单位，height以英寸为单位 */
/* 4 */
     scanf("%d , weight, height);                        /* 5 */
     if (weight < 100 && height > 64)                    /* 6 */
          if (height >= 72)                              /* 7 */
               printf("You are very tall for your weight.\n");
          else if (height < 72 &&> 64)                   /* 9 */
               printf("You are tall for your weight.\n");/* 10 */
          else if (weight > 300 && !(weight <= 300)      /* 11 */
               && height < 48)                           /* 12 */
          if (!(height >= 48))                           /* 13 */
               printf(" You are quite short for your weight.\n");
     else                                                /* 15 */
          printf("Your weight is ideal.\n");             /* 16 */
                                                         /* 17 */
     return 0;
}
```

```c
#include <stdio.h>
int main(void)
{
　　 int weight, height; /* weight in lbs, height in inches */

　　 printf("Enter your weight in pounds and ");
　　 printf("your height in inches.\n");
　　 scanf("%d %d", &weight, &height);
　　 if (weight < 100 && height > 64)
　　　　　if (height >= 72)
　　　　　　　 printf("You are very tall for your weight.\n");
　　　　　else
　　　　　　　 printf("You are tall for your weight.\n");
　　 else if (weight > 300 && height < 48)
　　　　　　　　printf(" You are quite short for your weight.\n");
　　 else
　　　　　printf("Your weight is ideal.\n");

　　 return 0;
}
```

## 4．下列各表达式的值是多少

### a．5 > 2　　                = 1

### b．3 + 4 > 2 && 3 < 2　　   = 0

### c．x >= y || y > x　　      = 1

### d．d = 5 + ( 6 > 2 )　　    = 6

### e．'X' > 'T' ? 10 : 5　　   = 10

### f． x > y ? y > x : x > y   = 0

## 5．下面的程序将打印什么？

```c
#include <stdio.h>
int main(void)
{
     int num;
     for (num = 1; num <= 11; num++)
     {
          if (num % 3 == 0)
               putchar('$');
          else
               putchar('*');
               putchar('#');
          putchar('%');
     }
     putchar('\n');
     return 0;
}
```

```c
*#%*#%$#%*#%*#%$#%*#%*#%$#%*#%*#%
```

## 6．下面的程序将打印什么？

```c
#include <stdio.h>
int main(void)
{
     int i = 0;
     while (i < 3) {
          switch (i++) {
               case 0: printf("fat ");
               case 1: printf("hat ");
               case 2: printf("cat ");
               default: printf("Oh no!");
          }
          putchar('\n');
     }
     return 0;
}
```

```c
fat hat cat Oh no!
hat cat Oh no!
cat Oh no!
```

## 7．下面的程序有哪些错误

```c
#include <stdio.h>
int main(void)
{
     char ch;
     int lc = 0; /* 统计小写字母
     int uc = 0; /* 统计大写字母
     int oc = 0; /* 统计其他字母

     while ((ch = getchar()) != '#')
     {
          if ('a' <= ch >= 'z')
               lc++;
          else if (!(ch < 'A') || !(ch > 'Z')
               uc++;
          oc++;
     }
     printf(%d lowercase, %d uppercase, %d other, lc, uc, oc);
     return 0;
}
```

```c
#include <stdio.h>
int main(void)
{
     char ch;
     int lc = 0; /* 统计小写字母 */
     int uc = 0; /* 统计大写字母 */
     int oc = 0; /* 统计其他字母 */

     while ((ch = getchar()) != '#')
     {
          if ('a' <= ch && 'z' <= ch )
               lc++;
          else if (!(ch < 'A') || !(ch > 'Z'))
               uc++;
          else oc++;
     }
     printf("%d lowercase, %d uppercase, %d other", lc, uc, oc);
     return 0;
}
```

## 8．下面的程序将打印什么

```c
/* retire.c */
#include <stdio.h>
int main(void)
{
     int age = 20;
     while (age++ <= 65)
     {
          if ((age % 20) == 0) /* age是否能被20整除？ */
               printf("You are %d. Here is a raise.\n", age);
          if (age = 65)
               printf("You are %d. Here is your gold watch.\n", age);
     }
     return 0;
}
```

```c
You are 65. Here is your gold watch.
//不断重复上述行
//if (age = 65)错误条件
```

## 9．给定下面的输入时，以下程序将打印什么？

```c
q
c
h
b
#include <stdio.h>
int main(void)
{
     char ch;

     while ((ch = getchar()) != '#')
     {
          if (ch == '\n')
               continue;
          printf("Step 1\n");
          if (ch == 'c')
               continue;
          else if (ch == 'b')
               break;
          else if (ch == 'h')
               goto laststep;
          printf("Step 2\n");
     laststep: printf("Step 3\n");
     }
     printf("Done\n");
     return 0;
}
```

```c
Step 1
Step 2
Step 3
Step 1
Step 1
Step 3
Step 1
Done
```

## 10．重写复习题9，但这次不能使用continue和goto语句

```c
#include <stdio.h>
int main(void)
{
　　 char ch;
　　 while ((ch = getchar()) != '#')
　　 {
　　　　　if (ch != '\n')
　　　　　{
　　　　　　　 printf("Step 1\n");
　　　　　　　 if (ch == 'b')
　　　　　　　　　　break;
　　　　　　　 else if (ch != 'c')
　　　　　　　 {
　　　　　　　　　　if (ch != 'h')
　　　　　　　　　　　printf("Step 2\n");
　　　　　　　　　　printf("Step 3\n");
　　　　　　　 }
　　　　　}
　　 }
　　 printf("Done\n");
　　 return 0;
}
```
