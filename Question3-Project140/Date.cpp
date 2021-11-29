#include <iostream>
#include <string>
#include "Date.h"
using namespace std;
const array<unsigned int, 13> Date::days
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int month, int day, int year)
{
    setDate(month, day, year);
}

void Date::setDate(int mm, int dd, int yy)
{
    if (mm >= 1 && mm <= 12) {
        month = mm;
    }
    else
    {
        throw invalid_argument{ "Month must be 1-12" };
    }
    if (yy >= 1900 && yy <= 2100)
    {
        year = yy;
    }
    else
    {
        throw invalid_argument{ "Year must be >= 1900 and <= 2100" };
    }
    if ((mm == 2 && leapYear(year) && dd >= 1 && dd <= 29) || (dd >= 1 && dd <= days[mm]))
    {
        day = dd;
    }
    else
    {
        throw invalid_argument{ "Day is out of range for current month and year" };
    }
}
Date& Date::operator++()
{
    helpIncrement(); // increment date
    return *this; // reference return to create an lvalue
}
Date Date::operator++(int)
{
    Date temp{ *this }; // hold current state of object
    helpIncrement();
    // return unincremented, saved, temporary object
    return temp; // value return; not a reference return
}
Date& Date::operator+=(unsigned int additionalDays)
{
    for (unsigned int i = 0; i < additionalDays; ++i)
    {
        helpIncrement();
    }
    return *this; // enables cascading
}
Date& Date::operator--()
{
    helpDecrement(); // decrement date
    return *this; // reference return to create an lvalue
}
Date Date::operator--(int)
{
    Date temp{ *this }; // hold current state of object
    helpDecrement();
    // return undecremented, saved, temporary object
    return temp; // value return; not a reference return
}
Date& Date::operator-=(unsigned int additionalDays)
{
    for (unsigned int i = 0; i < additionalDays; ++i)
    {
        helpDecrement();
    }
    return *this; // enables cascading
}
bool Date::leapYear(int testYear) {
    return (testYear % 400 == 0 ||
        (testYear % 100 != 0 && testYear % 4 == 0));
}
bool Date::endOfMonth(int testDay) const
{
    if (month == 2 && leapYear(year))
    {
        return testDay == 29; // last day of Feb. in leap year
    }
    else
    {
        return testDay == days[month];
    }
}
bool Date::firstOfMonth(int testDay) const
{
    return testDay == 1;
}
void Date::helpIncrement()
{
    if (!endOfMonth(day))
    {
        ++day; // increment day
    }
    else
    {
        if (month < 12)
        { // day is end of month and month < 12
            ++month; // increment month
            day = 1; // first day of new month
        }
        else
        { // last day of year
            ++year; // increment year
            month = 1; // first month of new year
            day = 1; // first day of new month
        }
    }
}
void Date::helpDecrement()
{
    if (!firstOfMonth(day))
    {
        --day;// decrement day
    }
    else
    {
        if (month > 1)
        {
            --month; // decrement month
            day = days[month]; // last day of previous month
            if (leapYear(year) && month == 2)
                ++day;
        }
        else
        {
            --year; // decrement year
            month = 12; // last month of previous year
            day = days[month]; // last day of new month
        }
    }
}
bool Date::operator>(const Date& g) const
{
    return (year > g.year) ||
        (year > g.year && month > g.month) ||
        (year > g.year && month > g.month && day > g.day) ? true : false;
}

bool Date::operator <(const Date& g) const
{
    return (year < g.year) ||
        (year < g.year&& month < g.month) ||
        (year < g.year&& month < g.month&& day < g.day) ? true : false;
}
ostream& operator<<(ostream& output, const Date& d)
{
    static string monthName[13]{ "", "January", "February",
        "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December" };
    output << monthName[d.month] << ' ' << d.day << ", " << d.year;
    return output;
}
bool Date::operator==(const Date& g) const
{
    return day == g.day && month == g.month && year == g.year;
}
int Date::getMonth() const
{
    return month;
}
int Date::getDay() const
{
    return day;
}
int Date::getYear() const
{
    return year;
}
void Date::setYear(int yr)
{
    year = yr;
}