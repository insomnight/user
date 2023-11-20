
/*
 * 13．用变长数组（VLA）代替标准数组，完成编程练习12。
 */

#include <stdio.h>
#include <stdlib.h>
#define ROW 20
#define COL 30

static char swap[10] = {' ','.','\'',':','~','*','=',' ','%','#'};

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

    if((fout = fopen("out12","w")) == NULL)
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
        cdata[row][col] = swap[num];
        if(col == ( COL - 1 ))
            cdata[row][COL] = '\0';
        count++;
        row = count / COL;
        col = count % COL;
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
