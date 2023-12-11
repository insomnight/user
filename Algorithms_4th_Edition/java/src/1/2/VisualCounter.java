import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdRandom;

public class VisualCounter {

    private int count;

    private int value;

    public VisualCounter(int n, int max) {
        StdDraw.setXscale(0,n);
        StdDraw.setYscale(-max,max);
        StdDraw.setPenRadius(.005);
    }

    public void increment()
    {
        count++;
        value++;
        StdDraw.point(count,value);
    }

    public void decrease()
    {
        count++;
        value--;
        StdDraw.point(count,value);
    }

    public int tally()
    {return value;}

    @Override
    public String toString() {
        return "[" + count+", "+value+"]";
    }
}
