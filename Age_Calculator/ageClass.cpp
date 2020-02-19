#include "ageClass.h"
#include<iostream>
#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include "myHeader.h"

using namespace std;
COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ageClass::t()
{


    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    //getdate(&d);
    //gettime(&t);
    gotoxy(55,1);
    printf("Date: %d-%d-%d \n",now->tm_mday,(now->tm_mon)+1,(now->tm_year)+1900);
    gotoxy(55,2);
    printf("Time: %d:%d:%d \n",now->tm_hour, now->tm_min,now->tm_sec);
}

void ageClass:: printBuildDateTime ()
{
    cout <<"\n\t\t\t\t\t" <<__TIMESTAMP__ << endl;
}

ageClass::isLeapYear(int year, int mon)
{
    int flag = 0;
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            if (mon == 2)
            {
                flag = 1;
            }
        }
    }
    else if (year % 4 == 0)
    {
        if (mon == 2)
        {
            flag = 1;
        }
    }
    return (flag);
}


void ageClass::currentDateAge()
{
    char f2='n';
    time_t ts;
    struct tm *ct;
    do
    {
        system("cls");
        t();

        /*get current date.*/
        ts = time(NULL);
        ct = localtime(&ts);

        long long int x2,x12,a2,b2,k2,i2,j2,n2,C2,n,Y1,Y2,M1,M2,D1,D2,C,r,a,b,c,x1,N,i,j,k,x,y,m,d,y1,y2,m1,m2,d1,d2;
        char c1,c5;
        x2=0;
        x12=0;
        a2=0;
        b2=0;
        k2=0;
        i2=0;
        j2=0;
        n2=0;
        C2=0;
        n=0;
        C=0;
        N=0;
        c=0;
        y=0;
        m=0;
        d=0;

        cout<<"\tEnter your birthday date[yyyy/mm/dd]: ";
        cin>>y1>>c1>>m1>>c5>>d1;
        cout<<endl;
        y2=(ct->tm_year )+ 1900;
        m2=(ct->tm_mon )+ 1;
        d2=ct->tm_mday;
        cout<<"\n\tCurrent Date: "<< y2<<"/"<<m2<<"/"<<d2<<endl;
        r=d2;
        Y1=y1;
        Y2=y2;
        M1=m1;
        M2=m2;
        D1=d1;
        D2=d2;
        if ((y1*10000+m1*100+d1)>(y2*10000+m2*100+d2))
        {
            cout<<"\tError.."<<endl;
        }
        else
        {
            if (m2>m1)
                y=y2-y1;
            if (m2<m1)
                y=y2-y1-1;
            if (m2==m1)
            {
                if (d2>=d1)
                    y=y2-y1;
                else
                    y=y2-y1-1;
            }
            if (m2>m1)
            {
                if (d2>=d1)
                    m=m2-m1;
                else
                    m=m2-m1-1;
            }
            if (m2==m1)
            {
                if (d2>=d1)
                    m=m2-m1;
                else
                    m=11;
            }
            if (m2<m1)
            {
                if (d2>=d1)
                    m=12+m2-m1;
                else
                    m=11+m2-m1;
            }
            if (d2>=d1)
                d=d2-d1;
            else
            {
                if (m2-1==1)
                    d=31+d2-d1;
                if (m2-1==2)
                {
                    if (y1%4==0 && y1%400!=100 && y1%400!=200 && y1%400!=300)
                        d=29+d2-d1;
                    else
                        d=28+d2-d1;
                }
                if (m2-1==3)
                    d=31+d2-d1;
                if (m2-1==4)
                    d=30+d2-d1;
                if (m2-1==5)
                    d=31+d2-d1;
                if (m2-1==6)
                    d=30+d2-d1;
                if (m2-1==7)
                    d=31+d2-d1;
                if (m2-1==8)
                    d=31+d2-d1;
                if (m2-1==9)
                    d=30+d2-d1;
                if (m2-1==10)
                    d=31+d2-d1;
                if (m2-1==11)
                    d=30+d2-d1;
                if (m2-1==12)
                    d=31+d2-d1;
            }
            if (20000101<(Y1*10000+M1*100+D1))
            {
                for (a=1; a<M1; a++)
                {
                    if (a==1)
                        x1=31;
                    if (a==2)
                    {
                        if (Y1%4==0 && Y1%400!=100 && Y1%400!=200 && Y1%400!=300)
                            x1=29;
                        else
                            x1=28;
                    }
                    if (a==3)
                        x1=31;
                    if (a==4)
                        x1=30;
                    if (a==5)
                        x1=31;
                    if (a==6)
                        x1=30;
                    if (a==7)
                        x1=31;
                    if (a==8)
                        x1=31;
                    if (a==9)
                        x1=30;
                    if (a==10)
                        x1=31;
                    if (a==11)
                        x1=30;
                    if (a==12)
                        x1=31;
                    for (b=1; b<=x1; b++)
                        C++;
                    n=1;
                }
                if (2000<Y1)
                {
                    for (i=2000; i<Y1; i++)
                    {
                        for (j=1; j<=12; j++)
                        {
                            if (j==1)
                                x=31;
                            if (j==2)
                            {
                                if (i%4==0 && i%400!=100 && i%400!=200 && i%400!=300)
                                    x=29;
                                else
                                    x=28;
                            }
                            if (j==3)
                                x=31;
                            if (j==4)
                                x=30;
                            if (j==5)
                                x=31;
                            if (j==6)
                                x=30;
                            if (j==7)
                                x=31;
                            if (j==8)
                                x=31;
                            if (j==9)
                                x=30;
                            if (j==10)
                                x=31;
                            if (j==11)
                                x=30;
                            if (j==12)
                                x=31;
                            for (k=1; k<=x; k++)
                                n++;
                        }
                    }
                    C--;
                }
                C++;
                cout<<"\tYou were borned on ";
                if ((n+C+D1-1)%7==1)
                    cout<<"Saturday.";
                if ((n+C+D1-1)%7==2)
                    cout<<"Sunday.";
                if ((n+C+D1-1)%7==3)
                    cout<<"Monday.";
                if ((n+C+D1-1)%7==4)
                    cout<<"Tuesday.";
                if ((n+C+D1-1)%7==5)
                    cout<<"Wednesday.";
                if ((n+C+D1-1)%7==6)
                    cout<<"Thursday.";
                if ((n+C+D1-1)%7==0)
                    cout<<"Friday.";
            }
            if (20000101==(Y1*10000+M1*100+D1))
                cout<<"\tYou were borned on Saturday";
            if (20000101>(Y1*10000+M1*100+D1))
            {
                for (i=Y1; i<2000; i++)
                {
                    for (j=M1; j<=12; j++)
                    {
                        if (j==1)
                            x=31;
                        if (j==2)
                        {
                            if (i%4==0 && i%400!=100 && i%400!=200 && i%400!=300)
                                x=29;
                            else
                                x=28;
                        }
                        if (j==3)
                            x=31;
                        if (j==4)
                            x=30;
                        if (j==5)
                            x=31;
                        if (j==6)
                            x=30;
                        if (j==7)
                            x=31;
                        if (j==8)
                            x=31;
                        if (j==9)
                            x=30;
                        if (j==10)
                            x=31;
                        if (j==11)
                            x=30;
                        if (j==12)
                            x=31;
                        for (k=D1; k<=x; k++)
                            n++;
                        D1=1;
                    }
                    M1=1;
                }
                cout<<"\tYou were borned on ";
                if ((n-1)%7==6)
                    cout<<"Saturday.";
                if ((n-1)%7==5)
                    cout<<"Sunday.";
                if ((n-1)%7==4)
                    cout<<"Monday.";
                if ((n-1)%7==3)
                    cout<<"Tuesday.";
                if ((n-1)%7==2)
                    cout<<"Wednesday.";
                if ((n-1)%7==1)
                    cout<<"Thursday.";
                if ((n-1)%7==0)
                    cout<<"Friday.";
            }
            if (20000101<(Y2*10000+M2*100+D2))
            {
                for (a2=1; a2<M2; a2++)
                {
                    if (a2==1)
                        x12=31;
                    if (a2==2)
                    {
                        if (Y2%4==0 && Y2%400!=100 && Y2%400!=200 && Y2%400!=300)
                            x12=29;
                        else
                            x12=28;
                    }
                    if (a2==3)
                        x12=31;
                    if (a2==4)
                        x12=30;
                    if (a2==5)
                        x12=31;
                    if (a2==6)
                        x12=30;
                    if (a2==7)
                        x12=31;
                    if (a2==8)
                        x12=31;
                    if (a2==9)
                        x12=30;
                    if (a2==10)
                        x12=31;
                    if (a2==11)
                        x12=30;
                    if (a2==12)
                        x12=31;
                    for (b2=1; b2<=x12; b2++)
                        C2++;
                    n2=1;
                }
                if (2000<Y2)
                {
                    for (i2=2000; i2<Y2; i2++)
                    {
                        for (j2=1; j2<=12; j2++)
                        {
                            if (j2==1)
                                x2=31;
                            if (j2==2)
                            {
                                if (i2%4==0 && i2%400!=100 && i2%400!=200 && i2%400!=300)
                                    x2=29;
                                else
                                    x2=28;
                            }
                            if (j2==3)
                                x2=31;
                            if (j2==4)
                                x2=30;
                            if (j2==5)
                                x2=31;
                            if (j2==6)
                                x2=30;
                            if (j2==7)
                                x2=31;
                            if (j2==8)
                                x2=31;
                            if (j2==9)
                                x2=30;
                            if (j2==10)
                                x2=31;
                            if (j2==11)
                                x2=30;
                            if (j2==12)
                                x2=31;
                            for (k2=1; k2<=x2; k2++)
                                n2++;
                        }
                    }
                    C2--;
                }
                C2++;
                cout<<endl<<"\tToday is ";
                if ((n2+C2+D2-1)%7==1)
                    cout<<"Saturday.";
                if ((n2+C2+D2-1)%7==2)
                    cout<<"Sunday.";
                if ((n2+C2+D2-1)%7==3)
                    cout<<"Monday.";
                if ((n2+C2+D2-1)%7==4)
                    cout<<"Tuesday.";
                if ((n2+C2+D2-1)%7==5)
                    cout<<"Wednesday.";
                if ((n2+C2+D2-1)%7==6)
                    cout<<"Thursday.";
                if ((n2+C2+D2-1)%7==0)
                    cout<<"Friday.";
            }
            if (20000101==(Y2*10000+M2*100+D2))
                cout<<endl<<"Today is Saturday.";
            if (20000101>(Y2*10000+M2*100+D2))
            {
                for (i2=Y2; i2<2000; i2++)
                {
                    for (j2=M2; j2<=12; j2++)
                    {
                        if (j2==1)
                            x2=31;
                        if (j2==2)
                        {
                            if (i2%4==0 && i2%400!=100 && i2%400!=200 && i2%400!=300)
                                x2=29;
                            else
                                x2=28;
                        }
                        if (j2==3)
                            x2=31;
                        if (j2==4)
                            x2=30;
                        if (j2==5)
                            x2=31;
                        if (j2==6)
                            x2=30;
                        if (j2==7)
                            x2=31;
                        if (j2==8)
                            x2=31;
                        if (j2==9)
                            x2=30;
                        if (j2==10)
                            x2=31;
                        if (j2==11)
                            x2=30;
                        if (j2==12)
                            x2=31;
                        for (k2=D2; k2<=x2; k2++)
                            n2++;
                        D2=1;
                    }
                    M2=1;
                }
                cout<<endl<<"Today is ";
                if ((n2-1)%7==6)
                    cout<<"Saturday.";
                if ((n2-1)%7==5)
                    cout<<"Sunday.";
                if ((n2-1)%7==4)
                    cout<<"Monday.";
                if ((n2-1)%7==3)
                    cout<<"Tuesday.";
                if ((n2-1)%7==2)
                    cout<<"Wednesday.";
                if ((n2-1)%7==1)
                    cout<<"Thursday.";
                if ((n2-1)%7==0)
                    cout<<"Friday.";
            }
            cout<<endl<<endl<<"\n\tYou lived "<<y<<" years & "<<m<<" months & "<<d<<" days."<<endl<<endl;
            cout<<"\n\n\tNumber of years = "<<y<<endl;
            cout<<"\tNumber of months = "<<y*12+m<<endl;
            if (y1<y2)
            {
                for (a=1; a<m2; a++)
                {
                    if (a==1)
                        x1=31;
                    if (a==2)
                    {
                        if (y2%4==0 && y2%400!=100 && y2%400!=200 && y2%400!=300)
                            x1=29;
                        else
                            x1=28;
                    }
                    if (a==3)
                        x1=31;
                    if (a==4)
                        x1=30;
                    if (a==5)
                        x1=31;
                    if (a==6)
                        x1=30;
                    if (a==7)
                        x1=31;
                    if (a==8)
                        x1=31;
                    if (a==9)
                        x1=30;
                    if (a==10)
                        x1=31;
                    if (a==11)
                        x1=30;
                    if (a==12)
                        x1=31;
                    for (b=1; b<=x1; b++)
                        c++;
                }
                for (i=y1; i<y2; i++)
                {
                    for (j=m1; j<=12; j++)
                    {
                        if (j==1)
                            x=31;
                        if (j==2)
                        {
                            if (i%4==0 && i%400!=100 && i%400!=200 && i%400!=300)
                                x=29;
                            else
                                x=28;
                        }
                        if (j==3)
                            x=31;
                        if (j==4)
                            x=30;
                        if (j==5)
                            x=31;
                        if (j==6)
                            x=30;
                        if (j==7)
                            x=31;
                        if (j==8)
                            x=31;
                        if (j==9)
                            x=30;
                        if (j==10)
                            x=31;
                        if (j==11)
                            x=30;
                        if (j==12)
                            x=31;
                        for (k=d1; k<=x; k++)
                            N++;
                        d1=1;
                    }
                    m1=1;
                }
                cout<<"\tNumber of weeks = "<<(r+c+N-1)/7<<endl;
                cout<<"\tNumber of days = "<<r+c+N-1<<endl;
                cout<<"\tNumber of hours = "<<(r+c+N-1)*24<<endl;
                cout<<"\tNumber of minutes = "<<(r+c+N-1)*24*60<<endl;
            }
            else
            {
                if (m1<m2)
                {
                    for (j=m1; j<m2; j++)
                    {
                        if (j==1)
                            x=31;
                        if (j==2)
                        {
                            if (y2%4==0 && y2%400!=100 && y2%400!=200 && y2%400!=300)
                                x=29;
                            else
                                x=28;
                        }
                        if (j==3)
                            x=31;
                        if (j==4)
                            x=30;
                        if (j==5)
                            x=31;
                        if (j==6)
                            x=30;
                        if (j==7)
                            x=31;
                        if (j==8)
                            x=31;
                        if (j==9)
                            x=30;
                        if (j==10)
                            x=31;
                        if (j==11)
                            x=30;
                        if (j==12)
                            x=31;
                        for (k=d1; k<=x; k++)
                            N++;
                        d1=1;
                    }
                    cout<<"\tNumber of weeks = "<<(r+N-1)/7<<endl;
                    cout<<"\tNumber of days = "<<r+N-1<<endl;
                    cout<<"\tNumber of hours = "<<(r+N-1)*24<<endl;
                    cout<<"\tNumber of minutes = "<<(r+N-1)*24*60<<endl;
                }
                else
                {
                    cout<<"\tNumber of weeks = "<< d/7<<endl;
                    cout<<"\tNumber of days = "<<d<<endl;
                    cout<<"\tNumber of hours = "<<d*24<<endl;
                    cout<<"\tNumber of minutes = "<<d*24*60<<endl;
                }
            }
        }

        fflush(stdin);

        cout<<"\n\n\tDo you want to Calculate your age again? (y/n): ";
        cin>>f2;
    }
    while(f2=='y');

}

