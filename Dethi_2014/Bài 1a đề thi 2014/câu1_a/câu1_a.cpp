#include <iostream>
#include <cstring>

class Bike {
private:
    char* brand; // hiệu xe

public:
    Bike(const char* brandName) {
        int length = std::strlen(brandName) + 1;
        brand = new char[length];
        std::strcpy(brand, brandName);
    }

    virtual ~Bike() {
        delete[] brand;
    }

    Bike(const Bike& other) {
        int length = std::strlen(other.brand) + 1;
        brand = new char[length];
        std::strcpy(brand, other.brand);
    }

    Bike& operator=(const Bike& other) {
        if (this != &other) {
            delete[] brand;
            int length = std::strlen(other.brand) + 1;
            brand = new char[length];
            std::strcpy(brand, other.brand);
        }
        return *this;
    }

    virtual void move(int t1) {
        std::cout << brand << ":" << t1 * 12 << " ";
    }
};