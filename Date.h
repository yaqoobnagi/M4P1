#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
private:
    int day, month, year;
    static const std::string monthNames[12];

    bool isLeapYear(int y) const;
    int daysInMonth(int m, int y) const;
    bool validDate(int d, int m, int y) const;

public:
    Date(); // default constructor
    Date(int d, int m, int y); // parameterized constructor

    bool setDate(int d, int m, int y);

    // Prefix and postfix increment/decrement
    Date& operator++();   // prefix
    Date operator++(int); // postfix
    Date& operator--();   // prefix
    Date operator--(int); // postfix

    int operator-(const Date& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Date& dt);
    friend std::istream& operator>>(std::istream& is, Date& dt);
};

#endif
