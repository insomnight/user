/*
 * 5．编写一个程序满足下面的要求。　　a．外部定义一个有两个成员的结构模板name：一个字符串存储名，一个字符串存储姓。　　b．外部定义一个有3个成员的结构模板student：一个name类型的结构，一个grade数组存储3个浮点型分数，一个变量存储3个分数平均数。　　c．在main()函数中声明一个内含CSIZE（CSIZE = 4）个student类型结构的数组，并初始化这些结构的名字部分。用函数执行g、e、f和g中描述的任务。　　d．以交互的方式获取每个学生的成绩，提示用户输入学生的姓名和分数。把分数存储到grade数组相应的结构中。可以在main()函数或其他函数中用循环来完成。　　e．计算每个结构的平均分，并把计算后的值赋给合适的成员。　　f．打印每个结构的信息。　　g．打印班级的平均分，即所有结构的数值成员的平均值。
 */

#include <stdio.h>
#define CSIZE 4
#define NSIZE 40
#define GSIZE 3

struct name
{
    char fname[NSIZE];
    char lname[NSIZE];
};

struct student
{
    struct name stu_name;
    double grade[GSIZE];
    double average;
};

void save_grade(struct student * stu);
void grade_average(struct student * stu);
void print_student(struct student * stu);
double class_average(struct student * stu,int size);

int main(void)
{
    struct student stulist[CSIZE] = {
        {.stu_name = { "Cheryl","Stone" }},
        {.stu_name = { "Rita","Leighton" }},
        {.stu_name = { "Albert","Holmes" }},
        {.stu_name = { "Edwiin","Beaufort" }}
    };
    double caverage;

    for(int i = 0; i < CSIZE; i++)
        save_grade(&stulist[i]);

    for(int i = 0; i < CSIZE; i++)
        grade_average(&stulist[i]);

    for(int i = 0; i < CSIZE; i++)
        print_student(&stulist[i]);

    caverage = class_average(stulist,CSIZE);
    printf("the class average is %lf\n",caverage);
    return 0;
}

void save_grade(struct student * stu)
{
    printf("Enter %s %s's the frist grade:",stu->stu_name.fname,stu->stu_name.lname);
    while(scanf("%lf",&stu->grade[0] )!= 1)
    {
        printf("The grade is not right!enter the first grade again!");
    }
    printf("Enter %s %s's the second grade:",stu->stu_name.fname,stu->stu_name.lname);
    while(scanf("%lf",&stu->grade[1] )!= 1)
    {
        printf("The grade is not right!enter the second grade again!");
    }
    printf("Enter %s %s's the thrid grade:",stu->stu_name.fname,stu->stu_name.lname);
    while(scanf("%lf",&stu->grade[2] )!= 1)
    {
        printf("The grade is not right!enter the thrid grade again!");
    }
}

void grade_average(struct student * stu)
{
    double total = 0.0;
    for(int i = 0; i < GSIZE; i++)
        total += stu->grade[i];
    stu->average =  total / GSIZE;
}

void print_student(struct student * stu)
{
    printf("stu_name: %s %s,grades:[%lf,%lf,%lf],average:%lf\n",stu->stu_name.fname,stu->stu_name.lname,
           stu->grade[0],stu->grade[1],stu->grade[2],stu->average);
}

double class_average(struct student * stu,int size)
{
    double total = 0.0;
    for(int i = 0; i < size; i++)
        total += stu[i].average;
    return total / size;
}
