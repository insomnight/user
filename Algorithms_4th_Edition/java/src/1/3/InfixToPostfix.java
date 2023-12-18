import edu.princeton.cs.algs4.Stack;

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
        int j = 0;
        char ch;
        char[] e = ex.toCharArray();
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
            }
        }
        return c.toString();
    }
}
