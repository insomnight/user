import edu.princeton.cs.algs4.StdDraw;

public class VisualAccumulator {
    private int n;
    private double total;

    public VisualAccumulator(int trials, double max) {
        StdDraw.setXscale(0,trials);
        StdDraw.setYscale(0,max);
        StdDraw.setPenRadius(.005);
    }

    public void addDataValue(double val)
    {
        n++;
        total += val;
        StdDraw.setPenColor(StdDraw.GRAY);
        StdDraw.point(n,val);
        StdDraw.setPenColor(StdDraw.RED);
        StdDraw.point(n,mean());
    }

    public double mean()
    {
        return total / n;
    }

    @Override
    public String toString() {
        return "Mean(" + n + " values): " + String.format("%7.5f",mean());
    }
}
