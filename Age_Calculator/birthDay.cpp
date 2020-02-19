#include <iostream>
#include <ctime>
using namespace std;

int main() {

    /**********************************/

    //enter date of your birth
    //dd mm yyyy
    //bugs: some dates may be inaccurate because it's not based on your birth date just everything converts to days and calculate from that
    //version 2.2

    /**********************************/

    time_t t = time(0);
    struct tm * now = localtime(&t);

    int years = (now->tm_year) + 1900;

    int n1 = 0, n2 = 0, n3 = 0;
    cin >> n1 >> n2 >> n3;
    if(n3 > years)
    {
        cout << "are you from the futute?" << endl;
    }
    if(n1 > 31)
    {
        cout << "lol really? " << n1 << " days?" << endl;
     }
    if(n2 > 12)
    {
        cout << "more than 12 months?" << endl;
    }
    else
    {
    int year1, months1, days1; //converts everything to days
    year1 = (years - n3) * 365;
    months1 = n2 * 30;
    days1 = n1;

    const int all = year1 + months1 + days1;

    unsigned long long int outY,outM,outD,outW,outH,outMi,outS;
    outY = all / 365;
    outM = all / 30;
    outD = all;
    outW = all / 7;
    outH = all * 24;
    outMi = all * 1440;
    outS = all * 86400;
    if(n1 > 0 && n2 > 0 && n3 > 0) {
    cout << outY << " years" << endl
         << outM << " months" << endl
         << outD << " days" << endl
         << outW << " weeks" << endl
         << outH << " hours" << endl
         << outMi << " minutes" << endl
         << outS << " seconds" << endl;
    }
    else
    {
        cout << "write date of your birth" << endl << "in format:" << endl << "dd mm yyyy" << endl;
        }
    }
    return 0;
}
