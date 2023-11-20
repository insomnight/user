/*
 * 10．为了让程序清单9.8中的to_binary()函数更通用，编写一个to_base_n()函数接受两个参数，且第二个参数在2～10范围内，然后以第2个参数中指定的进制打印第1个参数的数值。例如，to_base_n(129， 8)显示的结果为201，也就是129的八进制数。在一个完整的程序中测试该函数。
 */
#include<stdio.h>

int to_base_n(int, int);

int main(void)
{
    int number,base;
    while( scanf("%d%d",&number,&base) == 2)
    {
        printf("%d number the %d equivalent: %d\n",number,base,to_base_n(number,base));

    }
    return 0;
}

int to_base_n(int target, int base)
{
    if(target >= base)
        return target % base + 10 * to_base_n(target / base , base);
    else
        return target % base;
}
