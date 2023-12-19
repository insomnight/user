import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;

public class InfixToPostfix {
    public static int precede(char op)
    {
        return switch (op) {
            case '*', '/' -> 2;
            case '+', '-' -> 1;
            default -> 0;
        };
    }

    public static String RPExpression(String ex)
    {
        StringBuilder c = new StringBuilder();
        Stack<Character> stack = new Stack<>();
        char ch;
        char[] e = ex.toCharArray();
        stack.push('@');
        for (int i = 0; i < e.length; i++) {
            ch = e[i];
            if(ch == '(')
                stack.push(ch);
            else if(ch == ')') {
                while (stack.peek() != '(')
                    c.append(stack.pop());
                stack.pop();
            } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                while(precede(stack.peek()) >= precede(ch))
                    c.append(stack.pop());
                stack.push(ch);
            } else {
                while(ch >= '0' && ch <= '9')
                {
                    c.append(ch);
                    i++;
                    if(i >= e.length)
                        break;
                    ch = e[i];
                }
                i--;
                c.append(' ');
            }
        }
        while(stack.peek()!='@'){
            c.append(stack.pop());
        }
        return c.toString();
    }

    public static void main(String[] args) {
        while(!StdIn.isEmpty())
        {
            String ex = StdIn.readLine();
            String s = RPExpression(ex);
            System.out.println(s);
        }
    }
}
