/*
 * 6．设计一个位字段结构以存储下面的信息。字体ID：0～255之间的一个数；字体大小：0～127之间的一个数；对齐：0～2之间的一个数，表示左对齐、居中、右对齐；加粗：开（1）或闭（0）；斜体：开（1）或闭（0）；在一个程序中使用该结构来打印字体参数，并使用循环菜单来让用户改变参数。例如，该程序的一个运行示例如下：
 * 该程序要使用按位与运算符（&）和合适的掩码来把字体ID和字体大小信息转换到指定的范围内。
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
#define SIZE_MARK 0x7F

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

void print_font(const struct font * f);
char menu(void);
void eatline(void);
void change_font(struct font * f);
void change_size(struct font * f);
void change_alignment(struct font * f);
void toggle_bold(struct font * f);
void toggle_italic(struct font * f);
void toggle_underline(struct font * f);

int main(void)
{
    struct font f = { 1, 12, LEFT, OFF, OFF, OFF};
    char choose;
    print_font(&f);

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
        print_font(&f);
    }
    return 0;
}

void print_font(const struct font * f)
{
    printf("  ID SIZE ALIGNMENT   B   I   U\n");
    printf("%4u %4u %6s     %3s %3s %3s\n", f->id, f->size, align[f->alignment],state[f->b],state[f->i],state[f->u]);
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

void change_font(struct font * f)
{
    int newid;
    printf("Enter font id (0-255): ");
    while(scanf("%d",&newid) && newid < 0 && newid >255)
    {
        printf("not a right number.Please enter again: ");
        eatline();
    }
    eatline();
    
    f->id = (newid & ID_MARK);
}

void change_size(struct font * f)
{
    int new;
    printf("Enter font size (0-127): ");
    while(scanf("%d",&new) && new < 0 && new > 127)
    {
        printf("not a right number.Please enter again: ");
        eatline();
    }
    eatline();
    
    f->size = (new & SIZE_MARK);
}

void change_alignment(struct font * f)
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

    switch(choose)
    {
        case 'l': f->alignment = LEFT;
                break;
        case 'c': f->alignment = CENTER;
                break;
        case 'r': f->alignment = RIGHT;
        default:
                break;
    }
}

void toggle_bold(struct font * f)
{
    f->b ^= 1;
}

void toggle_italic(struct font * f)
{
    f->i ^= 1;
}

void toggle_underline(struct font * f)
{
    f->u ^=1;
}
