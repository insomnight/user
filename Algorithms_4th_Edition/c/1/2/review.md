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
