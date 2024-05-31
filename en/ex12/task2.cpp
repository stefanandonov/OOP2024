//
// Created by Stefan Andonov on 23.5.24.
//
#include<iostream>

using namespace std;

class ElementAlreadyExistsException {
public:
    void message() {
        cout << "Element already exists!" << endl;
    }
};

template<typename T>
class List {
private:
    T *array;
    int n;
public:
    List() {
        n = 0;
        array = new T[n];
    }

    List &operator+=(T &element) {
        for (int i = 0; i < n; i++) {
            if (array[i] == element) {
                throw ElementAlreadyExistsException();
            }
        }


        T *tmp = new T[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = array[i];
        }
        tmp[n] = element;
        n++;
        delete[] array;
        array = tmp;

        return *this;
    }

    friend ostream &operator<<(ostream &out, const List &l) {
        if (l.n == 0) {
            out << "EMPTY LIST" << endl;
        } else {
            for (int i = 0; i < l.n; i++) {
                out << l.array[i] << endl;
            }
        }

        return out;
    }
};

int main() {

    int n;
    cin >> n;

    List<string> strList;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        try {
            strList += str;
        } catch (ElementAlreadyExistsException & e) {
            e.message();
        }
    }

    cout << strList;

}