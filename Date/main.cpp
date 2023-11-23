#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

public:
    Date() : day(1), month(1), year(2000) {}

    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void incrementDay() {
        day++;
    }

    Date operator++() {
        incrementDay();
        return *this;
    }

    Date operator++(int) {
        Date temp = *this;
        incrementDay();
        return temp;
    }

    bool operator!=(const Date& other) const {
        return (day != other.day || month != other.month || year != other.year);
    }

    bool operator==(const Date& other) const {
        return (day == other.day && month == other.month && year == other.year);
    }

    bool operator<(const Date& other) const {
        if (year < other.year)
            return true;
        else if (year == other.year && month < other.month)
            return true;
        else if (year == other.year && month == other.month && day < other.day)
            return true;
        else
            return false;
    }

    bool operator>(const Date& other) const {
        return !(*this < other || *this == other);
    }

    friend ostream& operator<<(ostream& os, const Date& date);

    friend istream& operator>>(istream& is, Date& date);
};

ostream& operator<<(ostream& os, const Date& date) {
    os << date.day << '/' << date.month << '/' << date.year;
    return os;
}

istream& operator>>(istream& is, Date& date) {
    is >> date.day >> date.month >> date.year;
    return is;
}

int main() {
    Date myDate(1, 1, 2023);

    cout << "Original Date: " << myDate << endl;

    ++myDate;
    cout << "Date after incrementing: " << myDate << endl;

    Date anotherDate(3, 1, 2023);
    if (myDate == anotherDate)
        cout << "Dates are equal" << endl;
    else
        cout << "Dates are not equal" << endl;

    if (myDate != anotherDate)
        cout << "Dates are not equal" << endl;
    else
        cout << "Dates are equal" << endl;

    if (myDate < anotherDate)
        cout << "myDate is earlier than anotherDate" << endl;
    else
        cout << "myDate is not earlier than anotherDate" << endl;

    if (myDate > anotherDate)
        cout << "myDate is later than anotherDate" << endl;
    else
        cout << "myDate is not later than anotherDate" << endl;

    return 0;
}
