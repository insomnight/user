#include<stdio.h>

void jolly(void);
void deny(void);

int main(void)
{
    jolly();
    deny();
}

void jolly(void){
    for(int i = 0; i < 3;i++){
        printf("For he's a jolly good fellow!\n");
    }
}

void deny(void){
    printf("Which nobody can deny!\n");
}