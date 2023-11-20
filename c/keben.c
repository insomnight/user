/* strcnvt.c -- 使用 strtol()  */
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#define LIM 30
char * s_gets(char * st, int n);

int main()
{
    setlocale(LC_ALL,"");
     wchar_t ch= L'我';

     wprintf(L"我是%lc\n",ch);
     return 0;
}

char * s_gets(char * st, int n)
{
     char * ret_val;
     int i = 0;

     ret_val = fgets(st, n, stdin);
     if (ret_val)
     {
          while (st[i] != '\n' && st[i] != '\0')
               i++;
          if (st[i] == '\n')
               st[i] = '\0';
          else
               while (getchar() != '\n')
                     continue;
     }
     return ret_val;
}
