#include "Date.h"
#include <iostream>
using namespace std;

int main() {
    // Test 1: default constructor
    Date d1;
    cout << "Default date: " << d1 << endl;

    // Test 2: parameterized constructor
    Date d2(18,4,2018);
    cout << "Parameterized date: " << d2 << endl;

    // Test 3: setDate valid
    d2.setDate(1,1,2020);
    cout << "After setDate: " << d2 << endl;

    // Test 4: invalid dates
    d2.setDate(13,45,2018);
    d2.setDate(4,31,2000);
    d2.setDate(2,29,2009);

    // Test 5: subtraction
    Date d3(10,4,2014);
    Date d4(18,4,2014);
    cout << "Days between: " << (d4 - d3) << endl;

    // Test 6: increment/decrement operators
    Date d5(29,2,2008);
    ++d5;
    cout << "After pre-increment: " << d5 << endl;
    --d5;
    cout << "After pre-decrement: " << d5 << endl;
    d5++;
    cout << "After post-increment: " << d5 << endl;
    d5--;
    cout << "After post-decrement: " << d5 << endl;

    // Test 7: year rollover
    Date d6(31,12,2024);
    d6++;
    cout << "After 12/31/2024 increment: " << d6 << endl;
    d6--;
    cout << "After decrement: " << d6 << endl;

    // Test 8: cin input
    Date d7;
    cin >> d7;
    cout << "You entered: " << d7 << endl;

    return 0;
}
