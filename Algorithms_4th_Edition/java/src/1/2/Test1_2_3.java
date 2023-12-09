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
