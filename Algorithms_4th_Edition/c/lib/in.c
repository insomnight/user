/*
 * 输入处理实现
 * 功能:对文件读取不同的数据类型
 */
#include <stdio.h>
#include <stdlib.h>
#include "in.h"

/*
 * Reads all intergers from a file and returns them as an array of ints.
 * Params: filename - the name of the file
 * Returns: the ints in the file
 */
int_arr * readInts(int_arr * iap,const char * filename)
{
    FILE * fp;
    int cnt = 0;
    int * arr;
    int num;
    if((fp = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"%s , %d: can't open file %s\n",__FILE__,__LINE__,filename);
        exit(EXIT_FAILURE);
    }
    while(fscanf(fp,"%d",&num) == 1)
        cnt++;
    
    arr = (int *) malloc(sizeof(int) * cnt);
    if(arr == NULL)
    {
        fprintf(stderr,"%s , %d: can't apply the malloc",__FILE__,__LINE__);
        exit(EXIT_FAILURE);
    }
    
    rewind(fp);

    for(int i = 0 ; i < cnt; i++)
        fscanf(fp,"%d",arr + i);
    fclose(fp);
    iap->data = arr;
    iap->length = cnt;
    return iap;
}
