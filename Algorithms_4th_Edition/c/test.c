#include <stdio.h>
#define pf (getpf())

FILE * getpf(void);
int i = 12;

static FILE * f = NULL;

int main(void)
{
    printf("%d\n",(0+15)/2);
    printf("%.7lf\n",2.0e-6 * 100000000.1);
    printf("%d\n",(1 && 0 || 1 && 1));
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
