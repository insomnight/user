#include<stdio.h>

int main(void)
{
    //整数溢出
    int i = 2147483647;
    unsigned int j = 4294967295;

    printf("%d %d %d\n",i,i+1,i+2);
    printf("%u %u %u\n",j,j+1,j+2);

    //浮点数上溢
    float toobig = 3.4E38 * 100.0f;
    printf("%e\n", toobig);

    //浮点数下溢
    float low =3.4E38f;
    while(1){
        low = low /2;
        printf("%e\n", low);
    }
    return 0;
}