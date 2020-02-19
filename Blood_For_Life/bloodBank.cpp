#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include<dos.h>
#include "bloodBank.h"

using namespace std;
void bb();
void nd();
void ins();
void sti();
void temp();
void exitf();
void loading();

int total, o;
char a, b[10];
COORD coord= {0,0};
struct univ
{
    char name[85];
    char mobile[16];
    char adress[100];
    char bg[5];
    char ldd[12];
    char ctd[12];
} cat[1000];
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void bloodBank::ins()
{
    int i;
    FILE *fp7;
    fp7=fopen("td.txt", "r");
    fscanf(fp7,"%d", &o);
    fclose(fp7);
    FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6;
    fp1=fopen("name.txt", "r");
    fp2=fopen("mobile.txt", "r");
    fp3=fopen("adress.txt", "r");
    fp4=fopen("bg.txt", "r");
    fp5=fopen("ldd.txt", "r");
    fp6=fopen("ctd.txt", "r");
    for(i=0; i<o; i++)
    {
        fscanf(fp1,"%s", cat[i].name);
        fscanf(fp2,"%s", cat[i].mobile);
        fscanf(fp3,"%s", cat[i].adress);
        fscanf(fp4,"%s", cat[i].bg);
        fscanf(fp5,"%s", cat[i].ldd);
        fscanf(fp6,"%s", cat[i].ctd);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp6);


}

void bloodBank::loading()
{
    system("cls");
    for(int i=1; i<=50; i++)
    {
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t   Loading "<<'\n'<<'\t'<<'\t';
        for(int j=1; j<=i; j++)
            cout<<"*";
        cout<<"\n\n\t "<<2*i<<"%";
        if( i > 1 && i < 20)
            cout<<"\n\n\tLoading...";
        else if( i > 20 && i<40)
            cout<<"\n\n\tAccessing to Database...";
        else if(i >40 && i<48)
            cout<<"\n\n\tcompleting...";
        else
            cout<<"\n\n\tCompleted. Press Enter to Continue ";
    }
}

void bloodBank::menu()
{

    system("cls");
    cout<<"\n\n\t\t\tBlood For Life."<<endl;
    cout<<"\n\t\t\t     Menu"<<endl;
    cout<<"\n1. Blood Bank."<<endl;
    cout<<"2. New Donor."<<endl;
    cout<<"3. Exit."<<endl;
    gotoxy(20,20);
    fflush(stdin);
    cout<<"Enter Your Choice: ";

    cin>>a;
    switch (a)
    {
    case '1':
        loading();
        bb();
        break;
    case '2':
        nd();
        break;
    case '3':
        exitf();
    default:
        menu();
    }
}


void bloodBank::bb()
{

    system("cls");
    char ch[5];
    int tu[o], l, i, m=0;
    cout<<"\n\n\t\t\tBlood For Life.";
    gotoxy(10,10);
    cout<<"Enter the Blood Group(Ex: AB+): ";
    fflush(stdin);
    cin>>ch;
    l=strlen(ch);
    for(i=0; i<l; i++)
    {
        if(ch[i]>'Z'&&ch[i]!='+'&&ch[i]!='-')
        {
            ch[i]=ch[i]-32;
        }
    }

    for (i=0; i<o; i++)
    {
        if(strcmp(ch,cat[i].bg));
        else
        {
            tu[m]=i;
            m++;
        }
    }
    total=m;
    if(m==0)
    {
        system("cls");
        gotoxy(10,10);
        cout<<"No Donor Available,Please Pray To Almighty God....";
        gotoxy(10,15);
        cout<<"press Any Key to continue(0 to Go Back): ";
        fflush(stdin);
        cin>>a;
        if(a=='0')
        {
            system("cls");
            menu();
        }
        system("cls");
        bb();
    }
    else
    {
        char b[8];

loop1:
        system("cls");
        temp();
        int i, j, y=7, len;
        for (i=0; i<m; i++)
        {
            j=tu[i];
            gotoxy(2,y);
            if(i<9)
            {
                printf("0");
            }
            cout<<i+1<<".  "<<cat[j].name;
            gotoxy(35,y);
            cout<<cat[j].bg;
            gotoxy(45,y);
            cout<<cat[j].ldd;
            gotoxy(63,y);
            cout<<cat[j].ctd;
            y++;
        }
        gotoxy(20,y+1);
        fflush(stdin);
        cout<<"Enter Your Choice(0 to go back): ";
        cin>>b;
        len=strlen(b);
        if(len==1&&b[0]=='0')
        {
            menu();
        }
        int index=0, k;
        for (k=0; k<len; k++)
        {
            if((b[i]-48)>9)
            {
                goto loop1;
            }
            index=index*10;
            index=index+(b[k]-48);
        }
        int s;
        if(index>0&&index<=m)
        {
            s=tu[index-1];
            system("cls");
            gotoxy(20,3);
            fflush(stdout);
            cout<<"Blood Bank";
            gotoxy(0,5);
            cout<<"Name: "<<cat[s].name<<endl;
            gotoxy(0,7);
            cout<<"Blood Group: "<<cat[s].bg;
            gotoxy(0,8);
            cout<<"Mobile No: "<<cat[s].mobile;
            gotoxy(0,9);
            cout<<"Adress: "<<cat[s].adress;
            gotoxy(0,10);
            cout<<"Last donation Date: "<<cat[s].ldd;
            gotoxy(0,11);
            cout<<"Next Donation Date: "<<cat[s].ctd;
            getch();
            gotoxy(20,15);
            fflush(stdin);
            cout<<"Press any key to go back(0 to go to menu): ";
            cin>>a;
            if(a=='0')
            {
                menu();
            }
            else
            {
                goto loop1;
            }
        }
        else
        {
            goto loop1;
        }

    }
}


