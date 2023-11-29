#include <iostream>

using namespace std;

class ComplexNumber {
private:
    int a; // Phần thực
    int b; // Phần ảo (hệ số của căn bậc nhất)

public:
    // Constructor
    ComplexNumber(int _a = 0, int _b = 0) {
        a = _a;
        b = _b;
    }

    // Phương thức nhập số phức
    void input() {
        cout << "Nhập phần thực a: ";
        cin >> a;
        cout << "Nhập phần ảo b: ";
        cin >> b;
    }

    // Phương thức xuất số phức
    void display() {
        cout << a << " + " << b << "√7" << endl;
    }

    // Phương thức cộng hai số phức
    ComplexNumber operator+(ComplexNumber other) {
        int realPart = a + other.a;
        int imaginaryPart = b + other.b;
        return ComplexNumber(realPart, imaginaryPart);
    }

    // Phương thức trừ hai số phức
    ComplexNumber operator-(ComplexNumber other) {
        int realPart = a - other.a;
        int imaginaryPart = b - other.b;
        return ComplexNumber(realPart, imaginaryPart);
    }

    // Phương thức đổi dấu số phức
    ComplexNumber operator-() {
        return ComplexNumber(-a, -b);
    }

    // Phương thức nhân hai số phức
    ComplexNumber operator*(ComplexNumber other) {
        int realPart = (a * other.a) + (7 * b * other.b);
        int imaginaryPart = (a * other.b) + (b * other.a);
        return ComplexNumber(realPart, imaginaryPart);
    }
};