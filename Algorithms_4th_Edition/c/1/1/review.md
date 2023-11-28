# 算法(第4版) 1.1基础编程模型练习题

## 1.1.1 给出以下表达式的值

```c
a. ( 0 + 15 ) / 2    //7
b. 2.0e-6 ＊ 100000000.1    //200000000.2e-6 
c. true && false || true && true    //1
```

## 1.1.2 给出以下表达式的类型和值

```c
a. (1 + 2.236)/2    //java - 1.618(double),c - 1.618(double)
b. 1 + 2 + 3 + 4.0    //java - 10.0(double),c - 10.0(double)
c. 4.1 ＞= 4    //java - true(bool),c - 1(int)
d. 1 + 2 + "3"    //java - "33"(String),c - error
```

## 1.1.3 编写一个程序，从命令行得到三个整数参数。如果它们都相等则打印equal，否则打印not equal

```c
#include <stdio.h>
#include <stdlib.h>

/*
 * 三个整数比较，如果它们都相等,返回1，否则返回0
 * 参数: a - int类型数据
 * 参数: b - int类型数据
 * 参数: c - int类型数据
 * 返回: 如果a,b,c都相等,返回1,否则返回0
 */
int threeCompar(int a,int b,int c);

int main(int argc,char * argv[])
{
    if(argc < 3)
    {
        fprintf(stderr,"Usage:%s integer1 integer2 integer3",argv[0]);
        exit(EXIT_FAILURE);
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    
    if(threeCompar(a,b,c))
        puts("equal");
    else
        puts("not equal");

    return 0;
}


/*
 * 三个整数比较，如果它们都相等,返回1，否则返回0
 * 参数: a - int类型数据
 * 参数: b - int类型数据
 * 参数: c - int类型数据
 * 返回: 如果a,b,c都相等,返回1,否则返回0
 */
int threeCompar(int a,int b,int c)
{
    return a == b && b == c;
}

```

```java
public class Test1_1_3 {
    public static boolean threeCompar(int a, int b, int c)
    {
        return a == b && b == c;
    }
    public static void main(String[] args) {
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int c = Integer.parseInt(args[2]);

        if(threeCompar(a,b,c))
            System.out.println("equal");
        else
            System.out.println("not equal");
    }
}
```

## 1.1.4 下列语句各有什么问题（如果有的话

```c
a. if (a ＞ b) then c = 0;   //c-语法不需要then,java-同上
b. if a ＞ b { c = 0; }    //c-无问题,java-无问题
c. if (a ＞ b) c = 0;    //c-无问题,java-无问题
d. if (a ＞ b) c = 0 else b = 0;   //c-无问题,java-无问题
```

## 1.1.5 编写一段程序，如果double类型的变量x和y都严格位于0和1之间则打印true，否则打印false

```c
#include <stdio.h>

void judgexy(double x,double y);

void judgexy(double x,double y)
{
    if(x>=0 && x<=1 && y>=0 && y<=1)
        puts("true");
    else
        puts("false");
}
```

```java
public class Test1_1_5 {

    public static void judgexy(double x,double y) {
        if(x >= 0 && y >= 0 && x <= 1 && y <= 1)
            System.out.println("true");
        else
            System.out.println("false");
    }
}
```

## 1.1.6 下面这段程序会打印出什么

```java
int f = 0;
int g = 1;
for (int i = 0; i ＜= 15; i++)
{
    StdOut.println(f);
    f = f + g;
    g = f - g;
}
```

```java
0
1
1
2
3
5
8
13
21
34
55
89
144
233
377
610 
```

## 1.1.7 分别给出以下代码段打印出的值

