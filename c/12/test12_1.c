/*
 * 1．不使用全局变量，重写程序清单12.4。
 */
/* global.c  -- 使用外部变量 */
#include <stdio.h>
int critic(int * u);
int main(void)
{
    int units;
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must have looked it up!\n");

    return 0;
}

int critic(int * u)
{
    /* 删除了可选的重复声明 */
    printf("No luck, my friend. Try again.\n");
    return scanf("%d", u);
}
