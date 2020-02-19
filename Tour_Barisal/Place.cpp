#include<iostream>
#include<cstdlib>
#include<fstream>
#include<conio.h>
#include "Place.h"
#define ltr 5000

using namespace std;

char Kuakata[ltr]={'\0'},bibichini_shahi_mosque[ltr]={'\0'},Barisal_local[ltr]={'\0'};
char Horinghata[ltr]={'\0'},tengragiri[ltr]={'\0'},Fatrarchor[ltr]={'\0'};
char guthia_mosque[ltr]={'\0'},Developer[ltr]={'\0'};
char Monpura[ltr]={'\0'},kukri_mukri[ltr]={'\0'},rakhain_area[ltr]={'\0'};

Place::Places()
{
    system("cls");
    int op;
    ifstream outfile;

    cout<<"\n\n\t\t*** List of Visiting Places ***\n\n";
    cout<<"\t________________________________________________________\n"<<endl;
    cout<<"\n\n\t 1.  Barisal city local Landmarks...\n"<<endl;
    cout<<"\n\n\t 2.  Bibichini Shahi Mosque...\n"<<endl;
    cout<<"\n\n\t 3.  Fatrar Chor...\n"<<endl;
    cout<<"\n\n\t 4.  Guthia Mosque...\n"<<endl;
    cout<<"\n\n\t 5.  Horin Ghata...\n"<<endl;
    cout<<"\n\n\t 6.  Kuakata Sea Beach...\n"<<endl;
    cout<<"\n\n\t 7.  Chor Kukri-Mukri...\n"<<endl;
    cout<<"\n\n\t 8.  Monpura Dwip...\n"<<endl;
    cout<<"\n\n\t 9.  Rakhain Area...\n"<<endl;
    cout<<"\n\n\t 10. Tengragiri Bon & Eco Park...\n"<<endl;
    cout<<"\n\n\n\t\t*** Enter 0 to go to main menu ***\n"<<endl;
    fflush(stdin);
    cout<<"\n\tEnter your Place number in the list you wish to see ... ";
    fflush(stdin);
    cin>>op;
    if(op==0){
        return 0;}
    else if(op==1){
        system("cls");
        cout<<"\n\n\t\t***Traveling***\n";
        outfile.open("Docs/Barisal_local.txt");
        while (!outfile.eof()) {
            outfile.getline(Barisal_local,5000);
            cout<<Barisal_local<<endl;
            }
        cout<<endl;
        outfile.close();
        cout<<"\n\n\n\tPress any key to continue .... ";
        getch();
        return 1;
        }

    else if(op==2){
        system("cls");
        cout<<"\n\n\t\t***Traveling***\n";
        outfile.open("Docs/bibichini_shahi_mosque.txt");
        while (!outfile.eof()) {
            outfile.getline(bibichini_shahi_mosque,5000);
            cout<<bibichini_shahi_mosque<<endl;
            }
        cout<<endl;
        outfile.close();
        cout<<"\n\n\n\nPress any key to continue .... ";
        getch();
        return 1;
        }

    else if(op==3)
    {
        system("cls");
        cout<<"\n\n\t\t***Traveling***\n";
        outfile.open("Docs/Fatrarchor.txt");
        while (!outfile.eof()) {
            outfile.getline(Fatrarchor,5000);
            cout<<Fatrarchor<<endl;
            }
        cout<<endl;
        outfile.close();
        cout<<"\n\n\n\nPress any key to continue .... ";
        getch();

        return 1;
    }

    else if(op==4)
        {
        system("cls");
        cout<<"\n\n\t\t***Traveling***\n";
        outfile.open("Docs/guthia_mosque.txt");
        while (!outfile.eof()) {
            outfile.getline(guthia_mosque,5000);
            cout<<guthia_mosque<<endl;
            }
        cout<<endl;
        outfile.close();
        cout<<"\n\n\n\nPress any key to continue .... ";
        getch();
        return 1;
        }

    else if(op==5)
    {
        system("cls");
        cout<<"\n\n\t\t***Traveling***\n";
        outfile.open("Docs/Horinghata.txt");
        while (!outfile.eof()) {
            outfile.getline(Horinghata,5000);
            cout<<Horinghata<<endl;
            }
        cout<<endl;
        outfile.close();
        cout<<"\n\n\n\nPress any key to continue .... ";
        getch();
        return 1;
        }

    else if(op==6)
    {
        system("cls");
        cout<<"\n\n\t\t***Traveling***\n";
        outfile.open("Docs/Kuakata.txt");
        while (!outfile.eof()) {
            outfile.getline(Kuakata,5000);
            cout<<Kuakata<<endl;
            }
        cout<<endl;
        outfile.close();
        cout<<"\n\n\n\nPress any key to continue .... ";
        getch();
        return 1;
    }

    else if(op==7)
    {
        system("cls");
        cout<<"\n\n\t\t***Traveling***\n";
        outfile.open("Docs/kukri_mukri.txt");
        while (!outfile.eof()) {
            outfile.getline(kukri_mukri,5000);
            cout<<kukri_mukri<<endl;
            }
        cout<<endl;
        outfile.close();
        cout<<"\n\n\n\nPress any key to continue .... ";
        getch();
        return 1;
    }

    else if(op==8)
    {
        system("cls");
        cout<<"\n\n\t\t***Traveling***\n";
        outfile.open("Docs/Monpura.txt");
        while (!outfile.eof()) {
            outfile.getline(Monpura,5000);
            cout<<Monpura<<endl;
            }
        cout<<endl;
        outfile.close();
        cout<<"\n\n\n\nPress any key to continue .... ";
        getch();
         return 1;
    }

    else if(op==9)
    {
        system("cls");
        cout<<"\n\n\t\t***Traveling***\n";
        outfile.open("Docs/rakhain_area.txt");
        while (!outfile.eof()) {
            outfile.getline(rakhain_area,5000);
            cout<<rakhain_area<<endl;
            }
        cout<<endl;
        outfile.close();
        cout<<"\n\n\n\nPress any key to continue .... ";
        getch();
        return 1;
    }

    else if(op==10)
        {
        system("cls");
        cout<<"\n\n\t\t***Traveling***\n";
        outfile.open("Docs/tengragiri.txt");
        while (!outfile.eof()) {
            outfile.getline(tengragiri,5000);
            cout<<tengragiri<<endl;
            }
        cout<<endl;
        outfile.close();
        cout<<"\n\n\n\nPress any key to continue .... ";
        getch();
        return 1;
    }
    else{
            system("cls");
            cout<<"\n\n\n\n\tSorry, wrong keyword... try again...\n\n\n\tPress any key...";
            getch();
            return 1;
    }

}

Place::Developer()
{
    ifstream outfile;
    char dev[5000];
    system("cls");
    cout<<"\n\n\t\t***Welcome***\n"<<endl;
    outfile.open("Docs/Developer.txt");
    while (!outfile.eof()) {
        outfile.getline(dev,5000);
        cout<<dev<<endl;
            }
    cout<<endl;
    outfile.close();
    cout<<"\n\n\n\nPress any key to continue .... ";
    getch();
    return 0;
}
