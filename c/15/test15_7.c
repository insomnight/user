/*
 * 7．编写一个与编程练习6功能相同的程序，使用unsigned long类型的变量存储字体信息，并且使用按位运算符而不是位成员来管理这些信息。
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEFT 0
#define CENTER 1
#define RIGHT 2

#define OFF 0
#define ON 1

#define ID_MARK 0xFF
#define SIZE_MARK 0x7F00
#define ALIGNMENT_MARK 0x18000
#define ALIGNMENT_CENTER 0x8000
#define ALIGNMENT_RIGHT 0x10000
#define B_MARK 0x20000
#define I_MARK 0x40000
#define U_MARK 0x80000

const char * state[] = { "off" , "on" };
const char * align[] = { "left" , "center" , "right" };

struct font
{
    unsigned int id : 8;
    unsigned int size : 7;
    unsigned int :  1;
    unsigned int alignment : 2;
    unsigned int b : 1;
    unsigned int i : 1;
    unsigned int u : 1;
};

void print_font(unsigned long f);
char menu(void);
void eatline(void);
void change_font(unsigned long *f);
void change_size(unsigned long *f);
void change_alignment(unsigned long *f);
void toggle_bold(unsigned long *f);
void toggle_italic(unsigned long *f);
void toggle_underline(unsigned long *f);

int main(void)
{
    unsigned long f;
    f = 0L;
    f |= (0x1 & ID_MARK);
    f |= (12 << 8);
    char choose;
    print_font(f);

    while((choose = menu()) != 'q')
    {
        switch(choose)
        {
            case 'f': change_font(&f);
                break;
            case 's': change_size(&f); 
                break;
            case 'a': change_alignment(&f); 
                break;
            case 'b': toggle_bold(&f); 
                break;
            case 'i': toggle_italic(&f);
                break;
            case 'u': toggle_underline(&f);
                break;
            default: 
                break;
        }
        print_font(f);
    }
    return 0;
}

void print_font(unsigned long f)
{
    printf("  ID SIZE ALIGNMENT   B   I   U\n");
    printf("%4lu ",f & ID_MARK);
    printf("%4lu ",(f & SIZE_MARK ) >> 8);
    printf("%6s     ", align[(f & ALIGNMENT_MARK) >> 15]);
    printf("%3s ",state[(f & B_MARK) >> 17]);
    printf("%3s ",state[(f & I_MARK) >> 18]);
    printf("%3s \n",state[(f & U_MARK) >> 19]);
}

char menu(void)
{
    puts("f)change font    s)change size    a)change alignment");
    puts("b)toggle bold    i)toggle italic  u)toggle underline");
    puts("q)quit");
    char choose;
    choose = getchar();
    tolower(choose);
    eatline();
    while(strchr("fsabiuq",choose) == NULL)
    {
        puts("Please enter a f, s, a, b, i, u, or q:");
        tolower(choose);
        eatline();
    }
    return choose;
}

void eatline(void)
{
    while(getchar()!='\n')
        continue;
}

void change_font(unsigned long *f)
{
    unsigned long new;
    printf("Enter font id (0-255): ");
    while(scanf("%lu",&new) && new < 0L && new >255L)
    {
        printf("not a right number.Please enter again: ");
        eatline();
    }
    eatline();

    *f &= ~ID_MARK;
    *f |= (new & ID_MARK);
}

void change_size(unsigned long *f)
{
    unsigned long new;
    printf("Enter font id (0-127): ");
    while(scanf("%lu",&new) && new < 0L && new >127L)
    {
        printf("not a right number.Please enter again: ");
        eatline();
    }
    eatline();

    *f &= ~SIZE_MARK;
    *f |= ((new<<8) & SIZE_MARK);
}

void change_alignment(unsigned long *f)
{
    char choose;
    puts("select alignment:");
    puts("l)left   c)center   r)right");
    choose = getchar();
    tolower(choose);
    eatline();
    while(strchr("lcr",choose) == NULL)
    {
        puts("Please enter a l, c, or r");
        choose = getchar();
        tolower(choose);
        eatline();
    }
    
    *f &= ~ALIGNMENT_MARK;
    switch(choose)
    {
        case 'l': 
                break;
        case 'c': *f |= ALIGNMENT_CENTER;
                break;
        case 'r': *f |= ALIGNMENT_RIGHT;
        default:
                break;
    }
}

void toggle_bold(unsigned long *f)
{
    *f ^= B_MARK;
}

void toggle_italic(unsigned long *f)
{
    *f ^= I_MARK;
}

void toggle_underline(unsigned long *f)
{
    *f ^= U_MARK;
}
