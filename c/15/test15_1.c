/*
 * 1．编写一个函数，把二进制字符串转换为一个数值。例如，有下面的语句：
 *     char * pbin = "01001001";
 *     那么把pbin作为参数传递给该函数后，它应该返回一个int类型的值73。
 */
#include <stdio.h>

int bstoi(const char * bs);

int main(void)
{
    char * pbin = "01001001";
    int num;
    num = bstoi(pbin);
    printf("%s to %d\n",pbin,num);
    return 0;
}

int bstoi(const char * bs)
{
   int i = 0;
   while(*bs)
   {
       i = i << 1 | (*bs == '0' ? 0 : 1);
       bs++;
   }
   return i;
}
