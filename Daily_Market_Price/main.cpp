#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void view_item();
void edit_item();
void add_new();
void delete_item();

struct market{
        char name[100];
        char quantity[40];
        double price;

};


int main()
{
    int ch;


    printf("\n\n\n\n\t*****************************************************************\n\n");

    printf("\t\t ***Welcome to Daily Market Price Application***\n");

    printf("\n\t*****************************************************************\n");

    printf("\n\n\tPress any key to enter the main menu ");

    getch();

    while(1)
    {

        system("cls");
        printf("\n\n\t\t\t*******MAINMENU******** \t\n");
        printf("\n\n\tOptions :: ");
        printf("\n\n\t1. View Items.\n");
        printf("\n\t2. Edit Items.\n");
        printf("\n\t3. Add New Item.\n");
        printf("\n\t4. Delete Item.\n");
        printf("\n\t5. Exit.\n\n");
        printf("\n\tEnter your choice : ");

        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            view_item();
            break;

        case 2:
            edit_item();
            break;

        case 3:
            add_new();
            break;

        case 4:
            delete_item();
            break;

        case 5:
            system("cls");
            printf("\n\n\n\n\tThank You for Using this Application\n\n\tPress any key ");
            getch();
            printf("\n\n\n\n\n");
            return 0;

        default :
            system("cls");
            printf("\n\n\n\n\tYou have enter a wrong choice.\n\n\tPress any key to get back to main menu ");
            getch();
            break;
        }

    }

    return 0;
}

void view_item()
{
    system("cls");
    FILE *fpte;
    struct market vitem;

    printf("\n\n\t*******************************\n");

    printf("\t* HERE IS THE VIEWING MENU *");

    printf("\n\t*******************************\n\n");

    printf("\n\n\tPress any key to View items with price ");
    getch();

    fpte=fopen("filename.txt","r+");
    if(fpte==NULL)
    {
        system("cls");
        printf("\n\n\n\n\t Sorry, Daily Market price database is missing. \n\n\t Please contract the Authority.\n\n");
        printf("\n\tPRESS ANY KEY TO EXIT...\n");
        getch();
        return;
    }
    system("cls");

    printf("\n\t\t *** Daily Market Price ***\n\n");
    printf("\n\tItems list with price\n");
    printf("\n\t%Item Name  \t \t\t %Quantity \t \t  Price\n");
    while(fread(&vitem,sizeof(vitem),1,fpte)==1)
    {
        printf("\n\t %-15s   \t \t %-15s \t  %-10.2lf\n",vitem.name,vitem.quantity,vitem.price);

    }
    printf("\n\n\n\tPress any key.... ");
    getch();
    return;
}

void edit_item()
{
    system("cls");
    FILE *ftpe;
    char name[50]={'\0'};
    struct market edit;
    printf("\n\n\t\t*******************************\n");
    printf("\n\n\t*** WELCOME TO EDIT ITEM PRICE MENU. ***\n");
    printf("\n\n\t\t*******************************\n");

    printf("\n\n\tEnter The Name Of The Item To Be Edited: ");
    fflush(stdin);
    gets(name);

    ftpe=fopen("filename.txt","r+");
    if(ftpe==NULL)
    {
        printf("\n\n\tThe Database does not exist..\n\n");
        printf("\n\n\tPRESS ANY KEY TO GO BACK ");
        getch();
        return;
    }

    while(fread(&edit,sizeof(edit),1,ftpe)==1)
    {

        if(strcmp(edit.name,name)==0)
        {

            printf("\n\n\tThe old item was : ");

            printf("\n\n\t#Name: %s\t #Quantity: %s\t #Price : %10.2lf.\n\n\n",edit.name,edit.quantity,edit.price);
            fflush(stdin);
            printf("\n\tEnter new price of ## %s : ",edit.name);
            scanf("%lf",&edit.price);

            fseek(ftpe,-sizeof(edit),SEEK_CUR);
            fwrite(&edit,sizeof(edit),1,ftpe);
            fseek(ftpe,-sizeof(edit.price),SEEK_CUR);
            fread(&edit,sizeof(edit),1,ftpe);
            fflush(stdout);
            printf("\n\n\tThe Item Price Have Been Successfully Edited. \n\n");
            fclose(ftpe);
        break;
        }
    }

    printf("\n\n\tPress any key ");
    getch();
    return;
}

void add_new(){
    system("cls");
    FILE *fp;
    char name[50]={'\0'};
    struct market item;
    int choice,a=1;
    printf("\n\n\n\t ***Welcome to Add new item menu***\n\n");
    fp=fopen("filename.txt","a+");
    if(fp==NULL)
    {
        fp=fopen("filename.txt","w+");
        if(fp==NULL)
        {
            system("cls");

            printf("\n\n\n\tSystem Error.\n\n\n\tPress any key to go to main menu ");

            getch();
            return;
        }
    }
    while(a==1)
    {
        choice=0;
        system("cls");
        fflush(stdin);
        printf("\n\n\tEnter item name :: ");

        gets(name);
        rewind(fp);
        while(fread(&item,sizeof(item),1,fp)==1)
        {
            if(strcmp(item.name,name)==0)
            {
                printf("\n\n\tThis item already exist.\n\n");

                choice=1;
            }

        }

        if(choice==0)
        {
            strcpy(item.name,name);
            fflush(stdin);
            printf("\n\n\tEnter Quantity :: ");
            gets(item.quantity);

            printf("\n\n\tEnter price :: ");
            fflush(stdin);
            scanf("%lf",&item.price);

            fwrite(&item,sizeof(item),1,fp);

            printf("\n\n\tThis Item is Added.\n");
        }

        printf("\n\n\n\tAdd another item enter- 1.\n\n\tGo to main menu enter 2. \n\n\t");
        scanf("%d",&a);

    }
    fclose(fp);
    printf("\n\n\tPress any key to go to main menu ");
    getch();
    return;
}


void delete_item()
{
    system("cls");
    char name[50]={'\0'};
    struct market del;
    FILE *fp,*fpt;
    printf("\n\n\n\t*** Welcome to delete item menu ***");

    fp=fopen("filename.txt","r+");
    if(fp==NULL)
    {
        printf("\n\n\t Database is missing...\n\n\tPress any key to go back.. ");
        getch();
        return;
    }

    fpt=fopen("temp.txt","w+");
    if(fpt==NULL)

        {

        printf("\n\n\tSYSTEM ERROR");

        printf("\n\n\n\tPRESS ANY KEY TO GO BACK ");

        getch();

        return ;

        }

    fflush(stdin);
    printf("\n\n\n\tEnter The Name Of The Item To Be Deleted :  ");
    gets(name);

    while(fread(&del,sizeof(del),1,fp))
        {

        if(strcmp(del.name,name)!=0)
            fwrite(&del,sizeof(del),1,fpt);
        }
    fclose(fp);
    fclose(fpt);
    remove("filename.txt");
    rename("temp.txt","filename.txt");
    printf("\n\n\n\n\tDeleted Successfully....\n\n\n\n\tPress any key to go back... ");
    getch();
    return;
}

