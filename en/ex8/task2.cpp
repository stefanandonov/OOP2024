//
// Created by Stefan Andonov on 26.4.24.
//

#include<iostream>

using namespace std;

class HotelReservation {
protected:
    string name;
    int days;
    int people;
    static int PRICE_PER_PERSON_PER_DAY;
public:
    HotelReservation(const string &name, int days, int people) : name(name), days(days), people(people) {}

    virtual int price() {
        return days * people * PRICE_PER_PERSON_PER_DAY;
    }

    virtual void print() {
        cout << "Regular hotel reservation for: " << name << " " << days << " " << people << " " << price() << endl;
    }

    int price(int amount) {
        if (amount >= price()) {
            return amount - price();
        }
        return -1;
    }
};

class HalfBoardHotelReservation : public HotelReservation {
private:
    static int PRICE_PER_BREAKFAST;
public:
    HalfBoardHotelReservation(const string &name, int days, int people) : HotelReservation(name,
                                                                                           days,
                                                                                           people) {}

    int price() {
        return HotelReservation::price() + (days * people * PRICE_PER_BREAKFAST);
    }

    void print() {
        cout << "Half board hotel reservation for: " << name << " " << days << " " << people << " " << price() << endl;
    }

};

int HalfBoardHotelReservation::PRICE_PER_BREAKFAST = 5;


int HotelReservation::PRICE_PER_PERSON_PER_DAY = 25;


class Hotel {
private:
    string name;
    int income;
public:
    Hotel(const string &name) : name(name) {
        this->income = 0;
    }

    int pay(HotelReservation & hr, int amount) {
        int change = hr.price(amount);

        if (change > -1){
            income += hr.price();
        }

        return change;
    }

    void print () {
        cout << "Hotel: " << name << " Income: " << income << endl;
    }
};

int main() {
//    HotelReservation hr("Stefan", 5, 2);
//    hr.print();
//
//    HalfBoardHotelReservation hbhr("Stefan", 4, 2);
//    hbhr.print();
//
//    HotelReservation hr2 = hbhr;
//    hr2.print();

    HotelReservation *hr1 = new HotelReservation("Stefan", 5, 2);

    HotelReservation *hr2 = new HalfBoardHotelReservation("Stefan", 4, 2);

    hr1->print();
    hr2->print();

    Hotel hotel ("Macedonia");

    cout << hotel.pay(*hr1, 300) << endl;
    cout << hotel.pay(*hr2, 200) << endl;

    hotel.print();
    return 0;
}
