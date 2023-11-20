#include<stdio.h>
#include<string.h>

int main(void)
{
    char lastname[40];
    char firstname[40];
    int lastnameSize,firstnameSize;

    printf("Please enter your firstname:\n");
    scanf("%s",firstname);
    printf("Please enter your lastname:\n");
    scanf("%s",lastname);
    firstnameSize = strlen(firstname);
    lastnameSize = strlen(lastname);
    printf("%s %s\n%*d %*d",firstname,lastname,firstnameSize,firstnameSize,lastnameSize,lastnameSize);
    return 0;
}
