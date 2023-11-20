
/*
 * 14．数字图像，尤其是从宇宙飞船发回的数字图像，可能会包含一些失真。为编程练习12添加消除失真的函数。该函数把每个值与它上下左右相邻的值作比较，如果该值与其周围相邻值的差都大于1，则用所有相邻值的平均值（四舍五入为整数）代替该值。注意，与边界上的点相邻的点少于4个，所以做特殊处理。
 */

#include <stdio.h>
#include <stdlib.h>
#define ROW 20
#define COL 30

static char swap[10] = {' ','.','\'',':','~','*','=',' ','%','#'};

int handle_data(int data[][COL],int row);
int judge_adjacent(int data[][COL],int row,int index_row,int index_col);
int average_adjacent(int data[][COL],int row,int index_row,int index_col);

int main(void)
{
    FILE *fin,*fout;
    int data[ROW][COL];
    char cdata[ROW][COL + 1];
    int count,row,col,num;
    
    if((fin = fopen("in12","r")) == NULL)
    {
        fprintf(stderr,"Can't open %s\n","in12");
        exit(EXIT_FAILURE);
    }

    if((fout = fopen("out14","w")) == NULL)
    {
        fprintf(stderr,"Can't open %s\n","out12");
        exit(EXIT_FAILURE);
    }

    count = 0;
    row = count / COL;
    col = count % COL;
    while( fscanf(fin,"%d", &data[row][col]) && count < ROW * COL)
    {
        num = data[row][col];
        count++;
        row = count / COL;
        col = count % COL;
    }

    handle_data(data,ROW);
    
    for(row = 0; row < ROW; row++)
        for(col = 0; col < COL; col++)
        {
            num = data[row][col];
            cdata[row][col] = swap[num];
            if(col == ( COL - 1 ))
                cdata[row][COL] = '\0';
        }

    for(int i = 0; i < ROW; i++)
    {
        puts(cdata[i]);
        fprintf(fout,"%s\n",cdata[i]);
    }
    fclose(fin);
    fclose(fout);

    return 0;
}

int handle_data(int data[][COL],int row)
{
    for(int index_row = 0; index_row < row; index_row++)
        for(int index_col = 0; index_col < COL; index_col++)
            if(judge_adjacent(data,row,index_row,index_col))
                data[index_row][index_col] = average_adjacent(data,row,index_row,index_col);
}

int judge_adjacent(int data[][COL],int row,int index_row,int index_col)
{
    int cazhi;
    /* 判断上方数据的差值 */
    if(index_row > 0)
    {
        cazhi = data[index_row][index_col] - data[index_row - 1][index_col];
        if( cazhi <= 1 && cazhi >= -1 )
            return 0;
    }
    /* 判断下方数据的差值 */
    if(index_row < row - 1)
    {
        cazhi = data[index_row][index_col] - data[index_row + 1][index_col];
        if( cazhi <= 1 && cazhi >= -1 )
            return 0;
    }
    /* 判断左方数据的差值 */
    if(index_col > 0)
    {
        cazhi = data[index_row][index_col] - data[index_row][index_col - 1];
        if( cazhi <= 1 && cazhi >= -1 )
            return 0;
    }
    /* 判断右方数据的差值 */
    if(index_col < COL - 1)
    {
        cazhi = data[index_row][index_col] - data[index_row][index_col + 1];
        if( cazhi <= 1 && cazhi >= -1 )
            return 0;
    }
    return 1;
}

int average_adjacent(int data[][COL],int row,int index_row,int index_col)
{
    int sum = 0;
    int count = 0;
    /* 上方数据 */
    if(index_row > 0)
    {
        sum += data[index_row -1][index_col];
        count++;
    }
    /* 下方数据 */
    if(index_row < row - 1)
    {
        sum += data[index_row + 1][index_col];
        count++;
    }
    /* 左方数据 */
    if(index_col > 0)
    {
        sum += data[index_row][index_col - 1];
        count++;
    }
    /* 右方数据 */
    if(index_col < COL - 1)
    {
        sum += data[index_row][index_col + 1];
        count++;
    }
    return sum / count;
}
