#include "hopdong.h"
#include <iostream>
using namespace std;

int main() {
    HopDong x;
    x.nhapFile("../data/hopdong.txt");
    x.hienThi();
    return 0;
}