```java
a. double t = 9.0;
  while (Math.abs(t -9.0/t) ＞ .001)
      t = (9.0/t + t) / 2.0;
  StdOut.printf("%.5f\n", t);
// 3.00009

b. int sum = 0;
  for (int i = 1; i ＜ 1000; i++)
      for (int j = 0; j ＜ i; j++)
          sum++;
  StdOut.println(sum);
// 499500

c. int sum = 0;
  for (int i = 1; i ＜ 1000; i ＊= 2)
      for (int j = 0; j ＜ 1000; j++)
          sum++;
  StdOut.println(sum);
// 10000
```

## 1.1.8 下列语句会打印出什么结果？给出解释

```java
a. System.out.println('b');    //b,打印b字符
b. System.out.println('b' + 'c');    //197,+运算会把char转换成int,再运算，b的ascii码是98,c的ascii码是99,所以相加等于197
c. System.out.println((char) ('a' + 4));    //一开始过程类似，得到整数101,跟着强制类型转换为char,对应就是e
```

## 1.1.9 编写一段代码，将一个正整数N用二进制表示并转换为一个String类型的值s

解答：Java有一个内置方法Integer.toBinaryString(N)专门完成这个任务，但该题的目的就是给出这个方法的其他实现方法。下面就是一个特别简洁的答案：

```java
String s = "";
for (int n = N; n ＞ 0; n /= 2)
    s = (n % 2) + s;
```

```c
#include <stdio.h>
#define BSIZE 100

char * itobitstr(char * bitstr,int bsize,int n);

int main(void)
{
    char bs[BSIZE];
    int n;
    while(scanf("%d",&n) == 1)
    {
        itobitstr(bs,BSIZE,n);
        printf("%d is %s\n",n,bs);
    }
    return 0;
}

char * itobitstr(char * bitstr,int bsize,int n)
{
    int top = 0;
    char temp;
    for(int i = n; i > 0; i /= 2)
    {
        bitstr[top] = '0' + i % 2;
        top++;
        if(top >= bsize)
            break;
    }
    bitstr[top] = '\0';
    for(int i = 0,j = top - 1; i < j; i++,j--)
    {
        temp = bitstr[i];
        bitstr[i] = bitstr[j];
        bitstr[j] = temp;
    }
    return bitstr;
}
```

## 1.1.10 下面这段代码有什么问题

```java
int[] a;
for (int i = 0; i ＜ 10; i++)
    a[i] = i ＊ i;
```

```c
在c里
使用未初始化的指针的结果是未知的

在java里:
解答：它没有用new为a[]分配内存。这段代码会产生一个variable a might not have been initialized的编译错误。
```

## 1.1.11 编写一段代码，打印出一个二维布尔数组的内容。其中，使用＊表示真，空格表示假。打印出行号和列号

```java
public class Test1_1_11 {

    public static void printfboolarray(boolean[][] arr)
    {
        for (int i = 0; i <arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.printf("%d - %d : %c\n",i,j,arr[i][j] ? '*':' ');;
            }
        }
    }
}
```

```c
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 3

void printboolarr(int row,int col,int arr[row][col]);

int main(void)
{
    int arr[ROW][COL];
    for(int i = 0; i < ROW; i++)
        for(int j = 0; j < COL; j++)
            arr[i][j] = rand() % 2;
    printboolarr(ROW,COL,arr);
    return 0;
}

void printboolarr(int row,int col,int arr[row][col])
{
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            printf("%d - %d : %c\n",i,j,arr[i][j] ? '*' : ' ');
}
```

## 1.1.12 以下代码段会打印出什么结果

```java
int[] a = new int[10];
for (int i = 0; i ＜ 10; i++)
    a[i] = 9- i;
for (int i = 0; i ＜ 10; i++)
    a[i] = a[a[i]];
for (int i = 0; i ＜ 10; i++)
    System.out.println(i);
```

```java
0
1
2
3
4
5
6
7
8
9
```

## 1.1.13 编写一段代码，打印出一个M行N列的二维数组的转置（交换行和列

