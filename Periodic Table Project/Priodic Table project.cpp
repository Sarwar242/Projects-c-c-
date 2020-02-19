#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
char read[10000],dev[1000];

int main()
{
    printf("\n\t ************************************");
    printf("\n\t  ************ WELCOME *************");
    printf("\n\t   ********************************\n");
    printf("\n\t    ******************************");
    printf("\n\t     ************ TO ************");
    printf("\n\t    ******************************\n");
    printf("\n\t   ********************************");
    printf("\n\t  ********** PERIODIC TABLE ********");
    printf("\n\t ************************************\n");

    printf("\n\n\n\t**************************************");
    printf("\n\t   Press any key to enter main menu   ");
    printf("\n\t**************************************\n\t\t\t  ");
    getch();
    char ch;
    while(1)
        {
            system("cls");
            printf("\n\n\t***WELCOME TO MAIN MENU***\n\n");
            printf("\t1. View Periodic Table..\n\n ");
            printf("\t2. About..\n\n");
            printf("\t3. Exit..\n\n");

            fflush(stdin);
            printf("\n\tEnter your choice: ");
            ch=getchar();
            if(ch=='1'){
                    system("cls");
                    FILE *fp;

                    fp=fopen("Periodic_table.txt","r+");
                    while(!feof(fp))
                    {
                        fgets(dev,1000,fp);

                        printf("%s",dev);
                    }
                fclose(fp);

          printf("\n\n\n\tPress any key to get back to main menu... ");
          getch();
         }
        else if(ch=='2')
        {
            system("cls");
            printf("\n\t###About Developer::\n\n\n");
            FILE *fp;

            fp=fopen("developer.txt","r+");
            while(!feof(fp))
                {
                fgets(read,10000,fp);

                printf("%s",read);
                }
                fclose(fp);
                printf("\n\n\n\tPress any key to get back to main menu... ");

                getch();
        }

        else if(ch=='3')
        {
            system("cls");
            printf("\n\tThank you for Using...\n");
            return 0;
        }
        else
            {
            system("cls");
            printf("\n\tOpps wrong keyword\n\tPress any key... ");
            getch();
            continue;
            }

    }

    return 0;
}
