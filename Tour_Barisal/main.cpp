#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include "Place.h"

using namespace std;

int main()
{
    cout<<"\t\t Tour  Barisal Application\n";
    cout<<"\t\t______________________________\n"<<endl;
    cout<<"\tPress any key to continue to main menu...   ";
    getch();
    printf("Loading....\n");
    while(1)
    {
        Place p;
        main:
        system("cls");
        cout<<"\n\n\t\t\t *** MAIN MENU ***"<<endl;
        cout<<"\t\t\t_________________________\n"<<endl;
        cout<<"\n\t\t 1.Enter 1 for Show Landmark Place's List."<<endl;
        cout<<"\n\t\t 2.Enter 2 for Developer Details."<<endl;
        cout<<"\n\t\t 3.Enter 3 for Exit.\n"<<endl;
        int ch;
        fflush(stdin);
        cout<<"\t\tEnter Menu No: ";
        cin>>ch;

        if(ch==1)
        {   mnu:
            p.Places();
            if(p.Places()==1)
                goto mnu;
            else
                goto main;
        }
        else if(ch==2)
        {
            p.Developer();
            goto main;
        }
        else if(ch==3)
        {
            cout<<"\n\n\tThank you for using this Application....\n\n"<<endl;

            return 0;
        }
        else
        {
            system("cls");
            cout<<"\n\n\n\tSorry you have enter a wrong choice ..\n\n\tPress any key to go back to main menu .. ";
            goto main;
        }
    }

    return 0;
}
