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
