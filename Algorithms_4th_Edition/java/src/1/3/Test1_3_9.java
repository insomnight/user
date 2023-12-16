import edu.princeton.cs.algs4.StdIn;

import java.util.Objects;
import java.util.Stack;

public class Test1_3_9 {
    public static void main(String[] args) {
        Stack<String> ops = new Stack<>();
        Stack<String> nums = new Stack<>();
        while(!StdIn.isEmpty())
        {
            String s = StdIn.readString();
            if(Objects.equals("+",s)  || Objects.equals("-",s) || Objects.equals("*",s) || Objects.equals("/",s))
                ops.push(s);
            else if(Objects.equals(")",s))
            {
                String num1 = nums.pop();
                String result ="( " + nums.pop() +" " + ops.pop() + " " + num1 + " )";
                nums.push(result);
            }else
                nums.push(s);
        }
        System.out.println(nums.peek());
    }
}
