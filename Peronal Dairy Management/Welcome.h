using namespace std;

void Welcome();
void Mainmenu();
void worng();

void Welcome()
{
    system("color FC");

    printf("\n\n\n\n\t**********************************************\n\n");

    printf("\t\t###WELOME TO PERSONAL DIARY###\n");

    printf("\n\t**********************************************\n");

    printf("\n\n\tPress any key to Enter the Main Menu->  ");
    getch();
    system("cls");

    printf("\n\n\n\n\t\tLoading... Please wait....\n\n\n");
}
void Mainmenu()
{
    printf("\n\n\t\tMAIN MENU:");
        printf("\n\t******************************\n");
        printf("\n\n\t1. ADD RECORD\t");
        printf("\n\t******************************\n");
        printf("\n\t2. VIEW RECORD\t");
        printf("\n\t******************************\n");
        printf("\n\n\tPress 0 to EXIT....\t\t");
        printf("\n\t******************************\n");
}

void worng()
{
     printf("\n\n\n\t\tYOU ENTERED WRONG CHOICE..\n\n");

            printf("\n\t\tPRESS ANY KEY TO TRY AGAIN\n ");

            getch();
}
