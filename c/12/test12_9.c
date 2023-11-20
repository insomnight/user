/*
 * 9．编写一个符合以下描述的函数。首先，询问用户需要输入多少个单词。然后，接收用户输入的单词，并显示出来，使用malloc()并回答第1个问题（即要输入多少个单词），创建一个动态数组，该数组内含相应的指向char的指针（注意，由于数组的每个元素都是指向char的指针，所以用于存储malloc()返回值的指针应该是一个指向指针的指针，且它所指向的指针指向char）。在读取字符串时，该程序应该把单词读入一个临时的char数组，使用malloc()分配足够的存储空间来存储单词，并把地址存入该指针数组（该数组中每个元素都是指向char的指针）。然后，从临时数组中把单词拷贝到动态分配的存储空间中。因此，有一个字符指针数组，每个指针都指向一个对象，该对象的大小正好能容纳被存储的特定单词。下面是该程序的一个运行示例：
 How many words do you wish to enter? 5
 Enter 5 words now:
 I enjoyed doing this exercise
 Here are your words:
 I
 enjoyed
 doing
 this
 exercise

 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int size;
    char linshi[2048];
    printf("How many words do you wish to enter? ");
    scanf("%d",&size);
    char ** arr;
    
    arr = (char **) malloc( size * sizeof(char *));

    printf("Enter %d words now:\n", size);

    for(int i = 0; i < size ; i++)
    {
        scanf("%s", linshi);
        arr[i] = malloc( ( strlen(linshi) + 1 ) * sizeof(char));
        strcpy(arr[i],linshi);
    }

    puts("Here are your words:");
    for(int i = 0; i < size; i++)
        puts(arr[i]);
    return 0;
}
