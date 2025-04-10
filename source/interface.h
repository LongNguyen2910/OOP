#ifndef INTERFACE_H
#define INTERFACE_H

template <typename T>
struct ListInterface {
    virtual void load() = 0;
    virtual void them() = 0;
    virtual void hienThi() = 0;
    virtual void xoa() = 0;
    virtual void sua() = 0;
    virtual T* timKiemMa() = 0; 
};

struct ObjectInterface {
    virtual void luu(string) = 0;
    virtual void nhap() = 0;
    virtual void hienThi() = 0;
    virtual void kiemTraThoiHan() = 0;
    virtual void nhapFile(string) = 0;
};

#endif