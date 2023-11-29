#include <iostream>
#include <vector>

using namespace std;

class MayLoc {
protected:
    float thoiGianThue;

public:
    MayLoc(float thoiGianThue) : thoiGianThue(thoiGianThue) {}

    virtual float tinhChiPhiNVL() = 0;
};

class MayLyTam : public MayLoc {
private:
    float luongXang;

public:
    MayLyTam(float thoiGianThue, float luongXang) : MayLoc(thoiGianThue), luongXang(luongXang) {}

    float tinhChiPhiNVL() override {
        return luongXang * 20000;
    }
};

class MayXucTac : public MayLoc {
private:
    float luongHoaChat;

public:
    MayXucTac(float thoiGianThue, float luongHoaChat) : MayLoc(thoiGianThue), luongHoaChat(luongHoaChat) {}

    float tinhChiPhiNVL() override {
        return luongHoaChat * 10000;
    }
};

class Ao {
private:
    float luongNuoc;
    vector<MayLoc*> mayLocList;

public:
    void nhapDuLieu() {
        int soMayLoc;
        cout << "Nhap so luong may loc: ";
        cin >> soMayLoc;

        for (int i = 0; i < soMayLoc; i++) {
            char loaiMayLoc;
            float thoiGianThue;

            cout << "Nhap loai may loc (L: Ly tam, X: Xuc tac): ";
            cin >> loaiMayLoc;

            cout << "Nhap thoi gian thue (gio): ";
            cin >> thoiGianThue;

            if (loaiMayLoc == 'L') {
                float luongXang;
                cout << "Nhap luong xang (lit): ";
                cin >> luongXang;

                MayLyTam* mayLyTam = new MayLyTam(thoiGianThue, luongXang);
                mayLocList.push_back(mayLyTam);
            }
            else if (loaiMayLoc == 'X') {
                float luongHoaChat;
                cout << "Nhap luong hoa chat (kg): ";
                cin >> luongHoaChat;

                MayXucTac* mayXucTac = new MayXucTac(thoiGianThue, luongHoaChat);
                mayLocList.push_back(mayXucTac);
            }
        }

        cout << "Nhap luong nuoc trong ao (m3): ";
        cin >> luongNuoc;
    }

    bool locHetNuoc() {
        float tongCongSuat = 0;
        for (MayLoc* mayLoc : mayLocList) {
            tongCongSuat += mayLoc->tinhChiPhiNVL();
        }

        float thoiGianLoc = luongNuoc / tongCongSuat;
        return thoiGianLoc <= 1;
    }

    float tinhTongChiPhi() {
        float tongChiPhi = 0;
        for (MayLoc* mayLoc : mayLocList) {
            tongChiPhi += mayLoc->tinhChiPhiNVL();
        }
        return tongChiPhi;
    }

    ~Ao() {
        for (MayLoc* mayLoc : mayLocList) {
            delete mayLoc;
        }
    }
};

int main() {
    Ao ao;
    ao.nhapDuLieu();

    if (ao.locHetNuoc()) {
        cout << "Ao duoc loc het nuoc." << endl;
    }
    else {
        cout << "Ao khong duoc loc het nuoc." << endl;
    }

    float tongChiPhi = ao.tinhTongChiPhi();
    cout << "Tong chi phi su dung cac may loc: " << tongChiPhi << " dong." << endl;

    return 0;
}