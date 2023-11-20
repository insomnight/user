/*
 * 6．一个文本文件中保存着一个垒球队的信息。每行数据都是这样排列：
 *    4 Jessie Joybat 5 2 1 1
 *  第1项是球员号，为方便起见，其范围是0～18。第2项是球员的名。第3项是球员的姓。名和姓都是一个单词。第4项是官方统计的球员上场次数。接着3项分别是击中数、走垒数和打点（RBI）。文件可能包含多场比赛的数据，所以同一位球员可能有多行数据，而且同一位球员的多行数据之间可能有其他球员的数据。编写一个程序，把数据存储到一个结构数组中。该结构中的成员要分别表示球员的名、姓、上场次数、击中数、走垒数、打点和安打率（稍后计算）。可以使用球员号作为数组的索引。该程序要读到文件结尾，并统计每位球员的各项累计总和。世界棒球统计与之相关。例如，一次走垒和触垒中的失误不计入上场次数，但是可能产生一个RBI。但是该程序要做的是像下面描述的一样读取和处理数据文件，不会关心数据的实际含义。要实现这些功能，最简单的方法是把结构的内容都初始化为零，把文件中的数据读入临时变量中，然后将其加入相应的结构中。程序读完文件后，应计算每位球员的安打率，并把计算结果存储到结构的相应成员中。计算安打率是用球员的累计击中数除以上场累计次数。这是一个浮点数计算。最后，程序结合整个球队的统计数据，一行显示一位球员的累计数据。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NLEN 40
#define TSIZE 19

struct name
{
    char fname[NLEN];
    char lname[NLEN];
};

struct player
{
    int no;
    struct name player_name;
    int games_played;
    int hits;
    int stolen_bases;
    int runs_batted_in;
    double batting_average;
};

int main(void)
{
    struct player temp;
    FILE *fp;
    struct player *plist[TSIZE] = {NULL};

    if((fp = fopen("match_data","r")) == NULL)
    {
        fprintf(stderr,"Can't open the file match_data.\n");
        exit(EXIT_FAILURE);
    }

    while((fscanf(fp,"%d %s %s %d %d %d %d",&temp.no,&temp.player_name.fname,&temp.player_name.lname,&temp.games_played,&temp.hits,&temp.stolen_bases,&temp.runs_batted_in)) == 7)
    {
        if(temp.no < 0 || temp.no > 18)
        {
            fprintf(stderr,"the player no %d is not in 0 ~ 18.\n",temp.no);
            continue;
        }

        if(plist[temp.no] == NULL)
        {
            plist[temp.no] = (struct player *) malloc(sizeof(struct player));
            plist[temp.no]->no = temp.no;
            strcpy(plist[temp.no]->player_name.fname , temp.player_name.fname);
            strcpy(plist[temp.no]->player_name.lname , temp.player_name.lname);
            plist[temp.no]->games_played = temp.games_played;
            plist[temp.no]->hits = temp.hits;
            plist[temp.no]->stolen_bases = temp.stolen_bases;
            plist[temp.no]->runs_batted_in = temp.runs_batted_in;
        } else {
            plist[temp.no]->games_played += temp.games_played;
            plist[temp.no]->hits += temp.hits;
            plist[temp.no]->stolen_bases += temp.stolen_bases;
            plist[temp.no]->runs_batted_in += temp.runs_batted_in;
        }
    }

    for(int i = 0; i < TSIZE; i++)
        if(plist[i] != NULL)
            plist[i]->batting_average = ((double) plist[i]->hits) / plist[i]->games_played; 

            printf("%2s %40s %-40s %4s %4s %4s %4s %4s\n","no"," ","name","GP","H","SB","RBI","AVG");
    for(int i = 0; i < TSIZE; i++)
        if(plist[i] != NULL)
            printf("%2d %40s %-40s %4d %4d %4d %4d %4.3lf\n",plist[i]->no,plist[i]->player_name.fname,plist[i]->player_name.lname,plist[i]->games_played,plist[i]->hits,plist[i]->stolen_bases,plist[i]->runs_batted_in,plist[i]->batting_average);

    for(int i = 0; i < TSIZE; i++)
        if(plist[i] != NULL)
            free(plist[i]);

    return 0;
}
