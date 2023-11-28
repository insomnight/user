import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Test1_1_21 {
    public static void main(String[] args) {
        String name;
        int a,b;
        while(!StdIn.isEmpty())
        {
            name = StdIn.readString();
            a = StdIn.readInt();
            b = StdIn.readInt();
            StdOut.printf("%-20s %-10d %-10d %10.3f\n",name,a,b,(double) a / b);
        }
    }
}
