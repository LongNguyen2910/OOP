#ifndef OTHERSTRUCT_H
#define OTHERSTRUCT_H
#include "validate.h"
#include "func.h"
#include <iostream>
using namespace std;

class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date(): Date(1,1,2025) {}
        Date(int d, int m, int y) {
            if (checkDate(d, m, y)) {
                day = d;
                month = m;
                year = y;
            } else {
                cout << "Constructor date loi\n";
            }
        }
        Date& operator=(Date other) {
            if(*this != other) {
                day = other.day;
                month = other.month;
                year = other.year;
            }
            return *this;
        }
        bool operator!=(Date& other) {
            return day != other.day || month != other.month || year != other.year;
        }
        bool operator==(Date& other) {
            return day == other.day && month == other.month && year == other.year;
        }
        friend ostream& operator<< (ostream& out, const Date& date) {
            out << (date.day<10?'0':'\0') << date.day << "/"
                << (date.month<10?'0':'\0') << date.month << "/" << date.year << "\n";
            return out;
        }
        friend istream& operator>> (istream& in, Date& date) {
            do {
                cout << "nhap ngay: ";
                in >> date.day;
                cout << "nhap thang: ";
                cin >> date.month;
                cout << "nhap nam: ";
                cin >> date.year;
                if (!checkDate(date.day, date.month, date.year)) {
                    cout << "Date khong hop le\n";
                }
            } while (!checkDate(date.day, date.month, date.year));
            return in;
        }
        void setDay(int d) {
            if (checkDate(d))
                day = d;
            else 
                cout << "set day loi\n";
        }
        void setMonth(int m) {
            if (checkDate(1, m)) 
                month = m;
            else 
                cout << "set month loi\n";
        }
        void parseString(string_view s) {
            day = (s[0] - '0') * 10 + (s[1] - '0');
            month = (s[2] - '0') * 10 + (s[3] - '0');
            year = (s[4] - '0') * 1000 + (s[5] - '0') * 100 
                    + (s[6] - '0') * 10 + (s[7] - '0');
        }
        void setYear(int y) {
            if (checkDate(1, 1, y))
                year = y;
            else 
                cout << "set year loi\n";
        }
        bool operator>=(Date& another) {
            if (year > another.year) {
                return 1;
            } else if (year == another.year) {
                if (month > another.month) {
                    return 1;
                } else if (month == another.month) {
                    if (day >= another.day)
                        return 1;
                } else 
                    return 0;
            }
            return 0;
        }
        bool operator>(Date& another) {
            if (year > another.year) {
                return 1;
            } else if (year == another.year) {
                if (month > another.month) {
                    return 1;
                } else if (month == another.month) {
                    if (day > another.day)
                        return 1;
                } else 
                    return 0;
            }
            return 0;
        }
        bool lNow() {
            int x, y, z;
            getNow(x, y, z);
            Date now(x, y, z);
            return (now > *this); 
        }
        bool gNow() {
            int x, y, z;
            getNow(x, y, z);
            Date now(x, y, z);
            return (*this > now);
        }
        int getDay() {return day;}
        int getMonth() {return month;}
        int getYear() {return year;}
};

#endif