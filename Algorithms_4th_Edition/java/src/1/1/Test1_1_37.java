import edu.princeton.cs.algs4.StdRandom;

public class Test1_1_37 {

    public static void shuffle(int[] a)
    {
        int n = a.length;
        int r;
        int temp;
        for (int i = 0; i < n; i++) {
            r = StdRandom.uniformInt(n);
            temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
    public static void init_a(int[] a){
        for (int i = 0; i < a.length; i++) {
            a[i] = i;
        }
    }

    public static void main(String[] args) {
        int m,n;
        m = Integer.parseInt(args[0]);
        n = Integer.parseInt(args[1]);

        int[][] result = new int[m][m];
        int [] a = new int[m];

        for (int i = 0; i < n; i++) {
            init_a(a);
            StdRandom.shuffle(a);

            for (int j = 0; j < m; j++) {
                result[a[j]][j]++;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                System.out.printf("%d ",result[i][j]);
            }
            System.out.println();
        }
    }
}
