#include "Date.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

const string Date::monthNames[12] = { "January","February","March","April","May","June",
                                      "July","August","September","October","November","December" };

// Helper functions
bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int m, int y) const {
    switch(m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return  31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(y) ? 29 : 28;
        default: return 0;
    }
}

bool Date::validDate(int d, int m, int y) const {
    return (y >= 1 && m >= 1 && m <= 12 && d >= 1 && d <= daysInMonth(m,y));
}

// Constructors
Date::Date() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    day = now->tm_mday;
    month = now->tm_mon + 1;
    year = now->tm_year + 1900;
}

Date::Date(int d, int m, int y) {
    if (!setDate(d,m,y)) {
        day = 1; month = 1; year = 2000;
    }
}

bool Date::setDate(int d, int m, int y) {
    if(validDate(d,m,y)) {
        day = d; month = m; year = y;
        return true;
    }
    cout << "Invalid date: " << d << "/" << m << "/" << y << endl;
    return false;
}

// Increment / Decrement
Date& Date::operator++() { // prefix
    day++;
    if(day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if(month > 12) { month = 1; year++; }
    }
    return *this;
}

Date Date::operator++(int) { // postfix
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator--() { // prefix
    day--;
    if(day < 1) {
        month--;
        if(month < 1) { month = 12; year--; }
        day = daysInMonth(month, year);
    }
    return *this;
}

Date Date::operator--(int) { // postfix
    Date temp = *this;
    --(*this);
    return temp;
}

// Subtraction
int Date::operator-(const Date& other) const {
    tm a = {}, b = {};
    a.tm_mday = day; a.tm_mon = month-1; a.tm_year = year-1900;
    b.tm_mday = other.day; b.tm_mon = other.month-1; b.tm_year = other.year-1900;
    time_t t1 = mktime(&a);
    time_t t2 = mktime(&b);
    double diff = difftime(t1,t2)/ (60*60*24);
    return static_cast<int>(diff >=0 ? diff : -diff);
}

// Stream operators
ostream& operator<<(ostream& os, const Date& dt) {
    os << Date::monthNames[dt.month-1] << " " << dt.day << ", " << dt.year;
    return os;
}

istream& operator>>(istream& is, Date& dt) {
    int d,m,y;
    cout << "Enter date (dd mm yyyy): ";
    is >> d >> m >> y;
    while(!dt.setDate(d,m,y)) {
        cout << "Enter date (dd mm yyyy): ";
        is >> d >> m >> y;
    }
    return is;
}