```c
#include <stdio.h>

#define ROW 3
#define COL 9

void printreverse(int row,int col,int arr[row][col]);

int main(void)
{
    int arr[ROW][COL];

    for(int i = 0;i < ROW; i++)
        for(int j = 0; j < COL; j++)
            arr[i][j] = (i + 1) * 10 + j;

    printreverse(ROW,COL,arr);
    return 0;
}

void printreverse(int row,int col,int arr[row][col])
{
    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
            printf("%d ",arr[j][i]);
        putchar('\n');
    }
}

```

```java
public class Test1_1_13 {

    public static void printreverse(int[][] arr)
    {
        for (int i = 0; i < arr[0].length; i++) {
            for (int j = 0; j < arr.length; j++) {
                System.out.printf("%d ",arr[j][i]);
            }
        }
    }
}
```

## 1.1.14 编写一个静态方法lg()，接受一个整型参数N，返回不大于log2N的最大整数。不要使用Math库

```c
#include <stdio.h>
#include <stdlib.h>

int lg(double n);

int main(void)
{
    int result;
    double n;
    while(scanf("%lf",&n) == 1)
    {
        result = lg(n);
        printf("long2 %lf the biggest integer is %d\n",n,result);
    }
    return 0;
}

int lg(double n)
{
    int result = 0;
    if(n <= 0)
    {
        fprintf(stderr,"%d < 0,Not in the defined field of log\n");
        exit(EXIT_FAILURE);
    }

    if(n >= 1)
        for(int i = 2; i <= n; i *= 2)
            result++;
    else
    {
        result = -1;
        for(double i = 1.0 / 2.0; i > n; i /= 2.0)
            result--;
    }
    return result;
}
```

```java
public class Test1_1_14 {
    public static int lg(int n)
    {
        if(n <= 0)
            throw new IllegalArgumentException("lg的参数要大于0,当前参数:" + n);
        int result =1;
        for (int i = 2; i < n; i *= 2)
            result++;
        return result;
    }
}
```

## 1.1.15 编写一个静态方法histogram()，接受一个整型数组a[]和一个整数M为参数并返回一个大小为M的数组，其中第i个元素的值为整数i在参数数组中出现的次数。如果a[]中的值均在0到M-1之间，返回数组中所有元素之和应该和a.length相等

```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int * histogram(int a[],int asize,int m);

int main(void)
{
    int a[SIZE] = {1,2,3,4,5,6,7,8,9,11};
    int * result;
    result = histogram(a,SIZE,SIZE + 1);

    for(int i = 0; i < SIZE + 1; i++)
        printf("%d ",result[i]);
    free(result);
    return 0;
}

int * histogram(int a[],int asize,int m)
{
    int * result;
    result = calloc(m,sizeof(int));
    for(int i = 0; i < asize; i++)
        if(a[i] >= 0 && a[i] < m)
            result[a[i]]++;
    return result;
}
```

```java
public class Test1_1_15 {
    public static int [] histogram(int a[],int m)
    {
        int[] result = new int[m];
        for (int i = 0; i < a.length; i++)
            if(a[i] >= 0 && a[i] < m)
                result[a[i]]++;
        return result;
    }
}
```

## 1.1.16 给出exR1(6)的返回值

```java
public static String exR1(int n)
{
    if (n ＜= 0) return "";
    return exR1(n-3) + n + exR1(n-2) + n;
}
//311361142246
6 exr1(3) + 6 + exr1(4) + 6;
3 exr1(0) + 3 + exr1(1) + 3;
4 exr1(1) + 4 + exr1(2) + 4;
1 exr1(-2) + 1 + exr1(-1) + 1;
2 exr1(-1) + 2 + exr1(0) + 2;
```

## 1.1.17 找出以下递归函数的问题

```java
public static String exR2(int n)
{
    String s = exR2(n-3) + n + exR2(n-2) + n;
    if (n ＜= 0) return "";
    return s;
}
```

