/*
 * 14．以变长数组作为函数形参，完成编程练习13。 
 */
#include<stdio.h>

void save(int rows, int cols, double data[rows][cols]);
double average_done(int size, double data[size]);
double average(int rows, int cols, double data[rows][cols]);
double max(int rows, int cols, double data[rows][cols]);
void print_arr(int rows, int cols, double data[rows][cols]);

int main(void)
{
    double data[3][5];
    save(3,5,data);
    print_arr(3,5,data);
    printf("\n");

    for(int i = 0; i < 3; i++)
        printf("%f\n",average_done(5,data[i]));
    printf("\n");

    printf("%f\n",average(3,5,data));
    printf("\n");
    
    printf("%f\n",max(3,5,data));
    printf("\n");

    return 0;
}

void save(int rows, int cols, double data[rows][cols])
{
    int i = 0;
    while(scanf("%lf", &data[i / 5][i % 5] ) == 1)
    {
        i++;
        if(i == rows * cols)
            break;
    }
}

double average_done(int size, double data[size])
{
    double total = 0;
    for( int i = 0; i < size; i++)
        total += data[i];
    return total / size;
}

double average(int rows, int cols, double data[rows][cols])
{
    double total = 0;
    for(int i = 0; i < rows; i++)
        total += average_done(cols, data[i]);
    return total / rows;
}

double max(int rows, int cols, double data[rows][cols])
{
    double max = data[0][0];
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(max < data[i][j])
                    max = data[i][j];
    return max;
}

void print_arr(int rows, int cols, double data[rows][cols])
{
    for(int i = 0; i < rows; i++)
    { 
        for(int j = 0; j < cols; j++)
            printf("%8.3f ",data[i][j]);
        printf("\n");
    }
    printf("\n");
}


