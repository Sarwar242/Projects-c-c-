#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>

#include<windows.h>

void addrecord();

void viewrecord();
int datecheck(char filename[]);
int timecheck(char time[]);

struct record

{
    char time[6];

    char name[30];

    char place[25];

    char note[500];

} ;

int main()
{
    char ch;
    system("color FC");

    printf("\n\n\n\n\t**********************************************\n\n");

    printf("\t\t###WELOME TO PERSONAL DIARY###\n");

    printf("\n\t**********************************************\n");

    printf("\n\n\tPress any key to Enter the Main Menu->  ");
    getch();
    system("cls");

    printf("\n\n\n\n\t\tLoading... Please wait....\n\n\n");

    while(1)

    {
        First:
        system("cls");
        printf("\n\n\t\tMAIN MENU:");
        printf("\n\t******************************\n");
        printf("\n\n\t1. ADD RECORD\t");
        printf("\n\t******************************\n");
        printf("\n\t2. VIEW RECORD\t");
        printf("\n\t******************************\n");
        printf("\n\n\tPress 0 to EXIT....\t\t");
        printf("\n\t******************************\n");
        fflush(stdin);
        printf("\n\n\tENTER YOUR CHOICE: ");

        ch=getchar();

        switch(ch)

        {

        case '1':

            addrecord();

            goto First;

        case '2':

            viewrecord();

            goto First;
            break;


        case '0':

            printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE ");

            getch();

            return 0;

        default:

            printf("\n\n\n\t\tYOU ENTERED WRONG CHOICE..\n\n");

            printf("\n\t\tPRESS ANY KEY TO TRY AGAIN\n ");

            getch();
            goto First;

        }

    }

    return 0;

}
int datecheck(char filename[])
{
    char a1[10]={},a2[10]={},a3[10]={};
    int len;
    len=strlen(filename);
    int i,j;
    if(len>10)
        {printf("invalid date format\n");
        return 0;}
    int flag=1;
    j=0;
    int k=0,l=0;
    for(i=0;i<len;i++)
    {
        if((filename[i]>='0'&&filename[i]<='9')||filename[i]==45)
        {
            if(i==2&&filename[i]==45)
                {
                flag=2;
                ++i;
                }

            if(i==5&&filename[i]==45)
            {
                flag=3;
                ++i;

            }

            if(flag==1)
            {
                if(filename[i]>='0'&&filename[i]<='9')
                {

                a1[j]=filename[i];
                j++;
                }
                else
                {

                    return 0;
                }
            }
            a1[j]='\0';

            if(flag==2)
            {
                if(filename[i]>='0'&&filename[i]<='9')
                {

                a2[k]=filename[i];
                k++;
                }
                else
                {
//                    printf("invalid date format\n");
                    return 0;
                }
            }
            a2[k]='\0';
            if(flag==3)
            {
                if(filename[i]>='0'&&filename[i]<='9')
                {

                a3[l]=filename[i];
                l++;
                }
                else
                {
//                    printf("invalid date format\n");
                    return 0;
                }
            }
            a3[l]='\0';

        }
        else
            return 0;
    }

    int date=atoi(a1);
    int month=atoi(a2);
    int year=atoi(a3);
    int leap=0;
    int legit = 0;

    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        {leap=1;}

    if (month<13)
    {
       if (month == 1 || month==3 || month== 5 || month== 7 || month== 8 || month== 10 || month== 12 )
            {if (date <=31)
                {legit=1;}}
        else if (month == 4 || month== 6 || month== 9 || month== 11  )
            {if (date <= 30)
                {legit = 1;}}

        else
            {

                    if (leap == 0)
                            {{if (date <= 28)
                                    legit = 1;}}
                  if (leap == 1)
                            {if (date <= 29)
                                    {legit = 1;}}
             }

    }
    if(legit==1)
        return 1;
    else
        return 0;
}
int timecheck(char time[])
{
    char t1[5],t2[5];
    int len;
    len=strlen(time);
    int i,j;
    if(len>5)
        {
            return 0;
        }
    int flag=1;
    j=0;
    int k=0,l=0;
    for(i=0;i<len;i++)
    {
        if((time[i]>='0'&&time[i]<='9')||time[i]==46)
        {
            if(i==2&&time[i]==46)
                {
                flag=2;
                ++i;
                }
            if(flag==1)
            {
                if(time[i]>='0'&&time[i]<='9')
                {

                t1[j]=time[i];
                j++;
                }
                else
                {
                    return 0;
                }
            }
            t1[j]='\0';

            if(flag==2)
            {
                if(time[i]>='0'&&time[i]<='9')
                {

                t2[k]=time[i];
                k++;
                }
                else
                {
                    return 0;
                }
            }
            t2[k]='\0';

        }
        else
            return 0;
    }

    int hour=atoi(t1);
    int min=atoi(t2);

    int legit = 0;

    if(hour<=24)
        {
        legit=1;

        if(min<=60)
            legit=1;

        else
            legit=0;
        }

    if(legit==1)
        return 1;

    else
        return 0;
}
int dd;
void addrecord( )

