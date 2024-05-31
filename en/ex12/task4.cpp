//
// Created by Stefan Andonov on 23.5.24.
//

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

//vector testing

int main() {

    vector<int> ints;
    cout << ints.size() << " " << ints.capacity() << endl;

    vector<int> ints2(5);
    cout << ints2.size() << " " << ints2.capacity() << endl;

    for (int i = 0; i < ints2.size(); i++) {
        cout << ints2[i] << " ";
    }
    cout << endl;
    for (int element: ints2) {
        cout << element << " ";
    }

    cout << endl;


    for (int i = 0; i < 17; i++) {
        cout << "Adding value " << i << endl;
        ints.push_back(i % 3);
        cout << ints.size() << " " << ints.capacity() << endl;
        for (int element: ints) {
            cout << element << " ";
        }
        cout << endl;
    }


    ints.erase(remove(
                       ints.begin(),
                       ints.end(),
                       1
               ), ints.end()
    );

    for (int element: ints) {
        cout << element << " ";
    }
    cout << endl;


    return 0;
}
