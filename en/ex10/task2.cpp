//
// Created by Stefan Andonov on 10.5.24.
//


#include<iostream>

using namespace std;

class Product {
protected:
    string name;
    int price;
public:
    Product(const string &name, int price) : name(name), price(price) {}

};

class Discountable {
public:
    virtual int getPrice() = 0; //without discount

    virtual int getPriceWithDiscount() = 0;

    int getDiscount () {
        return getPrice() - getPriceWithDiscount();
    }

    virtual void print() = 0;
};

class FoodProduct : public Product, public Discountable {
    int calories;
public:
    FoodProduct(const string &name, int price, int calories) : Product(name, price), calories(calories) {}

    int getPrice() override {
        return price;
    }

    int getPriceWithDiscount() override {
        if (calories > 1000) {
            return int(price * 0.8); //20% discount
        } else if (calories > 500) {
            return int(price * 0.9); //10% discount;
        } else {
            return price;
        }
    }

    void print() override {
        cout << "Food product: "  << name << " " << price << " " << calories << " " << "(" << getPriceWithDiscount() << ")" << endl;
    }
};

class DigitalProduct : public Product, public Discountable {
private:
    float sizeInMB;
public:
    DigitalProduct(const string &name, int price, float sizeInMb) : Product(name, price), sizeInMB(sizeInMb) {}

    int getPrice() override {
        return price;
    }

    int getPriceWithDiscount() override {
        double discountCoef = 1.0;

        if (sizeInMB < 5 * 1024) {
            discountCoef -= 0.2;
        } else if (sizeInMB < 10 * 1024) {
            discountCoef -= 0.1;
        }

        if (name.find("HP") != -1) {
            discountCoef -= 0.15;
        }

        return int(price * discountCoef);
    }

    void print() override {
        cout << "Digital product: " << name << " " << price << " " << sizeInMB << "MB " << "(" << getPriceWithDiscount() << ")" << endl;
    }
};

int totalDiscount (Discountable ** products, int n) {
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += (products[i]->getDiscount());
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    Discountable ** products = new Discountable * [n];

    for (int i=0;i<n;i++){
        int type;

        string name;
        int price;
        cin >> type >> name >> price;
        if (type==1){
            int calories;
            cin >> calories;
            products[i] = new FoodProduct(name, price, calories);
        } else {
            float sizeInMb;
            cin >> sizeInMb;
            products[i] = new DigitalProduct(name, price, sizeInMb);
        }
    }

    for (int i=0;i<n;i++){
        products[i]->print();
    }

    cout << "TOTAL DISCOUNT" << endl;
    cout << totalDiscount(products, n);
    return 0;
}