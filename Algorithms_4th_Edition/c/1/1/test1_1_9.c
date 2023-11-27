/*
 * 编写一段代码，将一个正整数N用二进制表示并转换为一个String类型的值s。
 */
#include <stdio.h>
#define BSIZE 100

char * itobitstr(char * bitstr,int bsize,int n);

int main(void)
{
    char bs[BSIZE];
    int n;
    while(scanf("%d",&n) == 1)
    {
        itobitstr(bs,BSIZE,n);
        printf("%d is %s\n",n,bs);
    }
    return 0;
}

char * itobitstr(char * bitstr,int bsize,int n)
{
    int top = 0;
    char temp;
    for(int i = n; i > 0; i /= 2)
    {
        bitstr[top] = '0' + i % 2;
        top++;
        if(top >= bsize)
            break;
    }
    bitstr[top] = '\0';
    for(int i = 0,j = top - 1; i < j; i++,j--)
    {
        temp = bitstr[i];
        bitstr[i] = bitstr[j];
        bitstr[j] = temp;
    }
    return bitstr;
}
