#ifndef DANHSACHHOPDONG_H
#define DANHSACHHOPDONG_H
#include "hopdong.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class DanhSachHopDong : public ListInterface<HopDong> {
    private:
        vector<HopDong> dsHopDong;
    public:
        DanhSachHopDong() {
            dsHopDong = vector<HopDong>();
        }
        DanhSachHopDong(vector<HopDong>& ds) {
            dsHopDong = ds;
        }
        vector<HopDong>& getDS() {
            return dsHopDong;
        }
        void load() override;
        void luu(string) override;
        void them() override;
        void hienThi() override;
        void xoa() override;
        void sua() override;
        void sapXep() override;
        void xuatFile(string) override;
        HopDong* timKiem(string) override;
        HopDong* timKiem() override;
};

void DanhSachHopDong::them() {
    cout << "Nhap thong tin hop dong\n";
    cout << "Nhap so hop dong muon them: ";
    int n;
    cin >> n;
    cin.ignore(100, '\n');
    for (int i = 0; i < n; i++) {
        HopDong x;
        x.nhap();
        dsHopDong.push_back(x);
    }
}

void DanhSachHopDong::hienThi() {
    cout << "Danh sach hop dong:\n";
    for (auto& i : dsHopDong) {
        i.hienThi();
    }
}

void DanhSachHopDong::sapXep() {
    int n = 0;
    do {
        DanhSachHopDong ds = dsHopDong;
        cout << "Sap xep hop dong\n";
        cout << "1. Sap xep theo ngay ky hop dong\n";
        cout << "2. Sap xep theo ngay ky hop dong giam dan\n";
        cout << "3. Sap xep theo ngay het han\n";
        cout << "4. Sap xep theo ngay het han giam dan\n";
        cout << "5. exit\n";
        cout << "Nhap lua chon: ";
        cin >> n;
        switch (n) {
            case 1:
                sort(ds.getDS().begin(), ds.getDS().end(), [](HopDong& a, HopDong& b) {
                    return b.getNgayKy() > a.getNgayKy();
                });
                break;
            case 2:
                sort(ds.getDS().begin(), ds.getDS().end(), [](HopDong& a, HopDong& b) {
                    return a.getNgayKy() > b.getNgayKy();
                });
                break;
            case 3:
                sort(ds.getDS().begin(), ds.getDS().end(), [](HopDong& a, HopDong& b) {
                    return b.getNgayHetHan() > a.getNgayHetHan();
                });
                break;
            case 4:
                sort(ds.getDS().begin(), ds.getDS().end(), [](HopDong& a, HopDong& b) {
                    return a.getNgayHetHan() > b.getNgayHetHan();
                });
                break;
            case 5:
                cout << "exit\n";
                return;
                break;
            default:
                cout << "Lua chon khong hop le\n";
        }
        cout << "1. Hien thi\n";
        cout << "2. Xuat file\n";
        cout << "3. exit\n";
        cout << "Nhap lua chon: ";
        int m;
        cin >> m;   
        switch (m) {
            case 1:
                cout << "Danh sach hop dong sau khi sap xep:\n";
                for (auto& i : ds.getDS()) {
                    i.hienThi();
                }
                break;
            case 2:
                cout << "Nhap ten file muon luu: ";
                {
                    string file;
                    cin >> file;
                    ds.xuatFile(file);
                }
                break;
            case 3:
                break;
            default:
                cout << "Lua chon khong hop le\n";
        }

    } while (n < 5);
}

void DanhSachHopDong::luu(string s = "../data/hopdong.txt") {
    ofstream outf(s, ios::app);
    if (!outf) {
        cerr << "Loi mo file\n";
        return;
    }
    outf << dsHopDong.size() << endl;
    for (auto& i : dsHopDong) {
        i.luu(s);
    }
}

void DanhSachHopDong::xuatFile(string file) {
    string s = "../out/";
    file = s + file;
    luu(file);
}

void DanhSachHopDong::load() {
    ifstream inf("../data/hopdong.txt");
    if (!inf) {
        cerr << "Loi mo file\n";
        return;
    }
    string s;
    getline(inf, s);
    int n = stoi(s);
    while (n--) {
        HopDong x;
        x.nhapFile(inf);
        dsHopDong.push_back(x);
    }
    inf.close();
}

HopDong* DanhSachHopDong::timKiem(string ma) {
    for (auto& i : dsHopDong) {
        if (compare(i.getMa(), ma)) {
            return &i;
        }
    }
    cout << "Khong tim thay hop dong\n";
    return nullptr;
}

HopDong* DanhSachHopDong::timKiem() {
    cout << "Nhap ten nha cung cap muon tim kiem: ";
    string ten;
    cin.ignore(100, '\n');
    getline(cin, ten);
    for (auto& i : dsHopDong) {
        if (compare(i.getTen(), ten)) {
            return &i;
        }
    }
    cout << "Khong tim thay hop dong\n";
    return nullptr;
}

void DanhSachHopDong::sua() {
    cout << "Nhap ma hop dong muon sua: ";
    string ma;
    cin >> ma;
    cin.ignore(100, '\n');
    HopDong* x = timKiem(ma);
    HopDong tmp;
    if (x != nullptr) {
        cout << "Nhap thong tin hop dong muon sua\n";
        tmp.nhap();
    }
    *x = tmp;
    x->hienThi();
    string filePath = "../data/hopdong.txt";
    ofstream outFile(filePath, ios::trunc); 
    if (!outFile) {
        cerr << "Khong the mo file: " << filePath << endl;
        return;
    }
    luu(filePath);
}

void DanhSachHopDong::xoa() {
    cout << "Nhap ma hop dong muon xoa: ";
    string ma;
    cin >> ma;
    cin.ignore(100, '\n');
    HopDong* x = timKiem(ma);
    if (x != nullptr)
        dsHopDong.erase(find_if(dsHopDong.begin(), dsHopDong.end(), [=](HopDong a) {
            return a.getMa() == ma;
        }));
    string filePath = "../data/hopdong.txt";
    ofstream outFile(filePath, ios::trunc); 
    if (!outFile) {
        cerr << "Khong the mo file: " << filePath << endl;
        return;
    }
    luu(filePath);
}



#endif