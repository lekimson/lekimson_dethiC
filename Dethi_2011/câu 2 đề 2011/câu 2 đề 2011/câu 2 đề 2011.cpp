#include <iostream>
using namespace std;

class MayXucTac {
private:
    static const int DON_GIA_THUE = 80000; // Đơn giá thuê máy (đồng/h)
    static const int DON_GIA_HOA_CHAT = 10000; // Đơn giá hóa chất (đồng/g)

    double congSuat; // Công suất lọc (m3/h)
    double luongHoaChat; // Lượng hóa chất (g)
    double thoiGianSuDung; // Thời gian sử dụng (h)

public:
    void nhap() {
        cout << "Nhap thong tin su dung may xuc tac:" << endl;
        cout << "Cong suat loc (m3/h): ";
        cin >> congSuat;
        cout << "Luong hoa chat (g): ";
        cin >> luongHoaChat;
        cout << "Thoi gian su dung (h): ";
        cin >> thoiGianSuDung;
    }

    double tinhLuongNuoc() {
        double congSuatThucTe;
        if (thoiGianSuDung < 10) {
            congSuatThucTe = congSuat;
        }
        else {
            congSuatThucTe = congSuat * thoiGianSuDung / 10;
        }

        return congSuatThucTe * thoiGianSuDung;
    }

    double tinhChiPhi() {
        double chiPhiThue = DON_GIA_THUE * thoiGianSuDung;
        double chiPhiHoaChat = DON_GIA_HOA_CHAT * luongHoaChat / 100;
        double chiPhiSuDung = chiPhiThue + chiPhiHoaChat;

        return chiPhiSuDung;
    }
};

int main() {
    cout << "Don gia hoa chat: " << MayXucTac::DON_GIA_HOA_CHAT << endl;
    MayXucTac m;
    m.nhap(); // Nhập thông tin sử dụng của máy xúc tác này
    cout << "Chi phi su dung may: " << m.tinhChiPhi() << endl;
    cout << "Luong nuoc loc duoc: " << m.tinhLuongNuoc() << endl;

    return 0;
}