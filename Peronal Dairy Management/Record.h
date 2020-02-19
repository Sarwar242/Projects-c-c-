#include"validy.h"

using namespace std;

void addrecord();
void viewrecord();

struct record

{
    char time[6];

    char name[30];

    char place[25];

    char note[500];

};
int dd,tt,choice;

void addrecord()

{
    system("cls");

    FILE *fp ;
    FILE *fpv;

    char another = 'Y' ,time[10];

    struct record e ;

    char filename[15];
    char name[100],date[100];
    int lb=0;
    tt=0;
    choice=0;
    int tell=0;
    cout<<"\n\n\t\t  ***************************\n";

    cout<<"\t\t* WELCOME TO THE ADD NOTE MENU *";

    cout<<"\n\t\t  ***************************\n\n";
    valid:
        if(lb==1)
            {
            system("cls");
            cout<<"\n\t**************** ADD MENU *****************\n\n\n";
        }
    cout<<"\n\n\tENTER DATE OF YOUR RECORD:[dd-mm-yyyy]: ";

    fflush(stdin);

    cin.getline(filename,15);
    strcpy(date,filename);

    dd=datecheck(filename);
    if(dd==0)
    {

        cout<<"\n\tSorry, Invalid date. Try again...\n\n\tPress any key... ";
        lb=1;
        getch();

        goto valid;
    }

    fp = fopen (filename, "r" ) ;

    if ( fp != NULL )

    {

//        fp=fopen(filename,"w+");
        cout<<"\n\tDate already exist.\n";

        cout<<"\n\tPRESS ANY KEY... ";
        getch();

        goto valid ;

    }
    fp = fopen (filename, "w+" ) ;
    while ( another == 'Y'|| another=='y' )
    {
        tm:
        choice=0;

        fflush(stdin);

        cout<<"\n\tENTER TIME[hh.mm] : ";

        cin.getline(time,6);
        tell=timecheck(time);
        if(tell==0)
        {
        cout<<"\t[Sorry, Invalid Time. Enter  again...]\n";
        tt=1;
        goto tm;
        }

        strcpy(e.time,time);

        cout<<"\n\tENTER NAME: ";

        fflush(stdin);

        cin.getline(e.name,30);
        strcpy(name,e.name);

        fflush(stdin);

        cout<<"\n\tENTER PLACE: ";

        cin.getline(e.place,25);

        fflush(stdin);

        printf("\n\tNOTE: ");

        cin.getline(e.note,500);

        fwrite ( &e, sizeof ( e ), 1, fp ) ;

        cout<<"\n\t\tYOUR RECORD IS ADDED...\n";

        cout<<"\n\tADD ANOTHER RECORD OF THE DATE...(Y/N) ";

        fflush (stdin);

        another = getchar();

    }

    fclose ( fp ) ;
    fpv=fopen("Records.txt","a+");

    fprintf(fpv,"%s %s\n",date,name);
    fclose(fpv);

    cout<<"\n\n\tPRESS ANY KEY TO Go To MAIN MENU...";

    getch();

}
int mm;
void viewrecord()
{

    FILE *fpte ;
    FILE *fv;
    system("cls");

    struct record customer ;

    char choice,filename[14];
    char name[100],date[100];

    int ch,la=0;

        system("cls");
        cout<<"\n\n\t\t*******************************"<<endl;

        cout<<"\t\t* HERE IS THE VIEWING MENU *"<<endl;

    cout<<"\n\t\t*******************************\n"<<endl;
    cool:

        if(la==1)
        {
            system("cls");
            cout<<"\n\t********View Menu*********\n"<<endl;
        }

        cout<<"\n\n\t[Enter 0 to go to main menu] \n"<<endl;
        fflush(stdout);
    fv=fopen("Records.txt","r+");
    rewind(fv);
    if(fv==NULL)
    {
        cout<<"\n\n\tDatabase Missing\n\n\tPress any key... ";
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

        cout<<"\n\n\tENTER THE DATE OF RECORD TO BE VIEWED:[dd-mm-yyyy]: ";
        fflush(stdin);
        cin.getline(filename,15);
        ch=atoi(filename);
        if(ch==0)
            return;
        mm=datecheck(filename);
        if(mm==0)
        {
            cout<<"\n\tSorry, Invalid date. Try again...\n\n\tPress any key... ";
            getch();
            la=1;
            goto cool;
    }

        fpte = fopen ( filename, "r");

        if ( fpte == NULL )

        {

            cout<<"\n\tTHE RECORD DOES NOT EXIST..."<<endl;

            cout<<"\n\tPRESS ANY KEY... ";
            la=1;
            getch();

            goto cool;

        }

        system("cls");
        fpte=fopen(filename,"r");
        rewind(fpte);

            cout<<"\n\tTHE RECORD FOR "<<filename<<" IS: "<<endl;

//            while (==1)
//
//
                fread(&customer, sizeof(customer),1,fpte);
                cout<<""<<endl;
                cout<<"\n\tTIME: "<<customer.time<<endl;
                cout<<"\n\n\tName: "<<customer.name<<endl;
                cout<<"\n\n\tPlace: "<<customer.place<<endl;
                cout<<"\n\n\tNOTE: "<<customer.note<<endl;
                cout<<""<<endl;

            //}
        cout<<"\n\n\tWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N): ";
        fflush(stdin);

        cin>>choice;
        fclose(fpte);

    if(choice=='Y'||choice=='y')
    {
        la=1;
        goto cool;
    }
    else
        return;
}

