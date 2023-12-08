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
