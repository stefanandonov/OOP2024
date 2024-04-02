//
// Created by Stefan Andonov on 28.3.24.
//


#include<iostream>

using namespace std;

class Array {
    int *content;
    int size;
    int capacity;

    void copy (const Array & other) {
        this->capacity = other.capacity;
        this->size = other.size;
        content = new int [this->capacity];
        for (int i=0;i<this->size;i++){
            content[i] = other.content[i];
        }
    }
public:
    Array(int capacity = 10) {
        this->capacity = capacity;
        size = 0;
        content = new int[capacity];
    }

    Array (const Array & other){
        copy(other);
    }

    Array & operator = (const Array & other) {
        if (this!=&other){
            delete [] content;
            copy(other);
        }

        return *this;
    }

    friend ostream &operator<<(ostream &out, const Array &a) {
        out << "Capacity: " << a.capacity << endl;
        out << "Size: " << a.size << endl;
        for (int i = 0; i < a.size; i++) {
            out << a.content[i] << " ";
        }
        out << endl;
        return out;
    }

    Array &operator+=(int number) {
         if (capacity==number) {
            int *tmp = new int[2 * capacity];
            capacity *= 2;
            for (int i = 0; i < size; i++) {
                tmp[i] = content[i];
            }
            delete [] content;
            content = tmp;
        }

        content[size] = number;
        size++;

        return *this;
    }

    ~Array(){
        delete [] content;
    }
};

int main() {
    Array a(3);
    cout << a;

    for (int i = 0; i < 14; i++) {
        a += i;
        cout << a;
    }


    return 0;
}