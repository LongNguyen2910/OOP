#ifndef NHACUNGCAP_H
#define NHACUNGCAP_H
#include "sanpham.h"
#include <iostream>
#include <vector>
using namespace std;

class NhaCungCap : public ObjectInterface {
    private:
        string maNhaCungCap;
        string tenNhaCungCap;
        string thongTinLienHe;
        vector<SanPham> sanPhamCungCap;
    public:
        NhaCungCap(): tenNhaCungCap {"Unknown"}, thongTinLienHe {"Unknown"} {};
        NhaCungCap(string s1, string s2, string s3, vector<SanPham>& v) {
            maNhaCungCap = s1;
            tenNhaCungCap = s2;
            thongTinLienHe = s3;
            sanPhamCungCap = v;
        }
        void setTen(string_view s) {
            if (!s.empty()) {
                tenNhaCungCap = s;
            } else {
                cout << "set ten loi!\n";
            }
        }
        void setThongTin(string_view s) {
            if (!s.empty()) {
                thongTinLienHe = s;
            } else {
                cout << "set thong tin loi!\n";
            }
        }
        string getMa() { return maNhaCungCap; }
        void setMa(string_view m) { maNhaCungCap = m; }
        string getTen() {
            return tenNhaCungCap;
        }
        string getThongTin() {
            return thongTinLienHe;
        }
        vector<SanPham>& getSanPham() {
            return sanPhamCungCap;
        }
        NhaCungCap& operator=(NhaCungCap& other) {
            tenNhaCungCap = other.tenNhaCungCap;
            thongTinLienHe = other.thongTinLienHe;
            sanPhamCungCap = other.sanPhamCungCap;
            return *this;
        }
        // bool operator==(NhaCungCap& another) {
            
        // }

        void luu(string) override;
        void nhap() override;
        void hienThi() override;
        bool kiemTraThoiHan() override;
        void nhapFile(string) override;
};

#endif