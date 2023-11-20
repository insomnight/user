/*
 * 3．编写一个文件拷贝程序，提示用户输入文本文件名，并以该文件名作为原始文件名和输出文件名。该程序要使用ctype.h中的toupper()函数，在写入到输出文件时把所有文本转换成大写。使用标准I/O和文本模式。
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SLEN 81

char * s_gets(char * st,int n);

int main(void)
{ 
    FILE * fp;
    char file[SLEN];
    int ch;
    long count,last;

    puts("Enter name of file:");
    s_gets(file,SLEN);
    if((fp = fopen(file,"rb+")) == NULL)
    {
        fprintf(stderr,"Can't open %s\n",file);
        exit(EXIT_FAILURE);
    }
    
    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);
    
    for(count = 0L; count < last; count++)
    {
        fseek(fp,count,SEEK_SET);
        ch = getc(fp);
        if(ch!='\032' && ch != '\r')
        {
            fseek(fp,count,SEEK_SET);
            putc(toupper(ch),fp);
        }
    }

    if(fclose(fp))
        fprintf(stderr,"Error closing file\n");

    return 0;
}

char * s_gets(char * st,int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n ,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
            *find = '\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}
