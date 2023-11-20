# 8.10　复习题

## 1．putchar(getchar())是一个有效表达式，它实现什么功能？getchar(putchar())是否也是有效表达式

- 表达式putchar(getchar())使程序读取下一个输入字符并打印出来。getchar()的返回值是putchar()的参数。但getchar(putchar())是无效的表达式，因为getchar()不需要参数，而putchar()需要一个参数。

## 2．下面的语句分别完成什么任务

- a．putchar('H');

```c
显示字符H
```

- b．putchar('\007');

```c
如果系统使用ASCII,则发出一声警报
```

- c．putchar('\n');

```c
把光标移至下一行的开始
```

- d．putchar('\b');

```c
退后一格
```

## 3．假设有一个名为count的可执行程序，用于统计输入的字符数。设计一个使用count程序统计essay文件中字符数的命令行，并把统计结果保存在essayct文件中

```c
count <essay >essayct
```

## 4. 给定复习题3中的程序和文件,下列哪一条是有效的命令

```c
a. essayct <essay
```

```c
b. count essay
```

```c
c．essay >count
```

- 都不是有效命令

## 5．EOF是什么

- 5．EOF是由getchar()和scanf()返回的信号（一个特殊值），表明函数检测到文件结尾。

## 6. 对于给定的输入（ch是int类型，而且是缓冲输入），下面各程序段的输出分别是什么

- a．输入如下：

```c
If you quit, I will.[enter]
```

- 程序段如下:
  
```c
while ((ch = getchar()) != 'i')
    putchar(ch);
```

- 输出如下：

```c
If you qu
```

- b.输入如下:

```c
Harhar[enter]
```

- 程序段如下:

```c
while ((ch = getchar()) != '\n')
{
    putchar(ch++);
    putchar(++ch);
}
```

- 输出如下:

```c
HJacrthjacrt
```

## 7．C如何处理不同计算机系统中的不同文件和换行约定

C的标准I/O库把不同的文件映射为统一的流来统一处理。

## 8．在使用缓冲输入的系统中，把数值和字符混合输入会遇到什么潜在的问题

数值输入会跳过空格和换行符，但是字符输入不会。假设有下面的代码：

```c
int score;
char grade;
printf("Enter the score.\n");
scanf("%s", &score);
printf("Enter the letter grade.\n");
grade = getchar();
```

如果输入分数98，然后按下Enter键把分数发送给程序，其实还发送了一个换行符。这个换行符会留在输入序列中，成为下一个读取的值（grade）。如果在字符输入之前输入了数字，就应该在处理字符输入之前添加删除换行符的代码。
