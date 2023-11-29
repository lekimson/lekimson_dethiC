#include <iostream>
#include <vector>

using namespace std;

class Shop {
protected:
    int ShopID;
    double Area;

public:
    Shop(int id, double area) : ShopID(id), Area(area) {}

    virtual double calculateFee() = 0;
};

class FoodShop : public Shop {
private:
    double ColdStorage;

public:
    FoodShop(int id, double area, double coldStorage) : Shop(id, area), ColdStorage(coldStorage) {}

    double calculateFee() {
        double rent = 40000000 * Area;
        double tax = rent * 0.05;
        return rent + tax + ColdStorage;
    }
};

class ClothingShop : public Shop {
public:
    ClothingShop(int id, double area) : Shop(id, area) {}

    double calculateFee() {
        double rent = 40000000 * Area;
        double tax = rent * 0.1;
        return rent + tax;
    }
};

class JewelryShop : public Shop {
private:
    double Revenue;

public:
    JewelryShop(int id, double area, double revenue) : Shop(id, area), Revenue(revenue) {}

    double calculateFee() {
        double rent = 40000000 * Area;
        double tax;
        if (Revenue < 100000000) {
            tax = Revenue * 0.2;
        }
        else {
            tax = Revenue * 0.3;
        }
        return rent + tax;
    }
};

int main() {
    vector<Shop*> shops;

    // Thêm các sạp vào danh sách
    shops.push_back(new FoodShop(1, 50, 5000000));
    shops.push_back(new ClothingShop(2, 30));
    shops.push_back(new JewelryShop(3, 20, 150000000));

    // Tính tổng số tiền các sạp phải đóng hàng năm
    double totalFee = 0;
    for (Shop* shop : shops) {
        totalFee += shop->calculateFee();
    }

    cout << "Total fee: " << totalFee << " VND" << endl;

    // Giải phóng bộ nhớ
    for (Shop* shop : shops) {
        delete shop;
    }

    return 0;
}