void ageClass::getDateofBirth()
{
    char f2='n';
    int DaysInMon[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31
                      };
    int days=0, month=0, year=0,d,m,y;
    time_t ts;
    struct tm *ct;
    do
    {
        system("cls");
        t();

        /*get current date.*/
        ts = time(NULL);
        ct = localtime(&ts);

        cout<<"\n\t\tCurrent Date: "<< ct->tm_year + 1900<<"/"<<ct->tm_mon + 1<<"/"<<ct->tm_mday<<endl;

        days = DaysInMon[month - 1] - days + 1;
        d=ct->tm_mday;
        m=ct->tm_mon + 1;
        y=ct->tm_year + 1900;

        fflush(stdin);
        cout<<"\n\n\t\tEnter your age(YY MM DD): ";
        cin>>year>>month>>days;


        /* calculating age in no of days, years and months */
        days = d-days;
        month = m - month;
        year =y - year;

        /* checking for leap year feb - 29 days */
        if (isLeapYear(year, month+1))
        {
            if (days >= (DaysInMon[m] + 1))
            {
                days = days - (DaysInMon[m] + 1);
                month = month + 1;
            }
        }
        else if (days >= DaysInMon[m])
        {
            days = days - (DaysInMon[m]);
            month = month + 1;
        }

        if (month >= 12)
        {
            year = year + 1;
            month = month - 12;
        }

        /* print age */
        cout<<"\n\n\t## Hey your birth date is: "<<year<<"/"<<month<<"/"<<days<<". ##\n"<<endl;
        getch();
        fflush(stdin);

        cout<<"\n\n\tDo you want to Calculate your age again? (y/n): ";
        cin>>f2;
    }
    while(f2=='y');
}
