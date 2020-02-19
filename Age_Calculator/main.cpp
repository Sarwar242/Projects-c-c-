#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<windows.h>
#include"myHeader.h"
#include"ageClass.h"

using namespace std;

int main()
{
    char ch;
    myHeader funcs;
    ageClass ac;

    funcs.loading();
    while(1)
    {
        system("cls");
        ac.printBuildDateTime();
        cout<<"\n\t\t1. Different Date Age."<<endl;
        cout<<"\n\t\t2. Current Date Age."<<endl;
        cout<<"\n\t\t3. Get your Birth Date."<<endl;
        cout<<"\n\t\t0. Exit."<<endl;
        cout<<"\n\t\tEnter Your Choice: ";
        ch= getche();

        switch(ch)
        {

        case '0':
            exit(0);
        case '1':
            funcs.DateDifference();
            break;
        case '2':
            ac.currentDateAge();
            break;

        case '3':
            ac.getDateofBirth();
            break;


        default:
            break;
        }
    }
    return 0;
}
