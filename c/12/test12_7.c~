/*
 * 7．编写一个程序，按照程序清单12.13输出示例后面讨论的内容，修改该程序。使其输出类似：
 * Enter the number of sets; enter q to stop : 18
 * How many sides and how many dice? 6 3
 * Here are 18 sets of 3 6-sided throws.
 *   12 10 6 9 8 14 8 15 9 14 12 17 11 7 10
 *   13 8 14
 * How many sets? Enter q to stop: q
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
    int size;
    int dice,sides;
    int roll;

    srand((unsigned int) time(0));
    printf("Enter the number of sets; enter q to stop : ");
    while(scanf("%d",&size) && size > 0)
    {
        printf("How many sides and how many dice? ");
        if(scanf("%d%d",&sides,&dice) != 2)
        {
            printf("You should have entered two interger.");
            break;
        }

        printf("Here are %d sets of %d %d-sided throws.\n",size,dice,sides);
        for(int i = 0; i < size; i++)
        {
            if( !((i + 1) % 15) )
                putchar('\n');
            roll = roll_n_dice(dice,sides);
            printf("%d ",roll);
        }
        putchar('\n');
        printf("Enter the number of sets; enter q to stop : ");
    }

    return 0;
}

