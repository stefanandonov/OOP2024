//
// Created by Stefan Andonov on 23.5.24.
//

#include<iostream>

using namespace std;

template <typename T>
class ElementAlreadyExistsException {
private:
    T element;
public:

    explicit ElementAlreadyExistsException(T element) : element(element) {}

    void message() {
        cout << element << " already exists" << endl;
    }
};

template<typename T>
class List {
private:
    T *content;
    int n;
public:
    List() {
        n = 0;
        content = new T[0];
    }

    List &operator+=(const T &t) {

        for (int i = 0; i < n; i++) {
            if (content[i] == t){
                throw ElementAlreadyExistsException<T>(t);
            }
        }

        T *tmp = new T[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = content[i];
        }
        tmp[n++] = t;
        delete[] content;
        content = tmp;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const List &l) {
        if (l.n == 0) {
            out << "List is empty";
        } else {
            for (int i = 0; i < l.n; i++) {
                out << i + 1 << "." << l.content[i] << endl;
            }
        }

        return out;

    }
};
template <typename T>
void print (T * array, int n){
    for (int i=0;i<n;i++){
        cout << array[i];
    }
}

int main() {
    int n;
    cin >> n;

    List<string> list;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        try{
            list += input;
        }
        catch (ElementAlreadyExistsException<string> & e){
            e.message();
        }
    }

    cout << list;

    List<string> * array = new List<string> [1];
    array[0]=list;

    print(array, 1);
    return 0;
}