{
    system("cls");

    FILE *fp ;
    FILE *fpv;

    char another = 'Y' ,time[10];

    struct record e ;

    char filename[15];
    char name[100],date[100];
    int choice;
    int lb=0,tt=0;
    int tell=0;
    printf("\n\n\t\t  ***************************\n");

    printf("\t\t* WELCOME TO THE ADD NOTE MENU *");

    printf("\n\t\t  ***************************\n\n");
    valid:
        if(lb==1)
            {
            system("cls");
            printf("\n\t**************** ADD MENU *****************\n\n\n");
        }
    printf("\n\n\tENTER DATE OF YOUR RECORD:[dd-mm-yyyy]: ");

    fflush(stdin);

    gets(filename);
    strcpy(date,filename);

    dd=datecheck(filename);
    if(dd==0)
    {

        printf("\n\tSorry, Invalid date. Try again...\n\n\tPress any key... ");
        lb=1;
        getch();

        goto valid;
    }

    fp = fopen (filename, "r" ) ;

    if ( fp != NULL )

    {

//        fp=fopen(filename,"w+");
        printf("\n\tDate already exist.\n");

        printf("\n\tPRESS ANY KEY... ");
        lb==1;

        getch();

        goto valid ;

    }
    fp = fopen (filename, "w+" ) ;
    while ( another == 'Y'|| another=='y' )
    {
        tm:
        choice=0;

        fflush(stdin);

        printf ( "\n\tENTER TIME[hh.mm] : ");

        scanf("%s",time);
        tell=timecheck(time);
        if(tell==0)
        {
        printf("\t[Sorry, Invalid Time. Enter  again...]\n");
        tt=1;
        goto tm;
        }

        strcpy(e.time,time);

        printf("\n\tENTER NAME: ");

        fflush(stdin);

        gets(e.name);
        strcpy(name,e.name);

        fflush(stdin);

        printf("\n\tENTER PLACE: ");

        gets(e.place);

        fflush(stdin);

        printf("\n\tNOTE: ");

        gets(e.note);

        fwrite ( &e, sizeof ( e ), 1, fp ) ;

        printf("\n\t\tYOUR RECORD IS ADDED...\n");

        printf ( "\n\tADD ANOTHER RECORD OF THE DATE...(Y/N) " ) ;

        fflush (stdin);

        another = getchar();

    }

    fclose ( fp ) ;
    fpv=fopen("Records.txt","a+");

    fprintf(fpv,"%s %s\n",date,name);
    fclose(fpv);

    printf("\n\n\tPRESS ANY KEY TO Go To MAIN MENU...");

    getch();

}
int mm;
void viewrecord()
{

    FILE *fpte ;
    FILE *fv;
    system("cls");

    struct record customer ;

    char time[6],choice,filename[14];
    char name[100],date[100];

    int ch,la=0;

        system("cls");
    printf("\n\n\t\t*******************************\n");

    printf("\t\t* HERE IS THE VIEWING MENU *");

    printf("\n\t\t*******************************\n\n");
    cool:

        if(la==1)
        {
            system("cls");
            printf("\n\t********View Menu*********\n\n");
        }

        printf("\n\n\t[Enter 0 to go to main menu] \n\n");
    fv=fopen("Records.txt","r+");
    rewind(fv);
    if(fv==NULL)
    {
        printf("\n\n\tDatabase Missing\n\n\tPress any key... ");
        getch();
        return;
    }
    printf("\n\tDate:            Name:\n");

    fflush(stdout);
    while(!feof(fv))
    {
        fscanf(fv,"%s %s\n",date,name);
        printf("\n\t%s      %s",date,name);

    }
    fclose(fv);

        printf("\n\n\tENTER THE DATE OF RECORD TO BE VIEWED:[dd-mm-yyyy]: ");
        fflush(stdin);
        gets(filename);
        ch=atoi(filename);
        if(ch==0)
            return;
        mm=datecheck(filename);
        if(mm==0)
        {
            printf("\n\tSorry, Invalid date. Try again...\n\n\tPress any key... ");
            getch();
            la=1;
            goto cool;
    }

        fpte = fopen ( filename, "r");

        if ( fpte == NULL )

        {

            puts ( "\n\tTHE RECORD DOES NOT EXIST...\n" ) ;

            printf("\n\tPRESS ANY KEY... ");
            la=1;
            getch();

            goto cool;

        }

        system("cls");
        fpte=fopen(filename,"r");
        rewind(fpte);

            printf("\n\tTHE RECORD FOR %s IS: ",filename);

//            while (==1)
//
//
                fread(&customer, sizeof(customer),1,fpte);
                printf("\n");

                printf("\n\tTIME: %s",customer.time);

                printf("\n\n\tName: %s",customer.name);

                printf("\n\n\tPlace: %s",customer.place);

                printf("\n\n\tNOTE: %s",customer.note);

                printf("\n");

            //}

        printf("\n\n\tWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N): ");

        fflush(stdin);

        scanf("%c",&choice);
        fclose(fpte);

    if(choice=='Y'||choice=='y')
    {
        la=1;
        goto cool;
    }
    else
        return;
}

