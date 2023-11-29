#include <iostream>
#include <string>
#include <algorithm>

class BigInteger {
private:
    std::string value;

public:
    BigInteger(const std::string& str = "") : value(str) {}

    friend std::istream& operator>>(std::istream& is, BigInteger& num) {
        is >> num.value;
        num.removeLeadingZeros();
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const BigInteger& num) {
        os << num.value;
        return os;
    }

    bool operator==(const BigInteger& other) const {
        return value == other.value;
    }

    void removeLeadingZeros() {
        value.erase(0, value.find_first_not_of('0'));
        if (value.empty()) {
            value = "0";
        }
    }
};

int main() {
    BigInteger n1(" 1234567891011 ");
    BigInteger n2;

    std::cout << "Input an integer = ";
    std::cin >> n2;

    if (n1 == n2)
        std::cout << "Equal.\n";
    else
        std::cout << "Not equal.\n";

    return 0;
}