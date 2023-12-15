import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;

import java.util.Objects;

public class Parentheses {
    public static boolean parent(String s)
    {
        Stack<Character> st = new Stack<>();
        char[] charArray = s.toCharArray();
        for (int i = 0; i < charArray.length; i++) {
           if(charArray[i] == '(' || charArray[i] == '{' || charArray[i] == '[' )
               st.push(charArray[i]);
           else if (charArray[i] == ')' && !Objects.equals('(',st.pop()))
               return false;
           else if (charArray[i] == '}' && !Objects.equals('{',st.pop()))
               return false;
           else if (charArray[i] == ']' && !Objects.equals('[',st.pop()))
               return false;
        }
        return st.isEmpty();
    }

    public static void main(String[] args) {
        while(!StdIn.isEmpty()) {
            String s = StdIn.readLine();
            System.out.printf("%s %s parentheses!\n", s, parent(s) ? "is" : "not");
        }
    }
}
