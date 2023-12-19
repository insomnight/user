# 算法4 1.3 背包、队列和栈

## 1.3.1 为FixedCapacityStackOfStrings添加一个方法isFull

```java
public boolean isFull()
{return a.length() == N;}
```

```c
int isFull( FixedCapacityStackOfStrings * fp)
{
    return f->n == fp->cap;
}
```

## 1.3.2 给定以下输入，java Stack的输出是什么

```java
it was - the best - of times - - - it was - the - -
```

输出:

```java
was best times of the was the it (1 left on stack)
```

## 1.3.3 假设某个用例程序会进行一系列入栈和出栈的混合栈操作。入栈操作会将整数0到9按顺序压入栈；出栈操作会打印出返回值。下面哪种序列是不可能产生的

```java
a. 4 3 2 1 0 9 8 7 6 5
b. 4 6 8 7 5 3 2 9 0 1
c. 2 5 6 7 4 8 9 3 1 0
d. 4 3 2 1 0 5 6 7 8 9
e. 1 2 3 4 5 6 9 8 7 0
f. 0 4 6 5 3 8 1 7 2 9
g. 1 4 7 9 8 6 5 3 0 2
h. 2 1 4 3 6 5 8 7 9 0

b不可能，因为01都在栈中，0比1一定先进栈，01的出栈顺序不可能出现
f不可能, 3进栈出栈了,21同时在栈中，不可能12出栈顺序
g不可能, 0 2出栈顺序
```

## 1.3.4 编写一个Stack的用例Parentheses，从标准输入中读取一个文本流并使用栈判定其中的括号是否配对完整。例如，对于 [ ( ) ] { } { [ ( )( ) ] ( ) }程序应该打印true，对于[ ( ] ) 则打印false

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "..\..\lib\stack.h"
#define CLEN 2056

char * s_gets(char *st, int n);
int isParentheses(char *st);

int main(void)
{
    char line[CLEN];
    while(s_gets(line,CLEN) != NULL && line[0] != '\0')
        printf("%s %s parentheses\n",line, isParentheses(line) ? "is" : "not");
    return 0;
}

char * s_gets(char *st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

int isParentheses(char *st)
{
    Stack cs;
    InitializeStack(&cs);

    char * ps;
    char popitem;
    ps = st;
    while(*ps != '\0')
    {
        if(*ps == '(' || *ps == '[' || *ps == '{')
            Push(*ps,&cs);
        else if(*ps == ')' && Pop(&popitem, &cs) && popitem != '(')
            return 0;
        else if(*ps == ']' && Pop(&popitem, &cs) && popitem != '[')
            return 0;
        else if(*ps == '}' && Pop(&popitem, &cs) && popitem != '{')
            return 0;
        ps++;
    }
    return EmptyStack(&cs);
}
```

```java
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
```

## 1.3.5 当N为50时下面这段代码会打印什么？从较高的抽象层次描述给定正整数N时这段代码的行为

```java
Stack＜Integer＞ stack = new Stack＜Integer＞();

while (N > 0)
{
    stack.push(N % 2);
    N = N / 2;
}
for (int d : stack) StdOut.print(d);
StdOut.println();
```

答：打印N的二进制表示（当N为50时打印110010）。

## 1.3.6 下面这段代码对队列q进行了什么操作

```java
Stack＜String＞ stack = new Stack＜String＞();
while (! q.isEmpty())
stack.push(q.dequeue());
while (! stack.isEmpty())
q.enqueue(stack.pop());
```

这段代码对队列q进行了倒序操作

## 1.3.7 为Stack添加一个方法peek()，返回栈中最近添加的元素（而不弹出它

```c
/* 访问最新加入栈的元素,不删除 */
bool peek(Item *pitem,const Stack * ps)
{
    if(EmptyStack(ps))
        return false;
    CopyToItem(ps->items[ps->top-1],pitem);
    return true;
}
```

```java
Item peek()
{
    if(isEmpty()) throw new NoSuchElementException("Stack underfolow");
    return first.item;
}
```

## 1.3.8 给定以下输入，给出DoublingStackOfStrings的数组的内容和大小

```java
it was - the best - of times - - - it was - the - -
```

![push()和pop()操作中数组大小调整的轨迹见表](test1_3_8.png "push()和pop()操作中数组大小调整的轨迹见表")

## 1.3.9 编写一段程序，从标准输入得到一个缺少左括号的表达式并打印出补全括号之后的中序表达式

例如，给定输入：

```java
1 + 2 ) ＊ 3-4 ) ＊ 5-6 ) ) )
```

你的程序应该输出：

```java
( ( 1 + 2 ) ＊ ( ( 3-4 ) ＊ ( 5-6 ) ) )
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "..\..\lib\stack.h"
#include "..\..\lib\LinkedString.h"
#define CLEN 2056

