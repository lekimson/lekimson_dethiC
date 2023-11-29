#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Constructor of Base" << std::endl;
    }

    // Hàm hủy ảo
    virtual ~Base() {
        std::cout << "Destructor of Base" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Constructor of Derived" << std::endl;
    }

    // Hàm hủy không ảo
    ~Derived() {
        std::cout << "Destructor of Derived" << std::endl;
    }
};

int main() {
    // Tạo một con trỏ cơ sở trỏ tới một đối tượng dẫn xuất
    Base* basePtr = new Derived();

    // Xóa đối tượng thông qua con trỏ cơ sở
    delete basePtr;

    return 0;
}