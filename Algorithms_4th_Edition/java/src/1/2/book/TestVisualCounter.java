import edu.princeton.cs.algs4.StdRandom;

public class TestVisualCounter {

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        VisualCounter vc = new VisualCounter(n, n);
        StdRandom.setSeed(System.currentTimeMillis());
        for (int i = 0; i < n; i++) {
            if(StdRandom.uniformDouble() > 0.3)
                vc.decrease();
            else
                vc.increment();
        }
        System.out.println(vc.tally());
        System.out.println(vc);
    }
}
