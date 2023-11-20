/*
1．编写一个程序，创建一个包含26个元素的数组，
并在其中存储26个小写字母。然后打印数组的所有内容。
*/
#include<stdio.h>
#define SIZE 26
int main(void)
{
    char alphabets[SIZE];
    for (size_t i = 0,ch = 'a'; i < SIZE; i++)
        alphabets[i] = ch + i;
    
    for (size_t i = 0; i < SIZE; i++)
        printf("%c%c",alphabets[i],(i+1)%5==0?'\n':' ');    
    return 0;
}