//
// Created by Stefan Andonov on 28.3.24.
//


#include<iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator=1, int denominator=1) : numerator(numerator), denominator(denominator) {}


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

    friend ostream & operator << (ostream & out, const Fraction & f){
        out << f.numerator << "/" << f.denominator << endl;
        return out;
    }

    friend istream & operator >> (istream & in, Fraction & f){
        in >> f.numerator >> f.denominator;
        return in;
    }

    bool operator<(const Fraction &rhs) const {
        return (this->numerator * rhs.denominator < rhs.numerator*this->denominator);
    }

    bool operator>(const Fraction &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Fraction &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Fraction &rhs) const {
        return !(*this < rhs);
    }


    Fraction & operator += (Fraction & rhs){
        this->numerator = this->numerator * rhs.denominator + rhs.numerator * this->denominator;
        this->denominator = this->denominator * rhs.denominator;
        return *this;
    }
};



int main() {

    Fraction f1,f2,f3;

//    int a,b;
//    cin >> a >> b;
//    f = Fraction(a,b);
    cin >> f1 >> f2 >> f3;
    cout << f1 << f2 << f3;

    cout << (f1+f2);
    cout << (f1 > f2) << endl;

    cout << (f3+=f1);



    return 0;
}