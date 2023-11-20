/*
 * 2．编写一个文件拷贝程序，该程序通过命令行获取原始文件名和拷贝文件名。尽量使用标准I/O和二进制模式。
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char * argv[])
{
    FILE *source,*targe;
    size_t bytes;
    int ch;

    if(argc < 3)
    {
        fprintf(stderr,"Usage: %s sourefilename targefilename\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    if((source = fopen(argv[1],"r")) == NULL)
    {
        fprintf(stderr,"I couldn't open the file \"%s\"\n",argv[1]);
        exit(EXIT_FAILURE);
    }

    if((targe = fopen(argv[2],"w")) ==NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    while((ch = getc(source))!=EOF)
        putc(ch,targe);

    if(fclose(source) != 0 || fclose(targe) != 0)
        fprintf(stderr,"Error in closing files\n");


    return 0;
}
