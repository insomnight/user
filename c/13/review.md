# 13.10　复习题

## 1．下面的程序有什么问题

```c
int main(void)
{
     int * fp;
     int k;

     fp = fopen("gelatin");
     for (k = 0; k < 30; k++)
          fputs(fp, "Nanette eats gelatin.");
     fclose("gelatin");
     return 0;
}
```

根据文件定义，应包含#include <stdio.h>。应该把fp声明为文件指针：FILE *fp;。要给fopen()函数提供一种模式：fopen("gelatin","w")，或者"a"模式。fputs()函数的参数顺序应该反过来。输出字符串应该有一个换行符，提高可读性。fclose()函数需要一个文件指针，而不是一个文件名：fclose(fp);。下面是修改后的版本：

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
     int * fp;
     int k;

     if((fp = fopen("gelatin","w") )== NULL)
     {
        printf("Can't open %s\n","gelatin");
        exit(EXIT_FAILURE);
     }
     for (k = 0; k < 30; k++)
          fputs("Nanette eats gelatin.\n", fp);
     if (fclose(fp) != 0)
          fprintf(stderr, "Error closing file\n");
     return 0;
}
```

## 2．下面的程序完成什么任务？（假设在命令行环境中运行）

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv [])
{
     int ch;
     FILE *fp;
     if (argc < 2)
          exit(EXIT_FAILURE);
     if ((fp = fopen(argv[1], "r")) == NULL)
          exit(EXIT_FAILURE);
     while ((ch = getc(fp)) != EOF)
          if (isdigit(ch))
               putchar(ch);
     fclose(fp);

     return 0;
}
```

如果可以打开的话，会打开与命令行第1个参数名相同名称的文件，并在屏幕上显示文件中的每个数字字符。

## 3．假设程序中有下列语句

```c
#include <stdio.h>
FILE * fp1,* fp2;
char ch;

fp1 = fopen("terky", "r");
fp2 = fopen("jerky", "w");
```

另外，假设成功打开了两个文件。补全下面函数调用中缺少的参数：　　

```c
a．ch = getc();　　
ch = getc(fp1);

b．fprintf( ,"%c\n", );
fprintf(fp2,"%c\n",ch);
　　
c．putc( , );　　
putc(ch,fp2);

d．fclose(); /* 关闭terky文件 */
fclode(fp1);

```

## 4．编写一个程序，不接受任何命令行参数或接受一个命令行参数。如果有一个参数，将其解释为文件名；如果没有参数，使用标准输入（stdin）作为输入。假设输入完全是浮点数。该程序要计算和报告输入数字的算术平均值

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv [])
{
　　 FILE * fp;
　　 double n;
　　 double sum = 0.0;
　　 int ct = 0;

　　 if (argc == 1)
　　　　　fp = stdin;
　　 else if (argc == 2)
　　 {
　　　　　if ((fp = fopen(argv[1], "r")) == NULL)
　　　　　{
　　　　　　　 fprintf(stderr, "Can't open %s\n", argv[1]);
　　　　　　　 exit(EXIT_FAILURE);
　　　　　}
　　 }
　　 else
　　 {
　　　　　fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
　　　　　exit(EXIT_FAILURE);
　　 }
　　 while (fscanf(fp, "%lf", &n) == 1)
　　 {
　　　　　sum += n;
　　　　　　　 ++ct;
　　 }
　　 if (ct > 0)
　　　　　printf("Average of %d values = %f\n", ct, sum / ct);
　　 else
　　　　　printf("No valid data.\n");

　　 return 0;
}
```

## 5．编写一个程序，接受两个命令行参数。第1个参数是字符，第2个参数是文件名。要求该程序只打印文件中包含给定字符的那些行

```c
#include <stdio.h>
#include <stdlib.h>
#define BUF 256
int has_ch(char ch, const char * line);
int main(int argc, char * argv [])
{
　　 FILE * fp;
　　 char ch;
　　 char line[BUF];

if (argc != 3)
　　 {
　　　　　printf("Usage: %s character filename\n", argv[0]);
　　　　　exit(EXIT_FAILURE);
　　 }
　　 ch = argv[1][0];
　　 if ((fp = fopen(argv[2], "r")) == NULL)
　　 {
　　　　　printf("Can't open %s\n", argv[2]);
　　　　　exit(EXIT_FAILURE);
　　 }
　　 while (fgets(line, BUF, fp) != NULL)
　　 {
　　　　　if (has_ch(ch, line))
　　　　　　　 fputs(line, stdout);
　　 }
　　 fclose(fp);
　　 return 0;
}
int has_ch(char ch, const char * line)
{
　　while (*line)
　　　 if (ch == *line++)
　　　　　 return(1);
　　return 0;
}
```

## 6．二进制文件和文本文件有何区别？二进制流和文本流有何区别

二进制文件与文本文件的区别是，这两种文件格式对系统的依赖性不同。二进制流和文本流的区别包括是在读写流时程序执行的转换（二进制流不转换，而文本流可能要转换换行符和其他字符）。

## 7

- a．分别用fprintf()和fwrite()存储8238201有何区别？

用fprintf()存储8238201时，将其视为7个字符，保存在7字节中。用fwrite()存储时，使用该数的二进制表示，将其存储为一个4字节的整数。

- b．分别用putc()和fwrite()存储字符S有何区别？

没有区别。两个函数都将其存储为一个单字节的二进制码。

## 8．下面语句的区别是什么

```c
printf("Hello, %s\n", name);
fprintf(stdout, "Hello, %s\n", name);
fprintf(stderr, "Hello, %s\n", name);
```

第1条语句是第2条语句的速记表示。第3条语句把消息写到标准错误上。通常，标准错误被定向到与标准输出相同的位置。但是标准错误不受标准输出重定向的影响。

## 9．"a+"、"r+"和"w+"模式打开的文件都是可读写的。哪种模式更适合用来更改文件中已有的内容

可以在以"r+"模式打开的文件中读写，所以该模式最合适。"a+"只允许在文件的末尾添加内容。"w+"模式提供一个空文件，丢弃文件原来的内容。
