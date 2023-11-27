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
