import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;

import java.util.Objects;

public class EvaluatePostfix{

    public static double computerEX(String ex)
    {
        Stack<Double> stack = new Stack<>();
        char[] e = ex.toCharArray();
        double a;
        double b;
        for (int i = 0; i < e.length; i++) {
            switch (e[i]){
                case '+':
                    b = stack.pop();
                    a = stack.pop();
                    stack.push(a + b);
                    break;
                case '-':
                    b = stack.pop();
                    a = stack.pop();
                    stack.push(a - b);
                    break;
                case '*':
                    b = stack.pop();
                    a = stack.pop();
                    stack.push(a * b);
                    break;
                case '/':
                    if(Objects.equals(stack.peek(),0.0))
                        throw new RuntimeException("除0错误!");
                    b = stack.pop();
                    a = stack.pop();
                    stack.push(a / b);
                    break;
                case ' ':
                    break;
                default:
                    a = 0;
                    while(e[i] >='0' && e[i] <= '9')
                    {
                        a = 10.0 * a + Double.parseDouble(Character.toString(e[i]));
                        i++;
                    }
                    i--;
                    stack.push(a);
            }
        }
        return stack.peek();
    }

    public static void main(String[] args) {
        while(!StdIn.isEmpty())
        {
            String s = StdIn.readLine();
            double result = computerEX(s);
            System.out.println(s + " = " + result);
        }
    }
}
