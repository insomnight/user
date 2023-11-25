#include <stdio.h>
#define pf (getpf())

FILE * getpf(void);
int i = 12;

static FILE * f = NULL;

int main(void)
{
    printf("1:%d\n",i);
    fprintf(pf,"2:%d\n",i);
    printf("3:%d\n",i);
    return 0;
}

FILE * getpf(void)
{
    if(f == NULL)
        return stdout;
    else
        return f;
}
