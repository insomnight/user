/*
 * 1．修改程序清单13.1中的程序，要求提示用户输入文件名，并读取用户输入的信息，不使用命令行参数。
 */
#include <stdio.h>
#include <stdlib.h>
#define SLEN 81

int main(void)
{
    int ch;
    FILE *fp;
    char file[SLEN]; 
    unsigned long count = 0;
    puts("Enter the name of the file to be processed:");
    scanf("%80s",file);
    if((fp = fopen(file,"r")) == NULL)
    {
        printf("Can't open %s\n",file);
        exit(EXIT_FAILURE);
    }

    while((ch =getc(fp)) != EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu charaters\n",file,count);

    return 0;
}
