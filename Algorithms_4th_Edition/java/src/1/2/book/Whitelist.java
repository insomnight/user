import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;

public class Whitelist {

    public static void main(String[] args) {
        int[] w = In.readInts(args[0]);
        StaticSETofInts set = new StaticSETofInts(w);
        while(!StdIn.isEmpty())
        {
            int key = StdIn.readInt();
            if(!set.contains(key))
                System.out.println(key);
        }
    }
}
