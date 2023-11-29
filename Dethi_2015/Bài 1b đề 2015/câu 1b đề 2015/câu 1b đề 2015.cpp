
#include <iostream>
class A {
public:
    A() { a = new int[3]; for (int i = 0; i < 3; i++) a[i] = i + 1; }
    ~A() { delete[] a; }
private:
    int* a;
};

void init(A*& a) {
    A* b = new A();
    a = b;
}

int main() {
    A* obj;
    init(obj);
    // Sử dụng obj ở đây
    delete obj; // Đừng quên giải phóng bộ nhớ khi không cần thiết nữa
    return 0;
}

