/*
 * 10．编写一个程序打开一个文本文件，通过交互方式获得文件名。通过一个循环，提示用户输入一个文件位置。然后该程序打印从该位置开始到下一个换行符之前的内容。用户输入负数或非数值字符可以结束输入循环。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 256

char * s_gets(char * st, int n);

int main(void)
{
    FILE * fp;
    char file[SLEN];
    long max,count;
    long last;
    int ch;
    long find;

    puts("Enter name of destinantion file:");
    s_gets(file,SLEN);
    
    if((fp = fopen(file,"rb")) == NULL)
    {
        fprintf(stderr,"Can't open %s\n",file);
        exit(EXIT_FAILURE);
    }
    
    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);

    max = 0L;
    for(long i = 0L; i < last; i++)
    {
        fseek(fp,i,SEEK_SET);
        ch = getc(fp);
        if(ch !='\032' && ch != '\r')
            max++;
    }
    
    printf("Enter 0 - %ld:",max);
    while(scanf("%ld",&find) && find >= 0 )
    {
        count = 0L;
        for(long i = 0L; i < last; i++)
        {
            fseek(fp,i,SEEK_SET);
            ch = getc(fp);
            if(ch != '\032' && ch != '\r')
            {
                if(count >= find)
                    putchar(ch);
                count++;
            }
        }
        printf("Enter 0 - %ld:",max);
    }
        
    fclose(fp);
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
