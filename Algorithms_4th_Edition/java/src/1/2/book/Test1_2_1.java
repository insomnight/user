import edu.princeton.cs.algs4.*;

import java.awt.geom.Line2D;
import java.util.Objects;

public class Test1_2_1 {

    public static void main(String[] args) {
        StdDraw.setPenRadius(.005);
        int n = Integer.parseInt(args[0]);
        Interval2D box = new Interval2D(new Interval1D(0, 1), new Interval1D(0, 1));
        box.draw();
        Point2D[] points = new Point2D[n];
        Point2D[] minP = new Point2D[2];
        double min = 0.0;
        for (int i = 0; i < n; i++) {
            points[i] = new Point2D(Math.random(),Math.random());
            points[i].draw();
            if(i == 1)
            {
                minP[0] = points[0];
                minP[1] = points[1];
                min = points[0].distanceTo(points[1]);
                System.out.println(min);
            }
            if(i > 1)
                for (int j = 0; j < i; j++) {
                    double temp = points[j].distanceTo(points[i]);
                    System.out.println(temp);
                    if(temp < min)
                    {
                        min = temp;
                        minP[0] = points[j];
                        minP[1] = points[i];
                    }
                }
        }
        StdDraw.setPenColor(StdDraw.RED);
        StdDraw.line(minP[0].x(),minP[0].y(),minP[1].x(),minP[1].y());
        System.out.println("the min distatnce is " + min);
    }
}
