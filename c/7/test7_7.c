/*
   7．编写一个程序，提示用户输入一周工作的小时数，然后打印工资总额、税金和净收入。做如下假设：　
   a．基本工资 = 10.00美元/小时　　
   b．加班（超过40小时） = 1.5倍的时间　　
   c．税率：　前300美元为15%　　　　　　 　
              续150美元为20%　　　　　　 　
              余下的为25%
   用#define定义符号常量。不用在意是否符合当前的税法。 */ 
#include<stdio.h> 
#define BASE_HOURLY_SALARY 10.00    //基本时薪
#define BASE_WORK_HOURS 40          //正常工作时长
#define OVERTIME_MAGNIFICATION 1.5  //加班时长倍率
#define TAX_LEVEL_ONE_RANGE 300     //税第一等级范围
#define TAX_LEVEL_ONE_RATE 0.15     //税第一等级税率
#define TAX_LEVEL_TWO_RANGE 150     //税第二等级范围
#define TAX_LEVEL_TWO_RATE 0.2      //税第二等级税率
#define TAX_LEVEL_OTHER_RATE 0.25   //剩下部分税率

int main(void)
{
    double salary =0.0;
    int work_hours;
    double tax = 0.0;
    while(scanf("%d",&work_hours))
    {
        salary = BASE_HOURLY_SALARY * (work_hours < BASE_WORK_HOURS ? work_hours : ( work_hours - BASE_WORK_HOURS ) * OVERTIME_MAGNIFICATION + BASE_WORK_HOURS);
        if(salary <= TAX_LEVEL_ONE_RANGE)
            tax = salary * TAX_LEVEL_ONE_RATE;
        else if(salary <= TAX_LEVEL_ONE_RANGE + TAX_LEVEL_TWO_RANGE)
            tax = TAX_LEVEL_ONE_RANGE * TAX_LEVEL_ONE_RATE + (salary -TAX_LEVEL_ONE_RANGE) * TAX_LEVEL_TWO_RATE;
        else 
            tax = TAX_LEVEL_ONE_RANGE * TAX_LEVEL_ONE_RATE +TAX_LEVEL_TWO_RANGE * TAX_LEVEL_TWO_RATE + (salary - TAX_LEVEL_ONE_RANGE - TAX_LEVEL_TWO_RANGE) * TAX_LEVEL_OTHER_RATE;
    printf("salary = %0.3f,tax = %0.3f,left = %0.3f\n",salary,tax, salary - tax);
    }
   return 0;
}
