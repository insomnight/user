/*
 * 13．编写一个程序，提示用户输入3组数，每组数包含5个double类型的数（假设用户都正确地响应，不会输入非数值数据）。该程序应完成下列任务。　　a．把用户输入的数据存储在3×5的数组中　　b．计算每组（5个）数据的平均值　　c．计算所有数据的平均值　　d．找出这15个数据中的最大值　　e．打印结果每个任务都要用单独的函数来完成（使用传统C处理数组的方式）。完成任务b，要编写一个计算并返回一维数组平均值的函数，利用循环调用该函数3次。对于处理其他任务的函数，应该把整个数组作为参数，完成任务c和d的函数应把结果返回主调函数。
 */
#include<stdio.h>

void save(double data[][5],int size);
double average_done(double data[],int size);
double average(double data[][5],int size);
double max(double data[][5],int size);
void print_arr(double data[][5],int size);

int main(void)
{
    double data[3][5];
    save(data,3);
    print_arr(data,3);
    printf("\n");

    for(int i = 0; i < 3; i++)
        printf("%f\n",average_done(data[i],5));
    printf("\n");

    printf("%f\n",average(data,3));
    printf("\n");
    
    printf("%f\n",max(data,3));
    printf("\n");

    return 0;
}

void save(double data[][5],int size)
{
    int i = 0;
    while(scanf("%lf", &data[i / 5][i % 5] ) == 1)
    {
        i++;
        if(i == size * 5)
            break;
    }
}

double average_done(double data[],int size)
{
    double total = 0;
    for( int i = 0; i < size; i++)
        total += data[i];
    return total / size;
}

double average(double data[][5],int size)
{
    double total = 0;
    for(int i = 0; i < size; i++)
        total += average_done(data[i], 5);
    return total / size;
}

double max(double data[][5],int size)
{
    double max = data[0][0];
    for(int i = 0; i < size; i++)
        for(int j = 0; j < 5; j++)
            if(max < data[i][j])
                    max = data[i][j];
    return max;
}

void print_arr(double data[][5],int size)
{
    for(int i = 0; i < size; i++)
    { 
        for(int j = 0; j < 5; j++)
            printf("%8.3f ",data[i][j]);
        printf("\n");
    }
    printf("\n");
}


