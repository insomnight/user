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
