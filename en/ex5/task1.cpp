//
// Created by Stefan Andonov on 29.3.24.
//

#include<iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int numerator = 1, int denominator = 1) : numerator(numerator), denominator(denominator) {}

    friend istream &operator>>(istream &in, Fraction &f) {
        in >> f.numerator >> f.denominator;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Fraction &f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }

    //1/2 + 3/4 = (1*4+3*2)/2*4 = 10/8


    //f1+f2
    Fraction operator+(Fraction &other) {
        return Fraction(
                this->numerator * other.denominator + other.numerator * this->denominator,
                this->denominator * other.denominator
        );
    }

    Fraction operator-(Fraction &other) {
        return Fraction(
                this->numerator * other.denominator - other.numerator * this->denominator,
                this->denominator * other.denominator
        );
    }

    Fraction operator*(Fraction &other) {
        return Fraction(
                this->numerator * other.numerator,
                this->denominator * other.denominator
        );
    }

    //cout << (f1+=f2);
    Fraction & operator+= (Fraction & other){
        this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
        this->denominator = this->denominator * other.denominator;
        return *this;
    }

    Fraction & operator-= (Fraction & other){
        this->numerator = this->numerator * other.denominator - other.numerator * this->denominator;
        this->denominator = this->denominator * other.denominator;
        return *this;
    }

    // cout << (f1 < f2)
    bool operator<(const Fraction &rhs) const {
        return this->numerator * rhs.denominator < rhs.numerator * this->denominator;
    }

    // cout << (f1 > f2) ==== cout << f2 <f1
    bool operator>(const Fraction &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Fraction &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Fraction &rhs) const {
        return !(*this < rhs);
    }

    bool operator== (const Fraction & rhs) {
        return this->numerator * rhs.denominator == rhs.numerator * this->denominator;
    }
};


int main() {
    Fraction f1, f2, f3;

    cin >> f1 >> f2 >> f3;

    cout << (f1 == f2) << endl;

    cout << f1 << endl << f2 << endl << f3 << endl;

    cout << (f1 + f2) << endl;

    cout << (f3+=f1) << endl << f3;



    return 0;
}
