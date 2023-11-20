#include <stdio.h>

union hold {
     int digit;
     double bigfl;
     char letter;
};

int main(void)
{
    union hold h1;
    union hold h2;
    union hold h3;
    h1.digit = 2;
    h2.bigfl = 2.0;
    h3.letter = 'c';
    printf("hold size %zd\n",sizeof(union hold));
    printf("h1 size %zd\n",sizeof(h1));
    printf("h2 size %zd\n",sizeof(h2));
    printf("h3 size %zd\n",sizeof(h3));
    return 0;
}