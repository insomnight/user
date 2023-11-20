#include <stdio.h>

int main(void)
{
    float downloadSpeed;
    float fileSize;
    printf("Enter the download speed in megabits per second (Mb/s):");
    scanf("%f", &downloadSpeed);
    printf("Enter the file size in megabytes (MB):");
    scanf("%f", &fileSize);
    printf("At %0.2f megabits per second, a file of %0.2f megabytes downloads in %0.2f seconds.", downloadSpeed, fileSize, fileSize * 8 / downloadSpeed);
    return 0;
}