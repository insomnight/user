# 16.17　复习题

## 1．下面的几组代码由一个或多个宏组成，其后是使用宏的源代码。在每种情况下代码的结果是什么？这些代码是否是有效代码？（假设其中的变量已声明

- a.

```c
#define FPM 5280 /*每英里的英尺数*/
dist = FPM * miles;

a．dist = 5280 * miles;有效。
```

- b.

```c
#define FEET 4
#define POD FEET + FEET
plort = FEET * POD;

b．plort = 4 * 4 + 4;有效。但是如果用户需要的是4 * (4 + 4)，则应该使用#define POD (FEET + FEET)。
```

- c.

```c
#define SIX = 6;
nex = SIX;

c．nex = = 6;;无效（如果两个等号之间没有空格，则有效，但是没有意义）。显然，用户忘记了在编写预处理器代码时不用加=。
```

- d.

```c
#define NEW(X) X + 5
y = NEW(y);
berg = NEW(berg) * lob;
est = NEW(berg) / NEW(y);
nilp = lob * NEW(-berg);

d．y = y + 5;有效。berg = berg + 5 * lob;有效，但是可能得不到想要的结果。est = berg + 5/y + 5;有效，但是可能得不到想要的结果。
```

## 2．修改复习题1中d部分的定义，使其更可靠

```c
#define NEX(X) ((X) + 5)
```

## 3．定义一个宏函数，返回两值中的较小值

```c
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
```

## 4．定义EVEN_GT(X, Y)宏，如果X为偶数且大于Y，该宏返回1

```c
#define EVEN_GT(X,Y) ( (X) > (Y) && (X) % 2 == 0 ? 1 : 0 )
```

## 5．定义一个宏函数，打印两个表达式及其值。例如，若参数为3+4和4*12，则打印

```c
3+4 is 7 and 4*12 is 48
```

```c
#define PR(X,Y) printf(#X " is %d and " #Y " is %d\n", X,Y)
```

## 6．创建#define指令完成下面的任务

- a．创建一个值为25的命名常量。

```c
#define QUARTERCENTURY 25
```

- b．SPACE表示空格字符。

```c
#define SPACE ' '
```

- c．PS()代表打印空格字符。

```c
#define PS() putchar(' ')或#define PS() putchar(SPACE)
```

- d．BIG(X)代表X的值加3。

```c
#define BIG(X) ((X) + 3)
```

- e．SUMSQ(X, Y)代表X和Y的平方和。

```c
#define SUMSQ(X,Y) ((X)*(X) + (Y)*(Y))
```

## 7．定义一个宏，以下面的格式打印名称、值和int类型变量的地址

```c
name: fop; value: 23; address: ff464016
```

```c
#define P(X) printf("name: "#X"; value: %d; address: %p\n", X,&X)
```

## 8．假设在测试程序时要暂时跳过一块代码，如何在不移除这块代码的前提下完成这项任务

```c
#define _SKIP_ /* 如果不需要跳过代码，则删除这条指令 */
#ifndef _SKIP_
/* 需要跳过的代码 */
#endif
```

## 9．编写一段代码，如果定义了PR_DATE宏，则打印预处理的日期

```c
#ifdef PR_DATE
　　 printf("Date = %s\n", _ _DATE_ _);
#endif
```

## 10．内联函数部分讨论了3种不同版本的square()函数。从行为方面看，这3种版本的函数有何不同

第1个版本返回x*x，这只是返回了square()的double类型值。例如，square(1.3)会返回1.69。第2个版本返回 (int)(x*x)，计算结果被截断后返回。但是，由于该函数的返回类型是double，int类型的值将被升级为double类型的值，所以1.69将先被转换成1，然后被转换成1.00。第3个版本返回(int)(x*x+0.5)。加上0.5可以让函数把结果四舍五入至与原值最接近的值，而不是简单地截断。所以，1.69+0.5得2.19，然后被截断为2，然后被转换成2.00；而1.44+0.5得1.94，被截断为1，然后被转换成1.00。

## 11．创建一个使用泛型选择表达式的宏，如果宏参数是_Bool类型，对"boolean"求值，否则对"not boolean"求值

```c
#define BOOL(X) _Generic((X), _Bool : "boolean", default :"not boolean")
```

## 12．下面的程序有什么错误

```c
#include <stdio.h>
int main(int argc, char argv[])
{
　　 printf("The square root of %f is %f\n", argv[1],sqrt(argv[1]) );
}
```

应该把argv参数声明为char *argv[]类型。命令行参数被存储为字符串，所以该程序应该先把argv[1]中的字符串转换成double类型的值。例如，用stdlib.h库中的atof()函数。程序中使用了sqrt()函数，所以应包含math.h头文件。程序在求平方根之前应排除参数为负的情况（检查参数是否大于或等于0）。

## 13．假设scores是内含1000个int类型元素的数组，要按降序排序该数组中的值。假设你使用qsort()和comp()比较函数

- a．如何正确调用qsort()？

```c
qsort( (void *)scores, (size_t) 1000, sizeof (double), comp);
```

- b．如何正确定义comp()？

```c
int comp(const void * p1,const void * p2)
{
    const int * a1 = (const int *) p1; 
    const int * a2 = (const int *) p2; 
    if(*a1 > *a2)
        return -1;
    else if(*a1 == *a2)
        return 0;
    else
        return 1;
}
```

## 14．假设data1是内含100个double类型元素的数组，data2是内含300个double类型元素的数组

- a．编写memcpy()的函数调用，把data2中的前100个元素拷贝到data1中。

```c
memcpy(data1,data2,100 * sizeof(double))
```

- b．编写memcpy()的函数调用，把data2中的后100个元素拷贝到data1中。

```c
memcpy(data1,data2 + 200, 100 * sizeof(double))
```