char * s_gets(char * st, int n);
void putch(char ch);

int main(void)
{
    char st[CLEN];
    char *pc;
    Stack nums;
    Stack ops;
    while(s_gets(st, CLEN) != NULL && st[0] != '\0')
    {
        InitializeStack(&nums);
        InitializeStack(&ops);
        pc = st;
        String num;
        initString(&num);
        String op;
        initString(&op);
        while(*pc != '\0')
        {
            if(isspace(*pc))
                ;
            else if(isdigit(*pc))
                appendChar(&num,*pc);
            else if(*pc == '+' || *pc == '-' || *pc == '/' || *pc == '*')
            {
                if(!stringIsEmpty(&num))
                {
                    Push(num,&nums);
                    initString(&num);
                } 
                appendChar(&op,*pc);
                Push(op,&ops);
                initString(&op);
            }else if (*pc == ')')
            {
                if(!stringIsEmpty(&num))
                {
                    Push(num,&nums);
                    initString(&num);
                }
                String a;
                initString(&a);
                String b;
                initString(&b);
                Pop(&b,&nums);
                Pop(&a,&nums);
                addFirst(&a,'(');
                appendChar(&b,')');
                Pop(&op,&ops);
                append(&a,&op);
                append(&a,&b);
                Push(a,&nums);
                initString(&op);
            }else if (*pc == '}')
            {
                if(!stringIsEmpty(&num))
                {
                    Push(num,&nums);
                    initString(&num);
                }
                String a;
                initString(&a);
                String b;
                initString(&b);
                Pop(&b,&nums);
                Pop(&a,&nums);
                addFirst(&a,'{');
                appendChar(&b,'}');
                Pop(&op,&ops);
                append(&a,&op);
                initString(&op);
                append(&a,&b);
                Push(a,&nums);
            }else if (*pc == ']')
            {
                if(!stringIsEmpty(&num))
                {
                    Push(num,&nums);
                    initString(&num);
                }
                String a;
                initString(&a);
                String b;
                initString(&b);
                Pop(&b,&nums);
                Pop(&a,&nums);
                addFirst(&a,'[');
                appendChar(&b,']');
                Pop(&op,&ops);
                append(&a,&op);
                initString(&op);
                append(&a,&b);
                Push(a,&nums);
            }
            pc++;
        }
        
        peek(&num,&nums);
        stringTraverse(&num,putch);
        putchar('\n');
    }
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

void putch(char ch)
{
    putchar(ch);
}
```

```java
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
```

## 1.3.10 编写一个过滤器InfixToPostfix，将算术表达式由中序表达式转为后序表达式

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CLEN 2056

char * s_gets(char * st, int n);

void trans(char * ex,char * str,int n);

int main(void)
{
    char st[CLEN];
    char ex[CLEN];
    while(s_gets(st, CLEN) != NULL && st[0] != '\0')
    {
        trans(ex,st,CLEN);
        printf("%s\n",ex);
    }
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

void trans(char * ex,char *str,int n)
{
    char stack[n];
    char *pc;
    pc = str;
    int top = 0, t = 0;
    while(*pc != '\0')
    {
        switch(*pc)
        {
            case '(':
                stack[top++] = *pc;
                break;
            case ')':
                while(stack[top - 1]!='(')
                {
                    ex[t] = stack[--top];
                    t++;
                }
                top--;
                break;
            case '+':
            case '-':
                while(top != 0 && stack[top - 1] != '(')
                {
                    ex[t] = stack[--top];
                    t++;
                }
                stack[top++] = *pc;
                break;
            case '*':
            case '/':
                while(stack[top - 1] == '*' || stack[top - 1] == '/')
                {
                    ex[t] = stack[--top];
                    t++;
                }
                stack[top++] = *pc;
                break;
            case ' ':
                break;
            default:
                while(*pc >= '0' && *pc <= '9')
                {
                    ex[t] = *pc;
                    t++;
                    pc++;
                }
                pc--;
                ex[t]=' ';
                t++;
        }
        pc++;
    }
    while(top!=0)
    {
        ex[t] = stack[--top];
        t++;
    }
    ex[t] ='\0';
}
```

```java
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
```

## 1.3.11 编写一段程序EvaluatePostfix，从标准输入中得到一个后序表达式，求值并打印结果（将上一题的程序中得到的输出用管道传递给这一段程序可以得到和Evaluate相同的行为

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEN 2056

char * s_gets(char * st, int n);
double compvalue(char * ex);

int main(void)
{
    char str[CLEN];
    double a;
    while(s_gets(str,CLEN) != NULL && str[0] != '\0')
    {
        a = compvalue(str);
        printf("%s = %lf\n",str,a);
    }
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

double compvalue(char * ex)
{
    double stack[CLEN],d;
    char *ch;
    int top = 0;
    ch = ex;
    while(*ch != '\0')
    {
        switch(*ch)
        {
            case '+':
                stack[top - 1] = stack[top - 1] + stack[top];
                top--;
                break;
            case '-':
                stack[top - 1] = stack[top - 1] - stack[top];
                top--;
                break;
            case '*':
                stack[top - 1] = stack[top - 1] * stack[top];
                top--;
                break;
            case '/':
                if(stack[top] == 0)
                {
                    fprintf(stderr,"\n\t除零错误!\n");
                    exit(EXIT_FAILURE);
                }
                stack[top - 1] = stack[top - 1] / stack[top];
                top--;
                break;
            case ' ':
                break;
            default:
                d = 0;
                while(*ch >= '0' && *ch <= '9')
                {
                    d = 10.0 * d + *ch - '0';
                    ch++;
                }
                ch--;
                top++;
                stack[top] = d;
        }
        ch++;
    }
    return stack[top];
}
```

```java
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
```

## 1.3.12 编写一个可迭代的Stack用例，它含有一个静态的copy()方法，接受一个字符串的栈作为参数并返回该栈的一个副本。注意：这种能力是迭代器价值的一个重要体现，因为有了它我们无需改变基本API就能够实现这种功能

```c
#include <stdio.h>
#include <stdlib.h>
#include "..\..\lib\stack.h"

Stack * copy(Stack * dest, Stack * sour);

int main(void)
{
    Stack one;
    InitializeStack(&one);
    Stack two;
    InitializeStack(&two);
    Push(0.0,&one);
    Push(0.1,&one);
    Push(2.0,&one);
    Push(0.3,&one);
    Iterator i;
    initIterator(&i, &one);
    while(hasNext(&i))
        printf("%lf\n",next(&i));

    copy(&two,&one);

    initIterator(&i, &two);
    while(hasNext(&i))
        printf("%lf\n",next(&i));

    return 0;
}

Stack * copy(Stack * dest, Stack * sour)
{
    Stack temp;
    InitializeStack(&temp);
    Iterator i;
    initIterator(&i, sour);
    InitializeStack(dest);
    while(hasNext(&i))
        Push(next(&i),&temp);
    initIterator(&i, &temp);
    while(hasNext(&i))
        Push(next(&i),dest);
    return dest;
}
```
