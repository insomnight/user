import edu.princeton.cs.algs4.StdRandom;

public class Test1_1_35 {
    public static int SIDES = 6;

    public static void main(String[] args) {
        double[] dist = new double[2 * SIDES + 1];
        for (int i = 1; i <= SIDES; i++)
            for(int j = 1; i <= SIDES; j++)
                dist[i+j] += 1.0;
        for(int k = 2; k <= 2 * SIDES; k++)
            dist[k] /= 36.0;

        double[] disttest = new double[2 * SIDES + 1];
        int n = 1;
        boolean flag;
        int roll;
        do {
            flag = true;
            for (int i = 0; i < n; i++) {
                roll = StdRandom.uniformInt(1, SIDES + 1) + StdRandom.uniformInt(1, SIDES + 1);
                disttest[roll] += 1.0;
            }

            for (int i = 2; i <= 2 * SIDES; i++) {
                disttest[i] /= n;
                if (Math.abs(disttest[i] - dist[i]) >= 0.0001)
                    flag = false;
            }

        } while (!flag);
        System.out.printf("the n = %d mock data and theory beetween less 0.001\n",n);
    }
}

