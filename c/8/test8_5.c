/*
 * 5．修改程序清单8.4的猜数字程序，使用更智能的猜测策略。例如，程序最初猜50，询问用户是猜大了、猜小了还是猜对了。如果猜小了，那么下一次猜测的值应是50和100中值，也就是75。如果这次猜大了，那么下一次猜测的值应是50和75的中值，等等。使用二分查找（binary search）策略，如果用户没有欺骗程序，那么程序很快就会猜到正确的答案。
 */
#include<stdio.h>

int getMedian(int num1,int num2);

int main(void)
{
    int small = 1;
    int height = 100;
    int guess = getMedian(small,height);
    char response;
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan s if it is smaller than your number else an b if it is bigger than your number.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((response = getchar()) != 'y') /* 获取响应 */
    {
        if (response == 's')
        {
            small = guess + 1;
            printf("Well, then, is it %d?\n", guess = getMedian(small,height));
        }
        else if (response == 'h')
        {
            height = guess - 1;
            printf("Well, then, is it %d?\n", guess = getMedian(small,height));
        }
        else
            printf("Sorry, I understand only y or s or h.\n");
        while (getchar() != '\n')
            continue; /* 跳过剩余的输入行 */
    }
    printf("I knew I could do it!\n");

    return 0;
}

int getMedian(int num1,int num2)
{
    return (num1 + num2) / 2;
}
