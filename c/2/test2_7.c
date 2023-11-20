#include<stdio.h>

void printSmile(void);

int main(void)
{
    for(int i = 3;i>0;i--){
        for(int j = i; j >0;j--)
            printSmile();
        printf("\n");
    }
    return 0;        
}

void printSmile(void){
    printf("Smile!");
}