# 10.12 复习题

## 1．下面的程序将打印什么内容

```c
#include <stdio.h>
int main(void)
{
     int ref[] = { 8, 4, 0, 2 };
     int *ptr;
     int index;

     for (index = 0, ptr = ref; index < 4; index++, ptr++)
          printf("%d %d\n", ref[index], *ptr);
     return 0;
}
```

```c
8 8
4 4
0 0
2 2
```

## 2．在复习题1中，ref有多少个元素

ref有4个元素

## 3．在复习题1中，ref的地址是什么？ref + 1是什么意思？++ref指向什么

数组名ref指向该数组的首元素（整数8）。表达式ref + 1指向该数组的第2个元素（整数4）。++ref不是有效的表达式，因为ref是一个常量，不是变量。

## 4．在下面的代码中，*ptr和*(ptr + 2)的值分别是什么

- a.

```c
int *ptr;
int torf[2][2] = {12, 14, 16};
ptr = torf[0];
```

```c
*ptr = 12;
*(ptr + 2) = 16
```

- b.

```c
int * ptr;
int fort[2][2] = { {12}, {14,16} };
ptr = fort[0];
```

```c
*ptr = 12;
*(ptr + 2) = 14;
```

## 5．在下面的代码中，**ptr和**(ptr + 1)的值分别是什么

- a．

```c
int (*ptr)[2];
int torf[2][2] = {12, 14, 16};
ptr = torf;
```

```c
**ptr = 12;
**(ptr + 1) = 16;
```

- b．

```c
int (*ptr)[2];
int torf[2][2] = { {12}, {14,16} };
ptr = torf;
```

```c
**ptr = 12;
**(ptr + 1) = 14;
```

## 6．假设有下面的声明

```c
int grid[30][100];
```

```c
a．用1种写法表示grid[22][56]的地址

&grid[22][56];
```

```c
b．用2种写法表示grid[22][0] 的地址

&grid[22][0]或grid[22];
```

```c
c．用3种写法表示grid[0][0] 的地址

&grid[0][0]或grid[0]或(int *) grid;
```

## 7．正确声明以下各变量

```c
a．digits是一个内含10个int类型值的数组

int digits[10];
```

```c
b．rates是一个内含6个float类型值的数组

float rates[6];
```

```c
c．mat是一个内含3个元素的数组，每个元素都是内含5个整数的数组

int mat[3][5];
```

```c
d．psa是一个内含20个元素的数组，每个元素都是指向char的指针

char *psa[20];
```

```c
e．pstr是一个指向数组的指针，该数组内含20个char类型的值

char (*pstr)[20];
```

## 8．正确用代码表达以下内容

```c
a．声明一个内含6个int类型值的数组，并初始化各元素为1、2、4、8、16、32

int sextet[6] = {1, 2, 4, 8, 16, 32};
```

```c
b．用数组表示法表示a声明的数组的第3个元素（其值为4）

sextet[2];
```

```c
c．假设编译器支持C99/C11标准，声明一个内含100个int类型值的数组，并初始化最后一个元素为-1，其他元素不考虑

int lots[100] = {[99] = -1};
```

```c
d．假设编译器支持C99/C11标准，声明一个内含100个int类型值的数组，并初始化下标为5、10、11、12、13的元素为101，其他元素不考虑

int pots[100] = { [5] = 101, [10] = 101, 101, 101, [3]=101};
```

## 9．内含10个元素的数组下标范围是什么

0~9

## 10．假设有下面的声明

```c
float rootbeer[10], things[10][5], *pf, value = 2.2;
int i = 3;
```

判断以下各项是否有效：

```c
a．rootbeer[2] = value;　　       \\有效
b．scanf("%f", &rootbeer );　　   \\无效
c．rootbeer = value;　　          \\无效
d．printf("%f", rootbeer);　　    \\无效
e．things[4][4] = rootbeer[3];　　\\有效
f．things[5] = rootbeer;　　      \\无效
g．pf = value;　　                \\无效
h．pf = rootbeer;                 \\有效
```

## 11．声明一个800×600的int类型数组

```c
int screen[800][600];
```

## 12．下面声明了3个数组

```c
double trots[20];
short clops[10][30];
long shots[5][10][15];
```

```c
a．分别以传统方式和以变长数组为参数的方式编写处理trots数组的void函数原型和函数调用

void process(double ar[], int n);
void processvla(int n, double ar[n]);
process(trots, 20);
processvla(20, trots);

b．分别以传统方式和以变长数组为参数的方式编写处理clops数组的void函数原型和函数调用

void process2(short ar2[][30], int n);
void process2vla(int n, int m, short ar2[n][m]);
process2(clops, 10);
process2vla(10, 30, clops);

c．分别以传统方式和以变长数组为参数的方式编写处理shots数组的void函数原型和函数调用

void process3(long ar3[][10][15], int n);
void process3vla(int n, int m,int k, long ar3[n][m][k]);
process3(shots, 5);
process3vla(5, 10, 15, shots);
```

## 13．下面有两个函数原型

```c
void show(const double ar[], int n);        // n是数组元素的个数
void show2(const double ar2[][3], int n);   // n是二维数组的行数
```

```c
a．编写一个函数调用，把一个内含8、3、9和2的复合字面量传递给show()函数。

show((int[4]) {8, 3, 9, 2}, 4);

b．编写一个函数调用，把一个2行3列的复合字面量（8、3、9作为第1行，5、4、1作为第2行）传递给show2()函数。

show2((int [2][3]) {{8, 3, 9}, {5, 4, 1}, 2});

```
