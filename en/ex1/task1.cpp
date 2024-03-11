//
// Created by Stefan Andonov on 1.3.24.
//

#include<iostream>
using namespace std;

void swap (int & x, int & y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main () {
    int a,b;
    cin >> a >> b;

    int & refA = a;
    refA--; //a--;

    cout << "BEFORE SWAP" << endl;
    cout << a << " " << b << endl;


    swap(a,b);

    cout << "AFTER SWAP" << endl;
    cout << a << " " << b << endl;
    return 0;
}