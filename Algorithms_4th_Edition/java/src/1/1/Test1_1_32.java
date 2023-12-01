import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdIn;

public class Test1_1_32 {

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        double l = Double.parseDouble(args[1]);
        double r = Double.parseDouble(args[2]);
        if(l > r)
            throw new IllegalArgumentException("the argument is not right: " + l +" > " + r);

        int[] stats = new int[n];
        int max = 0;
        while(!StdIn.isEmpty())
        {
            double num = StdIn.readDouble();
            if(num < l || num >= r)
                continue;
            int index = (int) ( (num - l) / (r - l) * n );
            System.out.printf("num = %f, index = %d\n", num, index);
            stats[index]++;
            if(stats[index] > max)
                max = stats[index];
        }

        StdDraw.setXscale(0.0,1.0);
        StdDraw.setYscale(0.0,max + 1);
        for (int i = 0; i < n; i++) {
            double x = 1.0 * (i + 1) / ( n + 1);
            double y = stats[i] / 2.0;
            double rw =  0.5 / n / 2;
            double rh = stats[i] / 2.0;
            StdDraw.filledRectangle(x,y,rw,rh);
        }
    }
}
