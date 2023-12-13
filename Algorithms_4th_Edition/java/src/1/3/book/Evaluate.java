import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;

public class Evaluate {
    public static void main(String[] args) {
        Stack<Double> vals = new Stack<>();
        Stack<String> ops = new Stack<>();

        while(!StdIn.isEmpty())
        {
            String s = StdIn.readString();
            if("(".equals(s)) continue;
            else if ("+".equals(s)) ops.push(s);
            else if ("-".equals(s)) ops.push(s);
            else if ("*".equals(s)) ops.push(s);
            else if ("/".equals(s)) ops.push(s);
            else if ("sqrt".equals(s)) ops.push(s);
            else if (")".equals(s))
            {
                String op = ops.pop();
                double v = vals.pop();
                if ("+".equals(op)) v = vals.pop() + v;
                else if ("-".equals(op)) v = vals.pop() - v;
                else if ("*".equals(op)) v = vals.pop() * v;
                else if ("/".equals(op)) v = vals.pop() / v;
                else if ("sqrt".equals(op)) v = Math.sqrt(v);
                vals.push(v);
            }
            else vals.push(Double.parseDouble(s));
        }
        System.out.println(vals.pop());
    }
}
