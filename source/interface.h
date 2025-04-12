#ifndef INTERFACE_H
#define INTERFACE_H

template <class T>
struct ListInterface {
    virtual void load() = 0;
    virtual void luu(string) = 0;
    virtual void them() = 0;
    virtual void hienThi() = 0;
    virtual void xoa() = 0;
    virtual void sua() = 0;
    virtual void xuatFile(string) = 0;
    virtual void sapXep() = 0;
    virtual T* timKiem(string) = 0;
    virtual T* timKiem() = 0;
};

struct ObjectInterface {
    virtual void luu(ofstream&) = 0;
    virtual void nhap() = 0;
    virtual void hienThi() = 0;
    virtual bool kiemTraThoiHan() = 0;
    virtual void nhapFile(ifstream&) = 0;
    virtual void xuatFile(ofstream&) = 0;
};

#endif