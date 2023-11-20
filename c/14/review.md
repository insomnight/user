# 14.17　复习题

## 1．下面的结构模板有什么问题

```c
structure {
     char itable;
     int num[20];
     char * togs
}
```

正确的关键是struct，不是structure。该结构模板要在左花括号前面有一个标记，或者在右花括号后面有一个结构变量名。另外，*togs后面和模板结尾处都少一个分号。

## 2．下面是程序的一部分，输出是什么

```c
#include <stdio.h>
struct house {
     float sqft;
     int rooms;
     int stories;
     char address[40];
};
int main(void)
{
     struct house fruzt = {1560.0, 6, 1, "22 Spiffo Road"};
     struct house *sign;

     sign = &fruzt;
     printf("%d %d\n", fruzt.rooms, sign->stories);
     printf("%s \n", fruzt.address);
     printf("%c %c\n", sign->address[3], fruzt.address[4]);
     return 0;
}
```

```c
6 1
22 Spiffo Road
S p
```

## 3．设计一个结构模板存储一个月份名、该月份名的3个字母缩写、该月的天数以及月份号

```c
struct month {
　　 char name[10];
　　 char abbrev[4];
　　 int days;
　　 int monumb;
};
```

## 4．定义一个数组，内含12个结构（第3题的结构类型）并初始化为一个年份（非闰年）

```c
struct month months[12] =
{
　　 { "January", "jan", 31, 1 },
　　 { "February", "feb", 28, 2 },
　　 { "March", "mar", 31, 3 },
　　 { "April", "apr", 30, 4 },
　　 { "May", "may", 31, 5 },
　　 { "June", "jun", 30, 6 },
　　 { "July", "jul", 31, 7 },
　　 { "August", "aug", 31, 8 },
　　 { "September", "sep", 30, 9 },
　　 { "October", "oct", 31, 10 },
　　 { "November", "nov", 30, 11 },
　　 { "December", "dec", 31, 12 }
};
```

## 5．编写一个函数，用户提供月份号，该函数就返回一年中到该月为止（包括该月）的总天数。假设在所有函数的外部声明了第3题的结构模版和一个该类型结构的数组

```c
extern struct month months [];
int days(int month)
{
　　 int index, total;
　　 if (month < 1 || month > 12)
　　　　　return(-1); /* error signal */
　　 else
　　 {
　　　　　for (index = 0, total = 0; index < month; index++)
　　　　　　　 total += months[index].days;
　　　　　return(total);
　　 }
}
```

## 6

- a．假设有下面的typedef，声明一个内含10个指定结构的数组。然后，单独给成员赋值（或等价字符串），使第3个元素表示一个焦距长度有500mm，孔径为f/2.0的Remarkata镜头。

```c
typedef struct lens { /* lens 描述 */
　　 float foclen;　 　/* 焦距长度，单位：mm */
　　 float fstop;　  　/* 孔径 */
　　 char brand[30];　 /* 品牌 */
} LENS;

LENS bigEye[10];
bigEye[2].foclen = 500;
bigEye[2].fstop = 2.0;
strcpy(bigEye[2].brand, "Remarkatar");
```

- b．重写a，在声明中使用一个待指定初始化器的初始化列表，而不是对每个成员单独赋值。

```c
LENS bigEye[10] = {[2] = {500,2.0,"Remarkatar"}};
```

## 7．考虑下面程序片段

```c
struct name {
     char first[20];
     char last[20];
};
struct bem {
     int limbs;
     struct name title;
     char type[30];
};
struct bem * pb;
struct bem deb = {
     6,
     { "Berbnazel", "Gwolkapwolk" },
     "Arcturan"
};

pb = &deb;
```

- a．下面的语句分别打印什么？

```c
printf("%d\n", deb.limbs);      \\6
printf("%s\n", pb->type);       \\Arcturan
printf("%s\n", pb->type + 2);   \\cturan
```

- b．如何用结构表示法（两种方法）表示"Gwolkapwolk"？

```c
(*pb).title.last;

pb->title.last;

deb.title.last;
```

- c．编写一个函数，以bem结构的地址作为参数，并以下面的形式输出结构的内容（假定结构模板在一个名为starfolk.h的头文件中

```c
Berbnazel Gwolkapwolk is a 6-limbed Arcturan.

void print_bem(const struct bem * b)
{
    printf("%s %s is a %d-limbed %s.\n",b->title.first,b->title.last,b->limbs,b->type);
}
```

