#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber {
private:
    int a; // Phần thực
    int b; // Phần ảo (hệ số của căn bậc nhất √7)

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

    // Phép cộng hai số phức
    ComplexNumber operator+(ComplexNumber other) {
        int realPart = a + other.a;
        int imaginaryPart = b + other.b;
        return ComplexNumber(realPart, imaginaryPart);
    }

    // Phép trừ hai số phức
    ComplexNumber operator-(ComplexNumber other) {
        int realPart = a - other.a;
        int imaginaryPart = b - other.b;
        return ComplexNumber(realPart, imaginaryPart);
    }

    // Phép đổi dấu số phức
    ComplexNumber operator-() {
        return ComplexNumber(-a, -b);
    }

    // Phép nhân hai số phức
    ComplexNumber operator*(ComplexNumber other) {
        int realPart = (a * other.a) + (7 * b * other.b);
        int imaginaryPart = (a * other.b) + (b * other.a);
        return ComplexNumber(realPart, imaginaryPart);
    }
};

int main() {
    ComplexNumber number1, number2;

    cout << "Nhập số phức thứ nhất:\n";
    number1.input();

    cout << "Nhập số phức thứ hai:\n";
    number2.input();

    cout << "Số phức thứ nhCâu b) Tiếp tục từ phần mã mẫu:

        ```cpp
        cout << "Số phức thứ nhất: ";
    number1.display();

    cout << "Số phức thứ hai: ";
    number2.display();

    // Tính tổng hai số phức
    ComplexNumber sum = number1 + number2;
    cout << "Tổng: ";
    sum.display();

    // Tính hiệu hai số phức
    ComplexNumber difference = number1 - number2;
    cout << "Hiệu: ";
    difference.display();

    // Đảo dấu số phức thứ nhất
    ComplexNumber negation = -number1;
    cout << "Đảo dấu số phức thứ nhất: ";
    negation.display();

    // Tính tích hai số phức
    ComplexNumber product = number1 * number2;
    cout << "Tích: ";
    product.display();

    return 0;
}