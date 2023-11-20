# 9.10 复习题

## 1. 实际参数和形式参数的区别

形式参数是定义被调函数中的变量。实际参数是出现在函数调用中的值，该值被赋给形式参数。可以把实际参数视以为在函数调用时初始化参数的值

## 2. 根据下面各函数的描述，分别编写它们的ANSI C函数头。注意，只需写出函数头，不用写函数体

- a．donut()接受一个int类型的参数，打印若干（参数指定数目）个0

```c
int donut(int n);
```

- b．gear()接受两个int类型的参数，返回int类型的值

```c
int gear(int a,int b);
```

- c．guess()不接受参数，返回一个int类型的值

```c
int guess(void);
```

- d．stuff_it()接受一个double类型的值和double类型变量的地址，把第1个值存储在指定位置

```c
void stuff_it(double a,double *p);
```

## 3．根据下面各函数的描述，分别编写它们的ANSI C函数头。注意，只需写出函数头，不用写函数体

- a．n_to_char()接受一个int类型的参数，返回一个char类型的值

```c
char n_to_char(int num);
```

- b．digit()接受一个double类型的参数和一个int类型的参数，返回一个int类型的值

```c
int digit(double d,int i);
```

- c．which()接受两个可存储double类型变量的地址，返回一个double类型的地址

```c
double * which(double * p1,double * p2);
```

- d．random()不接受参数，返回一个int类型的值

```c
int random(void);
```

## 4．设计一个函数，返回两整数之和

```c
int add(int a,int b)
{
    return a + b;
}
```

## 5．如果把复习题4改成返回两个double类型的值之和，应如何修改函数

```c
double add(double a,double b)
{
    return a + b;
}
```

## 6．设计一个名为alter()的函数，接受两个int类型的变量x和y，把它们的值分别改成两个变量之和以及两变量之差

```c
void alter(int * pa, int * pb)
{
    int temp;
    *pa += *pb;
    *pb = *pa - 2 * *pb;
}
```

## 7．下面的函数定义是否正确

```c
void salami(num)
{
     int num, count;
     for (count = 1; count <= num; num++)
          printf(" O salami mio!\n");
}
```

不正确。num应声明在salami()函数的参数列表中，而不是声明在函数体中。另外，把num++改成count++。

## 8．编写一个函数，返回3个整数参数中的最大值

```c
int max(int a,int b,int c)
{
    int max = a > b ? a : b;
    return max > c ? max : c;
}
```

## 9．给定下面的输出

```c
Please choose one of the following:
1) copy files            2) move files
3) remove files          4) quit
Enter the number of your choice:
```

- a．编写一个函数，显示一份有4个选项的菜单，提示用户进行选择（输出如上所示）。
- b．编写一个函数，接受两个int类型的参数分别表示上限和下限。该函数从用户的输入中读取整数。如果整数超出规定上下限，函数再次打印菜单（使用a部分的函数）提示用户输入，然后获取一个新值。如果用户输入的整数在规定范围内，该函数则把该整数返回主调函数。如果用户输入一个非整数字符，该函数应返回4。
- c．使用本题a和b部分的函数编写一个最小型的程序。最小型的意思是，该程序不需要实现菜单中各选项的功能，只需显示这些选项并获取有效的响应即可。

```c
#include <stdio.h>
/* 声明程序中要用到的函数 */
void showmenu(void); 
int getchoice(int, int);
int main()
{
　　 int res;
　　 showmenu();
　　 while ((res = getchoice(1, 4)) != 4)
　　 {
　　　　　printf("I like choice %d.\n", res);
　　　　　showmenu();
　　 }
　　 printf("Bye!\n");
　　 return 0;
}
void showmenu(void)
{
　　 printf("Please choose one of the following:\n");
　　 printf("1) copy files　　　　　 2) move files\n");
　　 printf("3) remove files　　　　 4) quit\n");
　　 printf("Enter the number of your choice:\n");
}
int getchoice(int low, int high)
{
　　 int ans;
　　 int good;
　　 good = scanf("%d", &ans);
　　 while (good == 1 && (ans < low || ans > high))
　　 {
　　　　　printf("%d is not a valid choice; try again\n", ans);
　　　　　showmenu();
　　　　　scanf("%d", &ans);
　　 }
　　 if (good != 1)
　　 {
　　　　　printf("Non-numeric input. ");
　　　　　ans = 4;
　　 }
　　 return ans;
}
```
