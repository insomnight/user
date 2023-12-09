# 算法4 1.2数据抽象练习

## 1.2.1 编写一个Point2D的用例，从命令行接受一个整数N。在单位正方形中生成N个随机点，然后计算两点之间的最近距离

```java
import edu.princeton.cs.algs4.Interval1D;
import edu.princeton.cs.algs4.Interval2D;
import edu.princeton.cs.algs4.Point2D;

import java.awt.geom.Line2D;

public class Book_1_2_2_1 {

    public static void main(String[] args) {
        double xlo = Double.parseDouble(args[0]);
        double xhi = Double.parseDouble(args[1]);
        double ylo = Double.parseDouble(args[2]);
        double yhi = Double.parseDouble(args[3]);
        int t = Integer.parseInt(args[4]);

        Interval1D xInterval = new Interval1D(xlo, xhi);
        Interval1D yInterval = new Interval1D(ylo, yhi);
        Interval2D box = new Interval2D(xInterval, yInterval);
        box.draw();
        Counter c = new Counter("hits");
        for (int i = 0; i < t; i++) {
            double x = Math.random();
            double y = Math.random();
            Point2D p = new Point2D(x,y);
            if(box.contains(p)) c.increment();
            else p.draw();
        }

        System.out.println(c);
        System.out.println(box.area());
    }
}
```

## 1.2.2 编写一个Interval1D的用例，从命令行接受一个整数N。从标准输入中读取N个间隔（每个间隔由一对double值定义）并打印出所有相交的间隔对

```java
import edu.princeton.cs.algs4.Interval1D;
import edu.princeton.cs.algs4.StdIn;

public class Test1_2_2 {

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        Interval1D[] interval1DS = new Interval1D[n];
        for(int i = 0; i < n; i++)
        {
            double x= StdIn.readDouble();
            double y= StdIn.readDouble();
            interval1DS[i] = new Interval1D(Math.min(x, y), Math.max(x, y));
            if(i > 0)
                for (int j = 0; j < i; j++)
                    if(interval1DS[j].intersects(interval1DS[i]))
                        System.out.println(interval1DS[j] + " intersects " + interval1DS[i]);
        }
    }
}
```

```c
#include <stdio.h>
#include <stdlib.h>
#include "..\..\lib\interval1D.h"

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage: %s integer(n)\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    double x,y;
    char str[100];
    Interval1D lis[n];
    for(int i = 0; i < n; i++)
    {
        while(!scanf("%lf%lf",&x,&y) == 2)
            continue;
        initInterval1D(&lis[i],x > y ? y : x,x > y ? x : y);
        if(i > 0)
            for(int j = 0; j < i; j++)
                if(intersects(&lis[j],&lis[i]))
                {
                    interval1DtoString(&lis[j],str,100);
                    printf("%s intersects ",str);
                    interval1DtoString(&lis[i],str,100);
                    printf("%s\n",str);
                }
    }
    return 0;
}
```

## 1.2.3 编写一个Interval2D的用例，从命令行接受参数N、min和max。生成N个随机的2D间隔，其宽和高均匀地分布在单位正方形中的min和max之间。用StdDraw画出它们并打印出相交的间隔对的数量以及有包含关系的间隔对数量

```java
import edu.princeton.cs.algs4.*;

public class Test1_2_3 {

    public static Interval1D ranByMinToMax(double min, double max)
    {
        double lo,hi;
        lo = StdRandom.uniformDouble(0,1 - min);
        hi = StdRandom.uniformDouble(lo + min, lo + max > 1 ? 1 : lo + max);
        return new Interval1D(lo,hi);
    }

    public static boolean contains(Interval2D a,Interval1D ix,Interval1D iy)
    {
        return a.contains(new Point2D(ix.min(),iy.min()))
                && a.contains(new Point2D(ix.min(),iy.max()))
                && a.contains(new Point2D(ix.max(),iy.min()))
                && a.contains(new Point2D(ix.max(),iy.max()));
    }

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        double min = Double.parseDouble(args[1]);
        double max = Double.parseDouble(args[2]);
        Interval2D box = new Interval2D(new Interval1D(0, 1), new Interval1D(0, 1));
        box.draw();

        StdDraw.setPenColor(StdDraw.BLUE);
        Interval2D[] list = new Interval2D[n];
        int  intersectsCnt = 0;
        int containsCnt = 0;
        for (int i = 0; i < n; i++) {
            Interval1D ix = ranByMinToMax(min,max);
            Interval1D iy = ranByMinToMax(min,max);
            list[i] = new Interval2D(ix,iy);
            list[i].draw();
            if(i > 0)
                for (int j = 0; j < i; j++) {
                    if (list[j].intersects(list[i]))
                        intersectsCnt++;
                    if(contains(list[j],ix,iy))
                        containsCnt++;
                }
        }
        System.out.printf("The intersects Interval2D count is %d\n",intersectsCnt);
        System.out.printf("The contains Interval2D count is %d\n",containsCnt);
    }
}
```

## 1.2.4 以下这段代码会打印出什么

```java
String string1 = "hello";
String string2 = string1;
string1 = "world";
StdOut.println(string1);
StdOut.println(string2);
```

```java
world
hello
```

## 1.2.5 以下这段代码会打印出什么

```java
String s = "Hello World";
s.toUpperCase();
s.substring(6, 11);
StdOut.println(s);
```

```java
Hello World
```

答："Hello World"。String对象是不可变的——所有字符串方法都会返回一个新的String对象（但它们不会改变参数对象的值）。这段代码忽略了返回的对象并直接打印了原字符串。要打印出"WORLD"，请用s = s.toUpperCase()和s =s.substring(6, 11)。

## 1.2.6 如果字符串s中的字符循环移动任意位置之后能够得到另一个字符串t，那么s就被称为t的回环变位（circular rotation）。例如，ACTGACG就是TGACGAC的一个回环变位，反之亦然。判定这个条件在基因组序列的研究中是很重要的。编写一个程序检查两个给定的字符串s和t是否互为回环变位。提示：答案只需要一行用到indexOf()、length()和字符串连接的代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * s_gets(char * st,int n);
int circulari_rotation(const char * a,const char * b);

int main(void)
{
    char a[1024];
    char b[1024];
    while(s_gets(a,1024) != NULL && a[0] != '\0' && s_gets(b,1024) != NULL && b[0] != '\0')
        if(circulari_rotation(a,b))
            printf("%s and %s is circulari totation\n",a,b);
        else
            printf("%s and %s not is circulari totation\n",a,b);
    return 0;
}

char * s_gets(char * st,int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
            *find = '\0';
        else 
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

int circulari_rotation(const char * a,const char * b)
{
    size_t alen = strlen(a);
    size_t blen = strlen(b);
    if(alen != blen)
        return 0;
    size_t strlen = alen + blen;
    char * str = malloc( (strlen + 1 ) * sizeof(char) );
    strncpy(str,b,strlen);
    strncat(str,b,blen);
    return strstr(str,a) != NULL;
}
```

## 1.2.7 以下递归函数的返回值是什么

```java
public static String mystery(String s)
{
    int N = s.length();
    if (N <= 1) return s;
    String a = s.substring(0, N/2);
    String b = s.substring(N/2, N);
    return mystery(b) + mystery(a);
}
```

s字符串的倒序

## 1.2.8 设a[ ]和b[ ]均为长数百万的整形数组。以下代码的作用是什么？有效吗

答：这段代码会将它们交换。它的效率不可能再高了，因为它复制的是引用而不需要复制数百万个元素。
