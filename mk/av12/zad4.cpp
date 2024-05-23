//
// Created by Stefan Andonov on 23.5.24.
//


#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {

    vector<int> firstVector(5);
    int s = firstVector.size();
    int c = firstVector.capacity();
    cout << "First Vector" << endl << "Size: " << s << " Capacity: " << c << endl;

    cout << (firstVector.empty() ? "First vector is empty" : "First vector is not empty") << endl;
    for (int i = 0; i < firstVector.size(); i++) {
        cout << firstVector[i] << " ";
    }


    vector<int> secondVector({1, 2, 3});
    s = secondVector.size();
    c = secondVector.capacity();
    cout << "Second Vector" << endl << "Size: " << s << " Capacity: " << c << endl;
    cout << "Vector elements: ";
    for (int i = 0; i < secondVector.size(); i++) {
        cout << secondVector[i] << " ";
    }

    secondVector.push_back(5);
    secondVector.push_back(6);

    s = secondVector.size();
    c = secondVector.capacity();
    cout << "Second Vector" << endl << "Size: " << s << " Capacity: " << c << endl;
    cout << "Vector elements: ";
    for (int i = 0; i < secondVector.size(); i++) {
        cout << secondVector[i] << " ";
    }

    secondVector.pop_back();
    s = secondVector.size();
    c = secondVector.capacity();
    cout << "Second Vector" << endl << "Size: " << s << " Capacity: " << c << endl;
    cout << "Vector elements: ";
    for (int i = 0; i < secondVector.size(); i++) {
        cout << secondVector[i] << " ";
    }

    secondVector.push_back(3);

    secondVector.erase(remove(secondVector.begin(),secondVector.end(), 3), secondVector.end());

    s = secondVector.size();
    c = secondVector.capacity();
    cout << "Second Vector" << endl << "Size: " << s << " Capacity: " << c << endl;
    cout << "Vector elements: ";
    for (int i = 0; i < secondVector.size(); i++) {
        cout << secondVector[i] << " ";
    }


    return 0;
}
