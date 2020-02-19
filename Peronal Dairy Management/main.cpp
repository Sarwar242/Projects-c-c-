#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<conio.h>
#include<windows.h>
#include"Record.h"
#include"Welcome.h"

using namespace std;

int main()
{
    char ch;
    Welcome();
    while(1)
    {
        First:
        system("cls");
        Mainmenu();
        fflush(stdin);
        cout<<"\n\n\tENTER YOUR CHOICE: ";
        ch=getche();

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
            worng();
            goto First;
        }
    }

    return 0;
}


