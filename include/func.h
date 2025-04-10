#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <ctime>
#include "otherstruct.h"
#include <algorithm>
using namespace std;

bool compare(string s1, string s2) {
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    return s1 == s2;
}

Date getNow() {
    time_t now = time(0);
    tm* t = localtime(&now);
    int year = (t->tm_year + 1900);
    int month = (t->tm_mon + 1);
    int day = t->tm_mday;
    return Date(day, month, year);
}

string_view nhapMa() {
    string s;
    do {
        cout << "Nhap ma: ";
        cin >> s;
        if (s.size() != 5) {
            cout << "Ma can 5 ki tu\n";
        } 
    } while (s.size() != 5);
    return s;
}

#endif