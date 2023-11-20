/*
 * 4．编写一个程序，创建一个有两个成员的结构模板：　　a．第1个成员是社会保险号，第2个成员是一个有3个成员的结构，第1个成员代表名，第2个成员代表中间名，第3个成员表示姓。创建并初始化一个内含5个该类型结构的数组。该程序以下面的格式打印数据：
 *            Dribble, Flossie M. –– 302039823
 *            如果有中间名，只打印它的第1个字母，后面加一个点（.）；如果没有中间名，则不用打印点。编写一个程序进行打印，把结构数组传递给这个函数。
 *            b．修改a部分，传递结构的值而不是结构的地址。
 */
#include <stdio.h>
#include <string.h>
#define NLEN 40

struct person
{
    char fname[NLEN];
    char mname[NLEN];
    char lname[NLEN];
};

struct insureder 
{
    long SSN;
    struct person personinfo;
};

void print_info(const struct insureder * p);
void print_info_data(const struct insureder data);

int main(void)
{
    struct insureder list[5] = {
        {302039823L,{"Dribble","Mark","Flossie"}},
        {302039824L,{"Dribble","","Flossie"}},
        {302039825L,{"Dribblea","Aark","Flossiea"}},
        {302039826L,{"Dribbleb","Bark","Flossiela"}},
        {302039827L,{"Dribblec","Cark","Flossieb"}}
    };

    for(int i = 0; i < 5; i++)
    {
        print_info(&list[i]);
    }

    printf("\n");

    for(int i = 0; i < 5; i++)
    {
        print_info_data(list[i]);
    }
    
    return 0;
}

void print_info(const struct insureder * p)
{
    if(strlen(p->personinfo.mname) > 0)
        printf("%s, %s %c. -- %ld\n",p->personinfo.fname,p->personinfo.lname,p->personinfo.mname[0],p->SSN); 
    else
        printf("%s, %s -- %ld\n",p->personinfo.fname,p->personinfo.lname,p->SSN); 
}

void print_info_data(const struct insureder data)
{
    if(strlen(data.personinfo.mname) > 0)
        printf("%s, %s %c. -- %ld\n",data.personinfo.fname,data.personinfo.lname,data.personinfo.mname[0],data.SSN); 
    else
        printf("%s, %s -- %ld\n",data.personinfo.fname,data.personinfo.lname,data.SSN); 
}
