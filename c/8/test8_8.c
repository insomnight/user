/*
 * 8．编写一个程序，显示一个提供加法、减法、乘法、除法的菜单。获得用户选择的选项后，程序提示用户输入两个数字，然后执行用户刚才选择的操作。该程序只接受菜单提供的选项。程序使用float类型的变量存储用户输入的数字，如果用户输入失败，则允许再次输入。进行除法运算时，如果用户输入0作为第2个数（除数），程序应提示用户重新输入一个新值。该程序的一个运行示例如下：
Enter the operation of your choice:
a. add           s. subtract
m. multiply      d. divide
q. quit
a
Enter first number: 22 .4
Enter second number: one
one is not an number.
Please enter a number, such as 2.5, -1.78E8, or 3: 1
22.4 + 1 = 23.4
Enter the operation of your choice:
a. add           s. subtract
m. multiply      d. divide
q. quit
d
Enter first number: 18.4
Enter second number: 0
Enter a number other than 0: 0.2
18.4 / 0.2 = 92
Enter the operation of your choice:
a. add           s. subtract
m. multiply      d. divide
q. quit
q
Bye.
*/
#include<stdio.h>
#include<ctype.h>

char menu(void);
char get_first(void);
double get_double();
double get_first_number(void);
double get_second_number(void);
void add(double ,double);
void subtract(double,double);
void multiply(double,double);
void divide(double,double);

int main(void)
{
    char cho;
    double first_number,second_number;
    while((cho = menu()) != 'q')
    {
        first_number = get_first_number();
        second_number = get_second_number();
        switch(cho)
        {
            case 'a':add(first_number,second_number);
                     break;
            case 's':subtract(first_number,second_number);
                     break;
            case 'm':multiply(first_number,second_number);
                     break;
            case 'd':divide(first_number,second_number);
                     break;
            default:
                     break;
        }
    }
    return 0;
}


char menu(void)
{
    char ch;
    printf("Enter the operation of your choice:\n");
    printf("a. add           s. subtract\n");
    printf("m. multiply      d. divide\n");
    printf("q. quit\n");

    ch = get_first();
    while(ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
    {
        printf("Please respond with a,s,m,d or q.\n");
        ch = getchar();
    }

    return ch;
}

char get_first(void)
{
    char ch;

    while(isspace(ch = getchar()))
        continue; 
    while(!isspace(getchar()))
        continue;
    return ch; 
}


double get_first_number(void)
{
    printf("Enter first number:");
    return get_double();
}


double get_second_number(void)
{
    printf("Enter second number:");
    return get_double();
}

double get_double()
{
    double input;
    char ch;
    
    while(scanf("%lf", &input) !=1)
    {
        while((ch = getchar() != '\n'))
            putchar(ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: 1.\n");
    }
    
    return input;
}

void add(double first,double second)
{
    printf("%0.3f + %0.3f = %0.3f\n",first,second,first+second);   
}

void subtract(double first,double second)
{
    printf("%0.3f - %0.3f = %0.3f\n",first,second,first-second);   
}

void multiply(double first,double second)
{
    printf("%0.3f * %0.3f = %0.3f\n",first,second,first*second);   
}

void divide(double first,double second)
{
    while(second == 0)
    {
        printf("Enter a number other than 0:");
        second = get_double();
    }
    printf("%0.3f / %0.3f = %0.3f\n",first,second,first/second);   
}
