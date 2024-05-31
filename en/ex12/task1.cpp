//
// Created by Stefan Andonov on 23.5.24.
//

#include<iostream>

using namespace std;

//template function
template<typename T>
void templateSwap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

//void swap(int & a, int & b) {
//    int tmp = a;
//    a = b;
//    b = tmp;
//}
//
//void swap(double & a, double & b) {
//    double tmp = a;
//    a = b;
//    b = tmp;
//}
//
//void swap(string & a, string & b) {
//    string tmp = a;
//    a = b;
//    b = tmp;
//}

int main() {

    int a, b;
    cin >> a >> b;

    templateSwap(a, b);

    cout << a << " " << b;

    string aa, bb;

    cin >> aa >> bb;

    templateSwap(aa, bb);

    cout << aa << " " << bb;

}