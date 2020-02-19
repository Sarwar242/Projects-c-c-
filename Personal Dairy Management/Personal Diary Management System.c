#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>

#include<windows.h>

void addrecord();

void viewrecord();

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

void addrecord( )

{
    system("cls");

    FILE *fp ;

    char another = 'Y' ,time[10];

    struct record e ;

    char filename[15];

    int choice;

    printf("\n\n\t\t  ***************************\n");

    printf("\t\t* WELCOME TO THE ADD NOTE MENU *");

    printf("\n\t\t  ***************************\n\n");

    printf("\n\n\tENTER DATE OF YOUR RECORD:[dd-mm-yyyy]: ");

    fflush(stdin);

    gets(filename);

    fp = fopen (filename, "r+" ) ;

    if ( fp == NULL )

    {

        fp=fopen(filename,"w+");

        if(fp==NULL)

        {

            printf("\nSYSTEM ERROR...\n");

            printf("\nPRESS ANY KEY TO EXIT ");

            getch();

            return ;

        }

    }

    while ( another == 'Y'|| another=='y' )

    {

        choice=0;

        fflush(stdin);

        printf ( "\n\tENTER TIME: ");

        scanf("%s",time);

        strcpy(e.time,time);

        printf("\n\tENTER NAME: ");

        fflush(stdin);

        gets(e.name);

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

    printf("\n\n\tPRESS ANY KEY TO Go To MAIN MENU...");

    getch();

}

void viewrecord()
{

    FILE *fpte ;

    system("cls");

    struct record customer ;

    char time[6],choice,filename[14];

    int ch;
    cool:
        system("cls");
    printf("\n\n\t\t*******************************\n");

    printf("\t\t* HERE IS THE VIEWING MENU *");

    printf("\n\t\t*******************************\n\n");

        printf("\n\tENTER THE DATE OF RECORD TO BE VIEWED:[dd-mm-yyyy]: ");
        fflush(stdin);
        gets(filename);

        fpte = fopen ( filename, "r+");

        if ( fpte == NULL )

        {

            puts ( "\n\tTHE RECORD DOES NOT EXIST...\n" ) ;

            printf("\n\tPRESS ANY KEY TO EXIT...");

            getch();

            return ;

        }

        system("cls");

            printf("\n\tTHE RECORD FOR %s IS: ",filename);

            while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )

            {

                printf("\n");

                printf("\n\tTIME: %s",customer.time);

                printf("\n\n\tName: %s",customer.name);

                printf("\n\n\tPlace: %s",customer.place);

                printf("\n\n\tNOTE: %s",customer.note);

                printf("\n");

            }

        printf("\n\n\tWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N): ");

        fflush(stdin);

        scanf("%c",&choice);
        fclose(fpte);

    if(choice=='Y'||choice=='y')
        goto cool;
    else
        return;
}
