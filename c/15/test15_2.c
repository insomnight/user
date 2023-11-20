/*
 * 2．编写一个程序，通过命令行参数读取两个二进制字符串，对这两个二进制数使用～运算符、&运算符、|运算符和^运算符，并以二进制字符串形式打印结果（如果无法使用命令行环境，可以通过交互式让程序读取字符串）。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * reverse_bs(char * bs);
char * and_bs(char * bs1,char * bs2);
char * or_bs(char * bs1,char * bs2);
char * xor_bs(char * bs1,char * bs2);

int main(int argc,char * argv[])
{
    char * result;
    if(argc < 3)
    {
        fprintf(stderr,"Usage: %s binary string1(1010) binary string1(1010)\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    
    result = reverse_bs(argv[1]);
    printf("~%s = %s\n",argv[1],result);
    free(result);

    result = reverse_bs(argv[2]);
    printf("~%s = %s\n",argv[2],result);
    free(result);

    result = and_bs(argv[1],argv[2]);
    printf("%s & %s = %s\n",argv[1],argv[2],result);
    free(result);

    result = or_bs(argv[1],argv[2]);
    printf("%s | %s = %s\n",argv[1],argv[2],result);
    free(result);

    result = xor_bs(argv[1],argv[2]);
    printf("%s ^ %s = %s\n",argv[1],argv[2],result);
    free(result);
    return 0;
}

char * reverse_bs(char * bs)
{
    int n = strlen(bs);
    char * reverse = "10";
    char * ret_val = malloc( n * sizeof(char) + 1);
    for(int i = 0; i < n;i++)
        if(*(bs + i) == '0' || *(bs+i) == '1')
            *(ret_val + i) = reverse[ (*(bs+i) - '0')];
        else
        {
            fprintf(stderr,"The %s is not a binary string\n",bs);
            free(ret_val);
            exit(EXIT_FAILURE);
        }
    *(ret_val + n) = '\0';
    return ret_val;
}

char * and_bs(char * bs1,char * bs2)
{
    int len1,len2,max;
    char * and = "001";
    len1 = strlen(bs1);
    len2 = strlen(bs2);
    max = len1 > len2 ? len1 : len2;
    char * nbs1 = malloc( max * sizeof(char) + 1);
    char * nbs2 = malloc( max * sizeof(char) + 1);
    nbs1[max] = '\0';
    nbs2[max] = '\0';
    for(int i = 0; i < max; i++)
    {
        if(i < len1)
        {
            if(bs1[len1-i-1] == '1' || bs1[len1-i-1] == '0')
                nbs1[max-i-1] = bs1[len1-i-1];
            else
            {
                fprintf(stderr,"The %s is not a binary string\n",bs1);
                free(nbs1);
                free(nbs2);
                exit(EXIT_FAILURE);
            } 
        }
        else
            *(nbs1+max-i-1) = '0';

        if(i < len2)
        {
            if(bs2[len2-i-1] == '1' || bs2[len2-i-1] == '0')
                nbs2[max-i-1] = bs2[len2-i-1];
            else{
                fprintf(stderr,"The %s is not a binary string\n",bs2);
                free(nbs1);
                free(nbs2);
                exit(EXIT_FAILURE);
            } 
        }
        else
            *(nbs2+max-i-1) = '0';
    }

    for(int i = 0; i < max; i++)
        nbs1[i] = and[(nbs1[i] + nbs2[i] - '0' - '0')]; 
    free(nbs2);
    return nbs1;
}

char * or_bs(char * bs1,char * bs2)
{
    char * or = "011";
    int len1,len2,max;
    len1 = strlen(bs1);
    len2 = strlen(bs2);
    max = len1 > len2 ? len1 : len2;
    char * nbs1 = malloc( max * sizeof(char) + 1);
    char * nbs2 = malloc( max * sizeof(char) + 1);
    nbs1[max] = '\0';
    nbs2[max] = '\0';
    for(int i = 0; i < max; i++)
    {
        if(i < len1)
        {
            if(bs1[len1-i-1] == '1' || bs1[len1-i-1] == '0')
                nbs1[max-i-1] = bs1[len1-i-1];
            else
            {
                fprintf(stderr,"The %s is not a binary string\n",bs1);
                free(nbs1);
                free(nbs2);
                exit(EXIT_FAILURE);
            } 
        }
        else
            *(nbs1+max-i-1) = '0';

        if(i < len2)
        {
            if(bs2[len2-i-1] == '1' || bs2[len2-i-1] == '0')
                nbs2[max-i-1] = bs2[len2-i-1];
            else{
                fprintf(stderr,"The %s is not a binary string\n",bs2);
                free(nbs1);
                free(nbs2);
                exit(EXIT_FAILURE);
            } 
        }
        else
            *(nbs2+max-i-1) = '0';
    }

    for(int i = 0; i < max; i++)
        nbs1[i] = or[(nbs1[i] + nbs2[i] - '0' - '0')]; 
    free(nbs2);
    return nbs1;
}

char * xor_bs(char * bs1,char * bs2)
{
    char * xor = "010";
    int len1,len2,max;
    len1 = strlen(bs1);
    len2 = strlen(bs2);
    max = len1 > len2 ? len1 : len2;
    char * nbs1 = malloc( max * sizeof(char) + 1);
    char * nbs2 = malloc( max * sizeof(char) + 1);
    nbs1[max] = '\0';
    nbs2[max] = '\0';
    for(int i = 0; i < max; i++)
    {
        if(i < len1)
        {
            if(bs1[len1-i-1] == '1' || bs1[len1-i-1] == '0')
                nbs1[max-i-1] = bs1[len1-i-1];
            else
            {
                fprintf(stderr,"The %s is not a binary string\n",bs1);
                free(nbs1);
                free(nbs2);
                exit(EXIT_FAILURE);
            } 
        }
        else
            *(nbs1+max-i-1) = '0';

        if(i < len2)
        {
            if(bs2[len2-i-1] == '1' || bs2[len2-i-1] == '0')
                nbs2[max-i-1] = bs2[len2-i-1];
            else{
                fprintf(stderr,"The %s is not a binary string\n",bs2);
                free(nbs1);
                free(nbs2);
                exit(EXIT_FAILURE);
            } 
        }
        else
            *(nbs2+max-i-1) = '0';
    }

    for(int i = 0; i < max; i++)
        nbs1[i] = xor[(nbs1[i] + nbs2[i] - '0' - '0')]; 
    free(nbs2);
    return nbs1;
}
