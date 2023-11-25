/*
 * 输入处理
 * 功能:对文件读取不同的数据类型
 */
#ifndef IN_H_
#define IN_H_

typedef struct int_array{
    int * data;
    int length;
} int_arr;

/*
 * Reads all intergers from a file and returns them as an array of ints.
 * Params: iap - 整形数组结构指针
 * Params: filename - the name of the file
 * Returns: the ints in the file
 */
int_arr * readInts(int_arr * iap,const char * filename);

#endif
