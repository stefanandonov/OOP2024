//
// Created by Stefan Andonov on 29.3.24.
//

#include<iostream>

using namespace std;

class Array {
private:
    int capacity;
    int size;
    int *content; //declaration

    void copy(const Array &other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->content = new int[this->capacity];
        for (int i = 0; i < this->size; i++) {
            this->content[i] = other.content[i];
        }
    }

public:
    Array(int capacity = 5) {//with and without arguments
        this->capacity = capacity;
        this->size = 0;
        this->content = new int[this->capacity];
    }

    //copy-constructor
    Array(const Array &other) {
        copy(other);
    }

    //operator = (assignment)
    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] content;
            copy(other);
        }

        return *this;
    }

    ~Array() {
        delete[] content;
    }

    friend ostream &operator<<(ostream &out, const Array &a) {
        out << "Capacity: " << a.capacity << endl;
        out << "Size: " << a.size << " (" << (100.0 * a.size) / a.capacity << "%)" << endl;
        for (int i = 0; i < a.size; i++) {
            out << a.content[i] << " ";
        }
        out << endl;
        return out;
    }

    Array &operator+=(int number) {
        if (size == capacity) {
            //TODO increment the capacity
            int *tmp = new int[2 * capacity];
            capacity *= 2;
            for (int i = 0; i < size; i++) {
                tmp[i]=content[i];
            }
            delete [] content;
            content = tmp;

        }
        content[size] = number;
        size++;


        return *this;
    }


};

int main() {
    Array a(10), b;

    cout << a;

    for (int i = 1; i <= 100; i++) {
        a += i;
    }

    cout << a;

    b = a;
    cout << b;

//    a = b;
//    a = a;
//    int x;
//    cout << (x = 5); //self assignment
    return 0;
}
