import edu.princeton.cs.algs4.StdOut;

public class Main {
    public static String exR1(int n)
    {
        if(n <=0) return "";
        return exR1(n-3) + n + exR1(n-2) + n;
    }

    public static int mystery(int a,int b)
    {
        if(b == 0) return 1;
        if(b % 2 == 0) return mystery(a*a,b/2);
        return mystery(a*a,b/2) * a;
    }
    public static void main(String[] args) {
        System.out.println(mystery(2,25));
        System.out.println(mystery(3,11));
    }
}