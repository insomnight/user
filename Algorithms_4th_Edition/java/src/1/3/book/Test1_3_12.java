import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;


public class Test1_3_12 {
    public static Stack<String> copy(Stack<String> sour)
    {
        Stack<String> temp = new Stack<>();
        Stack<String> result = new Stack<>();
        sour.forEach(temp::push);
        temp.forEach(result::push);
        return result;
    }

    public static void main(String[] args) {
        Stack<String> s = new Stack<>();
        while(!StdIn.isEmpty())
        {
            s.push(StdIn.readString());
        }
        Stack<String> copy = copy(s);
        copy.forEach(System.out::println);
    }
}
