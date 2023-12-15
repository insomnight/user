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
