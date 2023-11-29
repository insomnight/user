/*
 * 1.1.24 给出使用欧几里得算法计算105和24的最大公约数的过程中得到的一系列p和q的值。扩展该算法中的代码得到一个程序Euclid，从命令行接受两个参数，计算它们的最大公约数并打印出每次调用递归方法时的两个参数。使用你的程序计算1111111和1234567的最大公约数
 */
#include <stdio.h>
#include <stdlib.h>

int gcd(int p, int q);

int main(int argc,char *argv [])
{
    int p,q,result;
    if(argc < 3)
    {
        fprintf(stderr,"Usage: %s integer1 interger2\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    
    p = atoi(argv[1]);
    q = atoi(argv[2]);
    result = gcd(p,q);
    printf("The greatest common divisor of %d and %d is %d",p,q,result);
    return 0;
}

int gcd(int p, int q)
{
    printf("p = %d, q = %d\n",p,q);
    if(q == 0) return p;
    int r = p % q;
    return gcd(q, r);
}
