/*
12．考虑下面两个无限序列：
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
编写一个程序计算这两个无限序列的总和，直到到达某次数。
提示：奇数个-1相乘得-1，偶数个-1相乘得1。让用户交互地输入指定的次数，
当用户输入0或负值时结束输入。
查看运行100项、1000项、10000项后的总和，是否发现每个序列都收敛于某值？

100
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +1.0/100.0 = 5.187378
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +1.0/100.0 = 0.688172
1000
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +1.0/1000.0 = 7.485471
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +1.0/1000.0 = 0.692647
10000 
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +1.0/10000.0 = 9.787606
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +1.0/10000.0 = 0.693097
100000
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +1.0/100000.0 = 12.090146
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +1.0/100000.0 = 0.693142
1000000
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +1.0/1000000.0 = 14.392727
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +1.0/1000000.0 = 0.693147
*/
#include<stdio.h>
double progressions_one(int n);
double progressions_two(int n);

int main(void)
{
    int n;
    while(scanf("%d",&n)){
        printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +1.0/%d.0 = %f\n",n,progressions_one(n));
        printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +1.0/%d.0 = %f\n",n,progressions_two(n));
    }
    return 0;
}

double progressions_one(int n)
{
    double sum = 0;
    for (size_t i = 1; i <= n; i++)
        sum += 1.0 / ((double) i);
    return sum;    
}

double progressions_two(int n)
{
    double sum = 0;
    int flag = 1;
    for (size_t i = 1; i <= n; i++){
        sum += 1.0 / ((double) i) * flag;
        flag *= -1;
    }
    return sum;
}