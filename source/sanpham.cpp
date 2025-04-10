#include "sanpham.h"
#include <iostream>
#include <fstream>
using namespace std;

void SanPham::nhap() {
    do {
        cout << "Nhap loai hang(1-6): \n";
        for (auto x : loai) {
            cout <<x.first << ". "<< x.second << "\n";
        }
        cin >> loaiHang;
        cin.ignore(100, '\n');
        cout << "Nhap ten: ";
        getline(cin, ten);
        cout << "Nhap xuat xu: ";
        getline(cin, xuatXu);
        cout << "Nhap ngay SX\n";
        cin >> ngaySX;
        cout << "Nhap hsd\n";
        cin >> hsd;
    } while (!inRange(loaiHang, 1, 6) && !ten.empty() && !xuatXu.empty());
}

void SanPham::nhapFile(string file) {
    ifstream inf{file};
    if (!inf) {
        cerr << "Loi mo file\n";
        return;
    }
    string s;
    getline(inf, ma);
    getline(inf, ten);
    getline(inf, s);
    loaiHang = s[0] - '0';
    getline(inf, xuatXu);
    inf >> s;
    ngaySX.parseString(s);
    inf >> s;
    hsd.parseString(s);
}

void SanPham::luu(string file = "../data/sanpham.txt") {
    ofstream outf{file, ios::app};
    if (!outf) {
        cerr << "Loi luu data\n";
        return;
    }
    outf << ma << endl;
    outf << ten << endl;
    outf << loaiHang << endl;
    outf << xuatXu << endl;
    outf << ngaySX.getDay() << ngaySX.getMonth() << ngaySX.getYear() << endl;
    outf << hsd.getDay() << hsd.getMonth() << hsd.getYear() << endl;
}

void SanPham::hienThi() {
    cout << "Ma: " << ma << "\n";
    cout << "Ten: " << ten << "\n";
    cout << "Loai hang: " << loai.at(loaiHang) << "\n";
    cout << "Xuat xu: " << xuatXu << "\n";
    cout << "Ngay san xuat\n";
    cout << ngaySX;
    cout << "Han su dung\n";
    cout << hsd;
}

void SanPham::kiemTraThoiHan() {
    return;
}

int main() {
    return 0;
}