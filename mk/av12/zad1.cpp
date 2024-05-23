//
// Created by Stefan Andonov on 23.5.24.
//

#include<iostream>

using namespace std;


template<typename T>
void mySwap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {

    int a=5,b=6;

    mySwap(a,b);

    cout << a << " " << b << endl;

    string aa = "Stefna", bb = "Andonov";

    mySwap(aa,bb);
    cout << aa << " " << bb << endl;

//    mySwap(a,aa); this is WRONG!! question on the tests
    return 0;
}