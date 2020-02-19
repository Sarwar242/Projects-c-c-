#include <ctime>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

using namespace std;

const std::string currentTime()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%H:%M:%S %P", &tstruct);
    return buf;
}

const std::string currentDate()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%B %A ", &tstruct);
    return buf;
}

int main()
{
std:
    cout << "The current time is " << currentTime() << std::endl;
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    cout << "The current date is " << now->tm_mon + 1 << '-'
         << (now->tm_mday  + 1) << '-'
         <<  (now->tm_year + 1900)
         << " " << currentDate() << endl;

    cout << "Day of month is " << (now->tm_mday)
         << " and the Month of year is " << (now->tm_mon)+1 << "," << endl;
    cout << "also the day of year is " << (now->tm_yday)
         << " & our Weekday is " << (now->tm_wday) << "." << endl;
    cout << "The current year is " << (now->tm_year)+1900 << "."
         << endl;
    return 0;
}
