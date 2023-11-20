/*
4．编写一个程序，提示用户输入一个身高（单位：厘米），
并分别以厘米和英尺、英寸为单位显示该值，允许有小数部分。
程序应该能让用户重复输入身高，直到用户输入一个非正值。其输出示例如下：
Enter a height in centimeters: 182
182.0 cm = 5 feet, 11.7 inches
Enter a height in centimeters (<=0 to quit): 168.7
168.7 cm = 5 feet, 6.4 inches
Enter a height in centimeters (<=0 to quit): 0
bye
*/
#include<stdio.h>
#define CM_PER_INCH 2.54
#define INCH_PER_FEET 12
int main(void)
{
    double cm,inches,left;
    int feet;
    printf("Enter a height in centimeters: ");
    scanf("%lf",&cm);
    while(cm > 0){
        inches = cm / CM_PER_INCH;
        feet = inches /INCH_PER_FEET;
        left = inches - feet * INCH_PER_FEET;
        printf("%0.1f cm = %0d feet, %0.1f inches\n",cm,feet,left);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%lf",&cm);
    }
    printf("bye");
    return 0;
}