void bloodBank::temp()
{
    int y=5;
    system("cls");
    gotoxy(29,1);
    cout<<"Blood Bank";
    gotoxy(0,3);
    cout<<"Total Donor Number is: "<<total;
    gotoxy(0,y);
    cout<<" S. Name.";
    gotoxy(35,y);
    cout<<"BG.";
    gotoxy(42,y);
    cout<<"Last donation.";
    gotoxy(58,y);
    cout<<"Next Donation After.";
}


/// have to be completed.........

void bloodBank::nd()
{
    struct uni
    {
        char nam[85];
        char mobil[16];
        char adres[100];
        char bw[5];
        char ld[12];
        char ct[12];
    } b[1];
    int i;
    system("cls");
    cout<<"\n\n\t\t\tBlood For Life.\n"<<endl;
    cout<<"\t\t\t   NEW DONOR.";
    gotoxy(5,7);
    fflush(stdin);
    cout<<"Enter The Name(Ex: TONY_STARK): ";
    cin>>b[0].nam;
    gotoxy(5,9);
    fflush(stdin);
    cout<<"Enter The Mobile No(Ex: 01771803094): ";
    cin>>b[0].mobil;
    gotoxy(5,11);
    fflush(stdin);
    cout<<"Enter The Adress(Use '_' instead of Blank Space): ";
    cin>>b[0].adres;
    gotoxy(5,13);
    fflush(stdin);
    cout<<"Enter The Blood Group(Ex: AB+): ";
    cin>>b[0].bw;
    int l;
    l=strlen(b[0].bw);
    for(i=0; i<l; i++)
    {
        if(b[0].bw[i]>'Z'&&b[0].bw[i]!='+'&&b[0].bw[i]!='-')
        {
            b[0].bw[i]=b[0].bw[i]-32;
        }
    }

    gotoxy(5,15);
    fflush(stdin);
    cout<<"Enter The Last Donation Date(Ex: dd-mm-yy): ";
    cin>>b[0].ld;
    gotoxy(5,17);
    cout<<"Enter The Next Donation Date(Ex: dd-mm-yy): ";
    cin>>b[0].ct;
    o++;
    FILE *fp7;
    fp7=fopen("td.txt", "w");
    fprintf(fp7,"%d", o);
    fclose(fp7);
    FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6;
    fp1=fopen("name.txt", "a");
    fp2=fopen("mobile.txt", "a");
    fp3=fopen("adress.txt", "a");
    fp4=fopen("bg.txt", "a");
    fp5=fopen("ldd.txt", "a");
    fp6=fopen("ctd.txt", "a");
    fprintf(fp1,"\n");
    fprintf(fp2,"\n");
    fprintf(fp3,"\n");
    fprintf(fp4,"\n");
    fprintf(fp5,"\n");
    fprintf(fp6,"\n");
    fprintf(fp1,"%s", b[0].nam);
    fprintf(fp2,"%s", b[0].mobil);
    fprintf(fp3,"%s", b[0].adres);
    fprintf(fp4,"%s", b[0].bw);
    fprintf(fp5,"%s", b[0].ld);
    fprintf(fp6,"%s", b[0].ct);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp6);
    ins();
    menu();
}

void bloodBank::exitf()
{
    system("cls");
    gotoxy(15,10);
    cout<<"Donate Blood And Save Life\n               Someday Your's May Be Saved  \n\n\n"<<endl;
    exit(0);
}