答：这段代码中的基础情况永远不会被访问。调用exR2(3)会产生调用exR2(0)、exR2(-3)和exR2(-6)，循环往复直到发生StackOverflowError。

## 1.1.18 请看以下递归函数

```java
public static int mystery(int a, int b)
{
    if (b == 0)      return 0;
    if (b % 2 == 0) return mystery(a+a, b/2);
    return mystery(a+a, b/2) + a;
}
```

- mystery(2, 25)和mystery(3, 11)的返回值是多少？
  - mystery(2,25) = 50,mystery(3,11) = 33
- 给定正整数a和b, mystery(a,b)计算的结果是什么？
  - mystery(a,b) = a * b;
- 将代码中的+替换为＊并将return 0改为return 1，然后回答相同的问题。
  - mystery(2,25) = 33554432,mystery(3,11) = 177147
  - mystery(a,b) = a 的 b 次方;

## 1.1.19 在计算机上运行以下程序

```java
public class Fibonacci
{
    public static long F(int N)
    {
      if (N == 0) return 0;
      if (N == 1) return 1;
      return F(N-1) + F(N-2);
    }
    public static void main(String[] args)
    {
      for (int N = 0; N ＜ 100; N++)
          StdOut.println(N + " " + F(N));
    }
}
```

计算机用这段程序在一个小时之内能够得到F(N)结果的最大N值是多少？开发F(N)的一个更好的实现，用数组保存已经计算过的值。

- 一个小时内能够最大N值是56

```java
import edu.princeton.cs.algs4.StdOut;
import java.math.BigInteger;
import java.util.Objects;

public class Fibonacci
{
    public static BigInteger[] fb = new BigInteger[1000];
    public static BigInteger F(int N)
    {
        if (N == 0) return new BigInteger("0");
        if (N == 1) return new BigInteger("1");
        if(Objects.nonNull(fb[N])) return fb[N];
        fb[N] = F(N-1).add(F(N-2));
        return fb[N];
    }
    public static void main(String[] args)
    {
        for (int i = 0; i < 100; i++)
            StdOut.println(i + " " + F(i));
    }
}
```

```c
#include <stdio.h>
#define SIZE 1000

static long fb[1000]; 

long F(int N);

int main(void)
{
    for(int i = 0; i < 100; i++)
        printf("%d %ld\n",i,F(i));
    return 0;
}

long F(int N)
{
    if(N == 0) return 0;
    if(N == 1) return 1;
    if(fb[N] !=0) return fb[N];
    fb[N] = F(N-1) + F(N-2);
    return fb[N];
}
```

## 1.1.20 编写一个递归的静态方法计算ln(N! )的值

```c
#include <stdio.h>
#include <math.h>

double lnN(int n);

int main(void)
{
    for(int i = 1; i < 100; i++)
        printf("%d %lf\n",i,lnN(i));
    return 0;
}

double lnN(int n)
{
    if(n == 1) return log((double) 1);
    return log((double)n) + lnN(n - 1);
}
```

```java
public class Test1_1_20 {

    public static double lnN(int n)
    {
        if(n == 1) return Math.log((double) 1);
        return Math.log((double) n) + lnN(n-1);
    }

    public static void main(String[] args) {
        for (int i = 1; i < 100; i++) {
            System.out.println(i + " " + lnN(i));
        }
    }
}
```

## 1.1.21 编写一段程序，从标准输入按行读取数据，其中每行都包含一个名字和两个整数。然后用printf()打印一张表格，每行的若干列数据包括名字、两个整数和第一个整数除以第二个整数的结果，精确到小数点后三位。可以用这种程序将棒球球手的击球命中率或者学生的考试分数制成表格

```c
#include <stdio.h>
#define LEN 20

int main(void)
{
    char name[LEN];
    int a,b;
    while(scanf("%s%d%d",name,&a,&b) == 3)
        printf("%-20s %-10d %-10d %-10.3lf\n",name,a,b,(double) a / b);
    return 0;
}
```
