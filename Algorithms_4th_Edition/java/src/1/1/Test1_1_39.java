import edu.princeton.cs.algs4.StdRandom;

import java.lang.reflect.Array;
import java.util.Arrays;

public class Test1_1_39 {

    public static int rank(int key, int[] a)
    {
        int lo = 0;
        int hi = a.length - 1;
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if(key < a[mid]) hi = mid - 1;
            else if(key > a[mid]) lo = mid + 1;
            else return mid;
        }
        return -1;
    }

    public static int [] initArr(int n)
    {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = StdRandom.uniformInt(100000,1000000);
        }
        return a;
    }

    public static void main(String[] args) {
        int[] a,b;
        int[] testsize = {1000,10000,100000};
        double total;
        int t;
        t = Integer.parseInt(args[0]);

        StdRandom.setSeed(System.currentTimeMillis());
        for (int value : testsize) {
            total = 0.0;
            for (int j = 0; j < t; j++) {
                a = initArr(value);
                b = initArr(value);
                Arrays.sort(a);

                for (int i : b) {
                    if (rank(i, a) != -1)
                        total += 1.0;
                }
            }

            System.out.printf("n = %d, average = %.3f\n",value, total / t);
        }
    }
}
