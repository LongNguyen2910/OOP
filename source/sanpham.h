#ifndef SANPHAM_H
#define SANPHAM_H
#include "../include/otherstruct.h"
#include "interface.h"
#include <map>
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
            ma = "SP000";
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
        void getMa(string_view m) { ma = m; }
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
        Date getHsd() {return hsd;}
        void setHsd(Date d) {hsd = d;}

        void luu(string) override;
        void nhap() override;
        void hienThi() override;
        void kiemTraThoiHan() override;
        void nhapFile(string) override;
};

#endif