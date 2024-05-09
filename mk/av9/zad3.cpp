//
// Created by Stefan Andonov on 9.5.24.
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

class Discountable { //interface - behaviour
public:
    virtual int getPrice() = 0;

    virtual int getPriceWithDiscount() = 0;

    virtual void print() = 0;

    int discount (){
        return getPrice() - getPriceWithDiscount();
    }
};


class FoodProduct : public Product, public Discountable {
    int calories;
public:

    FoodProduct(const string &name, int price, int calories) : Product(name, price), calories(calories) {}

    int getPrice() override {
        return price;
    }

    int getPriceWithDiscount() override {
        if (calories>1000){
            return (int) (price * 0.7);
        }
        else if (calories>500){
            return (int) (price * 0.85);
        } else {
            return price;
        }
    }

    void print() override {
        cout << "FOOD" << " " << name << " (" << calories << ") " << getPrice() << " " << getPriceWithDiscount() << endl;
    }
};

class DigitalProduct : public Product, public Discountable{
    int sizeInMB;

public:
    DigitalProduct(const string &name, int price, int sizeInMb) : Product(name, price), sizeInMB(sizeInMb) {}

    int getPrice() override {
        return price;
    }

    int getPriceWithDiscount() override {
        double discount = 1.0;

        if (sizeInMB >= 100 * 1024){
            discount-=0.2;
        }
        else if (sizeInMB >= 50 * 1024){
            discount-=0.1;
        }

        if (name.find("HP")!=-1){
            discount-=0.05;
        }

        return (int) (price * discount);
    }

    void print() override {
        cout << "DIGITAL" << " " << name << " (" << sizeInMB << "MB) " << getPrice() << " " << getPriceWithDiscount() << endl;
    }
};

int totalDiscount (Discountable ** products, int n){
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += (products[i]->discount());
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
        int calories;
        int size;

        cin >> type >> name >> price;
        if (type==1){
            cin >> calories;
            products[i] = new FoodProduct(name, price, calories);
        } else {
            cin >> size;
            products[i] = new DigitalProduct(name, price, size);
        }
    }

    for (int i=0;i<n;i++){
        products[i]->print();
    }

    cout << totalDiscount(products, n);
    return 0;
}