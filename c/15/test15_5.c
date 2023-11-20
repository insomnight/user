/*
 * 5．编写一个函数，把一个unsigned int类型值中的所有位向左旋转指定数量的位。例如，rotate_l(x, 4)把x中所有位向左移动4个位置，而且从最左端移出的位会重新出现在右端。也就是说，把高阶位移出的位放入低阶位。在一个程序中测试该函数。
 */
#include <stdio.h>

unsigned int rotate_l(unsigned int n,unsigned int b);

int main(void)
{
    unsigned int num,b,result;
    while(scanf("%u%u", &num, &b) == 2)
    {
        result = rotate_l(num,b);
        printf("%u retate %u = %u\n",num,b,result);
    }
    return 0;
}

unsigned int rotate_l(unsigned int n,unsigned int b)
{
    unsigned int mark = 1;
    int size = sizeof(unsigned int) * 8 - 1;
    for(int i = 0; i < b; i++)
        n = (n  << 1) | (n >> size & mark);
    return n;
}
