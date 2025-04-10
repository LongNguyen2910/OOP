#ifndef INTERFACE_H
#define INTERFACE_H

template <class T>
struct ListInterface {
    virtual void load() = 0;
    virtual void luu() = 0;
    virtual void them() = 0;
    virtual void hienThi() = 0;
    virtual void xoa() = 0;
    virtual void sua() = 0;
    virtual void sapXep() = 0;
    virtual T* timKiem(string_view ten) = 0;
    virtual T* timKiem();
};

template <class T>
struct ObjectInterface {
    virtual void luu(string) = 0;
    virtual void nhap() = 0;
    virtual void hienThi() = 0;
    virtual bool kiemTraThoiHan() = 0;
    virtual void nhapFile(T) = 0;
};

#endif