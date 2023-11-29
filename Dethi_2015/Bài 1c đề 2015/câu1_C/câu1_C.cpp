#include <iostream>

class Singleton {
private:
    static Singleton* instance;

    // Các thành phần dữ liệu và phương thức khác của lớp

    Singleton() {
        // Khởi tạo các thành phần dữ liệu
    }

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    // Các phương thức khác của lớp
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();

    if (instance1 == instance2) {
        std::cout << "Two instances are the same.\n";
    }
    else {
        std::cout << "Two instances are different.\n";
    }

    return 0;
}