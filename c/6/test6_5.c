/*
5．编写一个程序，提示用户输入大写字母。
使用嵌套循环以下面金字塔型的格式打印字母：
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/
#include<stdio.h>

int main(void)
{
    char ch;
    printf("Enter a letter (inside A-Z):");
    scanf("%c",&ch);
    if(ch<'A'||ch>'Z'){
        printf("The input is error");
        return 0;
    }
    size_t max_size = ch - 'A';
    for (size_t i = 0; i <= max_size; i++)
    {
        for (size_t j = 0; j < max_size - i; j++)
            printf(" ");
        // for (char j = 'A'; j <= 'A'+i; j++)
        //     printf("%c",j);
        // for (char j = 'A'+i-1; j >= 'A'; j--)
        //     printf("%c",j);
        for (size_t j = 0; j < i * 2 + 1; j++)
            printf("%c",'A'+ (j % (i+1)));
        printf("\n");
    }
    
    return 0;
}