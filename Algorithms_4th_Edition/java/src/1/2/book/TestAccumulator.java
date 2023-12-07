import edu.princeton.cs.algs4.StdRandom;

public class TestAccumulator {

    public static void main(String[] args) {
        int t = Integer.parseInt(args[0]);
        Accumulator a = new Accumulator();
        for (int i = 0; i < t; i++) {
            a.addDataValue(StdRandom.uniformDouble());
        }
        System.out.println(a);
    }
}
