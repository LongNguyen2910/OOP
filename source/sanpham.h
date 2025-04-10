#ifndef SANPHAM_H
#define SANPHAM_H
#include "../include/otherstruct.h"
#include "interface.h"
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

const map<int, string> loai { {1, "Thuc Pham Tuoi Song"}, {2, "Thuc Pham Che Bien"}, {3, "Do Uong"}, {4, "Hoa Pham"}, 
                                {5, "Trung - Sua"}, {6, "Do Gia Dung"}};

class SanPham : public ObjectInterface {
    private:
        string ma;
        string ten;
        string xuatXu;
        Date ngaySX;
        Date hsd;
        int loaiHang;
    public:
        SanPham() {
            ten = "Unknown";
            ma = "SPCT000";
            xuatXu = "Unknown";
            hsd = Date();
            loaiHang = 1;
        }
        SanPham(string_view t, string_view xx, Date d, int lh) {
            if (!t.empty() && !xx.empty() && inRange(lh, 1, 6)) {
                ten = t;
                xuatXu = xx;
                hsd = d;
                loaiHang = lh;
            } else {
                cout << "Constructor san pham loi\n";
            }
        }
        SanPham& operator=(SanPham another) {
            ma = another.ma;
            ten = another.ten;
            xuatXu = another.xuatXu;
            hsd = another.hsd;
            loaiHang = another.loaiHang;
            return *this;
        }
        string getTen() {return ten;}
        void setTen(string_view name) {
            if (!name.empty()) ten = name;
            else {
                cout << "set ten loi\n";
            }
        }
        void setMa(string_view m) { ma = m; }
        string getMa() {return ma;}
        int getLoaiHang() {return loaiHang;}
        void setLoaiHang(int loai) {
            if (inRange(loai, 1, 6)) {
                loaiHang = loai;
            } else {
                cout << "set loai hang loi\n";
            }
        }
        string getXuatXu() { return xuatXu; }
        void setXuatXu(string_view x) {
            if (!x.empty()){
                xuatXu = x;
            } else {
                cout << "set xuat xu loi\n";
            }
        }
        Date getNgaySX() {return ngaySX;}
        void setNgaySX(Date n) {
            if (!n.gNow()) {
                ngaySX = n;
            } else {
                cout << "set ngay san xuat loi\n";
            }
        }
        Date getHsd() {return hsd;}
        void setHsd(Date d) {
            if (d >= ngaySX) {
                hsd = d;
            } else {
                cout << "set hsd loi\n";
            }
        }
        void luu(string) override;
        void nhap() override;
        void hienThi() override;
        bool kiemTraThoiHan() override;
        void nhapFile(string) override;
};

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
        if (!inRange(loaiHang, 1, 6) || ten.empty() || xuatXu.empty() || ngaySX.gNow() || (ngaySX > hsd)) {
            cout << "nhap loi\n";
        }
    } while (!inRange(loaiHang, 1, 6) || ten.empty() || xuatXu.empty() || ngaySX.gNow() || (ngaySX > hsd));
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

bool SanPham::kiemTraThoiHan() {
    int day, month, year;
    getNow(day, month, year);
    Date now(day, month, year);
    if (hsd >= now) {
        return 1;
    } else return 0;
}


#endif