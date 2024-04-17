//
// Created by Stefan Andonov on 17.4.24.
//

#include<iostream>
#include<cstring>
using namespace std;

class DebitCard {
protected:
    string holder;
    string id;
    double balance;
public:
    DebitCard(const string &holder, const string &id, double balance = 0) : holder(holder), id(id), balance(balance) {}

    friend ostream &operator<<(ostream &os, const DebitCard &card) {
        os << "Holder: " << card.holder << " ID: " << card.id << " Balance: " << card.balance;
        return os;
    }

    void deposit (double amount){
        balance+=amount;
    }

    virtual void withdraw (double amount){
        if (amount<=balance){
            balance-=amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
};

class CreditCard : public DebitCard {
private:
    double limit;
    static double INTEREST;
public:
    CreditCard(const string &holder, const string &id, double balance, double limit) : DebitCard(holder, id, balance),
                                                                                       limit(limit) {}

    friend ostream &operator<<(ostream &os, const CreditCard &card);

    void withdraw(double amount) {
        double positiveAmount = 0;
        double negativeAmount = 0;

        if (balance>0){
            if (amount>balance){
                positiveAmount = balance;
                negativeAmount = amount - balance;
            } else {
                positiveAmount = amount;
                negativeAmount = 0;
            }
        } else {
            positiveAmount = 0;
            negativeAmount = amount;
        }

        negativeAmount *= (1+INTEREST);

        if ((balance - positiveAmount - negativeAmount)>=limit){
            balance-=positiveAmount;
            balance-=negativeAmount;
        } else {
            cout << "Insufficient amount" << endl;
        }
    }
};

double CreditCard::INTEREST = 0.05;

ostream &operator<<(ostream &os, const CreditCard &card) {
    os << static_cast<const DebitCard &>(card) << " limit: " << card.limit;
    return os;
}


//5%

int main (){

//    DebitCard card ("Stefan","123123123",1000);
//    cout << card << endl;
//
//    card.deposit(20000);
//    cout << card << endl;
//
//    card.withdraw(15000);
//    cout << card << endl;
//
//    card.withdraw(7000);
//    cout << card << endl;

    CreditCard cc ("Stefan","123123123", 1000, -50000);
    cout << cc << endl;

    cc.withdraw(5000);
    cout << cc << endl;

    cc.withdraw(1000);
    cout << cc << endl;

    cc.deposit(500);
    cout << cc << endl;

    cc.withdraw(30000);
    cout << cc << endl;

    cc.withdraw(30000);
    cout << cc << endl;
    return 0;
}