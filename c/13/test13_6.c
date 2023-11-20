/*
 * 6．使用命令行参数的程序依赖于用户的内存如何正确地使用它们。重写程序清单13.2中的程序，不使用命令行参数，而是提示用户输入所需信息。
 */
#include <stdio.h>
#include <stdlib.h>    // 提供 exit()的原型
#include <string.h>    // 提供 strcpy()、strcat()的原型
#define LEN 40

char * s_gets(char * st, int n);

int main(void)
{
     FILE  *in, *out;    // 声明两个指向 FILE 的指针
     int ch;
     char source[LEN];
     char name[LEN];     // 存储输出文件名
     int count = 0;

    
     puts("Enter name of file:\n");
     s_gets(source,LEN-4);
     // 设置输入
     if ((in = fopen(source, "r")) == NULL)
     {
          fprintf(stderr, "I couldn't open the file \"%s\"\n",
                    source);
          exit(EXIT_FAILURE);
     }
     // 设置输出
     strncpy(name, source, LEN - 5);    // 拷贝文件名
     name[LEN - 5] = '\0';
     strcat(name, ".red");                // 在文件名后添加.red
     if ((out = fopen(name, "w")) == NULL)
     {                       // 以写模式打开文件
          fprintf(stderr, "Can't create output file.\n");
          exit(3);
     }
     // 拷贝数据
     while ((ch = getc(in)) != EOF)
          if (count++ % 3 == 0)
               putc(ch, out);    // 打印3个字符中的第1个字符
     // 收尾工作
     if (fclose(in) != 0 || fclose(out) != 0)
          fprintf(stderr, "Error in closing files\n");

     return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