## 8．考虑下面的声明

```c
struct fullname {
     char fname[20];
     char lname[20];
};
struct bard {
     struct fullname name;
     int born;
     int died;
};
struct bard willie;
struct bard *pt = &willie;
```

- a．用willie标识符标识willie结构的born成员。

```c
willie.born;
```

- b．用pt标识符标识willie结构的born成员。

```c
pt-> born;

(*pt).born;
```

- c．调用scanf()读入一个用willie标识符标识的born成员的值。

```c
scanf("%d",&willie.born);
```

- d．调用scanf()读入一个用pt标识符标识的born成员的值。

```c
scanf("%d",&(*pt).born);

scanf("%d",&pt->born);
```

- e．调用scanf()读入一个用willie标识符标识的name成员中lname成员的值。

```c
scanf("%s",willie.name.lname);
```

- f．调用scanf()读入一个用pt标识符标识的name成员中lname成员的值。

```c
scanf("%s",(*pt).name.lname);

scanf("%s",pt->name.lname);
```

- g．构造一个标识符，标识willie结构变量所表示的姓名中名的第3个字母（英文的名在前）。

```c
char ch = whillie.name.fname[2];
```

- h．构造一个表达式，表示willie结构变量所表示的名和姓中的字母总数。

```c
strlen(whillie.name.fname) + strlen(whillie.name.lname);
```

## 9．定义一个结构模板以存储这些项：汽车名、马力、EPA（美国环保局）城市交通MPG（每加仑燃料行驶的英里数）评级、轴距和出厂年份。使用car作为该模版的标记

```c
struct car {
　　 char name[20];
　　 float hp;
　　 float epampg;
　　 float wbase;
　　 int year;
};
```

## 10．假设有如下结构

```c
struct gas {
     float distance;
     float gals;
     float mpg;
};
```

- a．设计一个函数，接受struct gas类型的参数。假设传入的结构包含distance和gals信息。该函数为mpg成员计算正确的值，并把值返回该结构。

- b．设计一个函数，接受struct gas类型的参数。假设传入的结构包含distance和gals信息。该函数为mpg成员计算正确的值，并把该值赋给合适的成员。

```c
struct gas {
　　 float distance;
　　 float gals;
　　 float mpg;
};

struct gas mpgs(struct gas trip)
{
　　 if (trip.gals > 0)
　　　　　trip.mpg = trip.distance / trip.gals;
　　 else
　　　　　trip.mpg = -1.0;
　　 return trip;
}

void set_mpgs(struct gas * ptrip)
{
　　 if (ptrip->gals > 0)
　　　　　ptrip->mpg = ptrip->distance / ptrip->gals;
　　 else
　　　　　ptrip->mpg = -1.0;
}
```

注意，第1个函数不能直接改变其主调程序中的值，所以必须用返回值才能传递信息。

```c
struct gas idaho = {430.0, 14.8};　// 设置前两个成员
idaho = mpgs(idaho);　　　        　// 重置数据结构
```

但是，第2个函数可以直接访问最初的结构：

```c
struct gas ohio = {583, 17.6};　　//设置前两个成员
set_mpgs(&ohio);　　　        　  // 设置第3个成员
```

## 11．声明一个标记为choices的枚举，把枚举常量no、yes和maybe分别设置为0、1、2

```c
enum choices {no,yes,maybe};
```

## 12．声明一个指向函数的指针，该函数返回指向char的指针，接受一个指向char的指针和一个char类型的值

```c
char * (* pfun) (char *,char)
```

## 13．声明4个函数，并初始化一个指向这些函数的指针数组。每个函数都接受两个double类型的参数，返回double类型的值。另外，用两种方法使用该数组调用带10.0和2.5实参的第2个函数

```c
double sum(double, double);
double diff(double, double);
double times(double, double);
double divide(double, double);
double (*pf1[4])(double, double) = {sum, diff, times, divide};
```

或者用更简单的形式，把代码中最后一行替换成：

```c
typedef double (*ptype) (double, double);
ptype pfl[4] = {sum,diff, times, divide};
```

调用diff()函数：

```c
pf1[1](10.0, 2.5);　 　// 第1种表示法
(*pf1[1])(10.0, 2.5);　// 等价表示法
```
