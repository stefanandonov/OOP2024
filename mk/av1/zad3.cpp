//
// Created by Stefan Andonov on 29.2.24.
//

#include<iostream>
using namespace std;

struct ComplexNumber {
    double real;
    double imaginary;

    void read() {
        cin >> real >> imaginary;
    }

    void print(){
        if (imaginary>=0){
            cout << real << "+" << imaginary << "i" << endl;
        } else {
            cout << real << imaginary << "i" << endl;
        }
    }

    ComplexNumber add (ComplexNumber other){
//        ComplexNumber result;
//        result.real = real + other.real;
//        result.imaginary = imaginary + other.imaginary;
//        return result;

        return {real + other.real, imaginary+other.imaginary};
    }

};

int main () {
    ComplexNumber cn;
    ComplexNumber cn2;
    cn.read();
    cn.print();
    cn2.read();
    cn2.print();

    cn.add(cn2).print();

    return 0;
}