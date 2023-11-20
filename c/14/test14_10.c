/*
 * 10．编写一个程序，通过一个函数指针数组实现菜单。例如，选择菜单中的a，将激活由该数组第1个元素指向的函数。
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#define SEAT_MAX 12
#define NLEN 40
#define NOLEN 8
#define HLEN 4

struct seat
{
    char no[NOLEN];
    int isReserved;
    char fname[NLEN];
    char lname[NLEN];
};

static struct seat seatlist[SEAT_MAX];
static int empty_count = 0;

void init_seat(FILE * pf);
int menu(void);
void eatline(void);
char * s_gets(char * st, int n);
void show_empty_seats_counts(void);
void show_empty_seats(void);
void show_seat_sort_by_no(void);
void reserved_seat(void);
void cancel_seat(void);
int get_index_by_no(const char * no);
void hangban(char * hangbanno);
int inhangban(char ** hangbanfile,int size, char *hangno);

int main(void)
{
    puts("To choose a hangban,:");
    char * hangbanfile[] = { "102","311","444","519"};
    char hangbanchoose[HLEN];
    puts("qing shuru hangban hao:");
    while(s_gets(hangbanchoose,HLEN) != NULL && hangbanchoose[0] != '\0' && inhangban(hangbanfile,4,hangbanchoose))
        hangban(hangbanchoose);
    return 0;
}

void init_seat(FILE *pf)
{

    int count = 0;
    rewind(pf);
    while(count < SEAT_MAX && fread(&seatlist[count], sizeof(struct seat), 1, pf) == 1)
    {
        if(seatlist[count].isReserved == 0 )
            empty_count++;
        count++;
    }
    if(count != SEAT_MAX)    
        for(; count < SEAT_MAX; count++)
        {
            snprintf(seatlist[count].no,NOLEN,"%c%03d",'A',count);
            seatlist[count].isReserved = 0;
            empty_count++;
        }
}

int menu(void)
{
    char choose;
    char chooselist[] = "abcdef";

    puts("To choose a funcion,enter its letter label:");
    puts("a)Show number of empty seats");
    puts("b)Show list of empty seats");
    puts("c)Show alphabetical list of seats");
    puts("d)Assign a customer to a seat assignment");
    puts("e)Delete a seat assignment");
    puts("f)Quit");
    choose = getchar();
    choose = tolower(choose);
    eatline();
    while(strchr("abcdef",choose) == NULL)
    {
        puts("Please enter a a, b, c, d, e, or f:");
        choose = getchar();
        choose = tolower(choose);
        eatline();
    }

    for(int i = 0; i < 6; i++)
        if(chooselist[i] == choose)
            return i;
    return -1;
}

void eatline(void)
{
    while(getchar() != '\n')
        continue;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
            *find = '\0';
        else
            eatline();
    }
    return ret_val;
}

void show_empty_seats_counts(void)
{
    printf("The number of empty seats is %d\n\n",empty_count);
}

void show_empty_seats(void)
{
    if(empty_count < 1)
        puts("No seats!So bad!");
    puts("Here is the empty seats:\n");
    puts("seat_no");
    for(int i = 0; i < SEAT_MAX; i++)
        if(seatlist[i].isReserved == 0)
            printf("%s\n",seatlist[i].no); 
}

void show_seat_sort_by_no(void)
{
    char *empty_str[] = {"empty","reserved"};
    puts("Here is the seats after alphabetical:\n");
    for(int i = 0; i < SEAT_MAX; i++)
        printf("%8s %8s %s %s\n",seatlist[i].no,empty_str[seatlist[i].isReserved],seatlist[i].fname,seatlist[i].lname);
}

void reserved_seat(void)
{
    char seatno[NOLEN];
    char fname[NLEN];
    char lname[NLEN];
    int index;

    if(empty_count < 1)
    {
        puts("No seats!So bad!");
        return ;
    }
    
    show_empty_seats();
    puts("Please enter the seat no.");
    printf("Press [enter] at the start of a line to stop.\n");

    while(empty_count > 0 && s_gets(seatno,NOLEN) != NULL 
            && seatno[0] != '\0')
    {
        if((index = get_index_by_no(seatno)) == -1 )
        {
            puts("The seat is not find.Please enter the right seat no.");
            continue;
        }
        if(seatlist[index].isReserved)
        {
            puts("The seat is booked!enter other seat.");
            continue;
        }

        printf("Now enter the customer frist name.\n");
        s_gets(fname,NLEN);
        if(fname == NULL || fname[0] == '\0')
            break;
        printf("Now enter the customer last name.\n");
        s_gets(lname,NLEN);
        if(lname == NULL || lname[0] == '\0')
            break;
        strcpy(seatlist[index].fname,fname);
        strcpy(seatlist[index].lname,lname);
        seatlist[index].isReserved = 1;
        empty_count--;
        puts("Enter the next seat want to book");
    }
}

void cancel_seat(void)
{
    int index;
    char seatno[NOLEN];
    if(empty_count == SEAT_MAX)
    {
        puts("All seat is empty!");
        return ;
    }

    show_seat_sort_by_no();
    
    puts("Please enter the seat no.");
    printf("Press [enter] at the start of a line to stop.\n");

    while(empty_count > 1 && s_gets(seatno,NOLEN) != NULL 
            && seatno[0] != '\0')
    {
        if((index = get_index_by_no(seatno)) == -1 )
        {
            puts("The seat is not find.Please enter the right seat no.");
            continue;
        }
        if(!seatlist[index].isReserved)
        {
            puts("The seat is empty!enter other seat.");
            continue;
        }
        seatlist[index].fname[0] = '\0';
        seatlist[index].lname[0] = '\0';
        seatlist[index].isReserved = 0;
        empty_count++;
        puts("Enter the next seat want to cancel");
    }
}

int get_index_by_no(const char * no)
{
    int index = 0;
    for(; index < SEAT_MAX; index++)
        if(!strcmp(seatlist[index].no,no))
            return index;
    return -1;
}

void hangban(char * hangbanno)
{

    FILE *pf;
    int choose ;
    void (*pfun[5])(void) = {show_empty_seats_counts,show_empty_seats,show_seat_sort_by_no,reserved_seat,cancel_seat};


    char filename[100] = "seat";
    strcat(filename,hangbanno);
    if(( pf = fopen(filename,"a+b") ) == NULL)
    {
        fputs("Can't open seat.dat\n",stderr);
        exit(EXIT_FAILURE);
    }
    init_seat(pf);
    printf("Now hangban is %s \n",hangbanno);
    while((choose = menu()) != 5)
    {
        (*pfun[choose])();
        printf("Now hangban is %s \n",hangbanno);
    }

    rewind(pf);
    ftruncate(fileno(pf),0);
    fwrite(seatlist,sizeof(struct seat),SEAT_MAX,pf);
    fclose(pf);
}

int inhangban(char ** hangbanfile,int size, char *hangno)
{
    for(int i = 0; i < size; i++)
        if(strcmp(hangbanfile[i],hangno) == 0)
            return 1;
    return 0;
}
