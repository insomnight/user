import edu.princeton.cs.algs4.StdRandom;

public class TestVisualAccumulator {

    public static void main(String[] args) {
        int t = Integer.parseInt(args[0]);
        VisualAccumulator a = new VisualAccumulator(t,1.0);
        for (int i = 0; i < t; i++) {
            a.addDataValue(StdRandom.uniformDouble());
        }
        System.out.println(a);
    }
}
