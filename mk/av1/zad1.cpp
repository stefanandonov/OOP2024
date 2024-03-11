//
// Created by Stefan Andonov on 29.2.24.
//

#include<iostream>
using namespace std;

void swap (int & a, int & b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main () {
    int x,y;
    cin >> x >> y;

    int & reff = x;
    reff--;

    cout << x << endl;

    swap(x,y);

    cout << x << " " << y << endl;
}
