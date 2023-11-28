import edu.princeton.cs.algs4.StdOut;

import java.math.BigInteger;
import java.util.Objects;

public class Fibonacci
{
    public static BigInteger[] fb = new BigInteger[1000];
    public static BigInteger F(int N)
    {
        if (N == 0) return new BigInteger("0");
        if (N == 1) return new BigInteger("1");
        if(Objects.nonNull(fb[N])) return fb[N];
        fb[N] = F(N-1).add(F(N-2));
        return fb[N];
    }
    public static void main(String[] args)
    {
        for (int i = 0; i < 100; i++)
            StdOut.println(i + " " + F(i));
    }
}