public class Test1_1_30 {

    public static int gcd(int p,int q)
    {
        if(q == 0) return p;
        int r = p % q;
        return gcd(q,r);
    }
    public static boolean[][] boolarr(int n)
    {
        boolean[][] arr = new boolean[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if(gcd(i,j) == 1)
                    arr[i][j] = true;
                else
                    arr[i][j] = false;
        return arr;
    }
}
