// Tập tin PhanSo.h
#ifndef _PhanSo_h
#define _PhanSo_h
#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu, mau;
public:
    PhanSo(); // Hàm tạo mặc định
    PhanSo(int x, int y); // Hàm tạo với các tham số
    PhanSo operator+(const PhanSo& other); // Phép cộng hai phân số
    PhanSo operator+(int value); // Phép cộng một phân số với một số nguyên
    PhanSo& operator++(); // Phép tăng giá trị phân số lên 1 đơn vị
    PhanSo& operator+=(const PhanSo& other); // Phép cộng phân số với một phân số khác và gán giá trị
    friend ostream& operator<<(ostream& os, const PhanSo& ps); // Toán tử xuất
};

#e