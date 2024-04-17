//
// Created by Stefan Andonov on 28.3.24.
//


#include<iostream>

using namespace std;

class Student {
private:
    char *name;
    float average;
    int year;

    void copy(const Student &other) {
        this->year = other.year;
        this->average = other.average;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }

public:
    Student(char *name = "", float average = 6.0, int year = 1) {
        this->year = year;
        this->average = average;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Student(const Student &other) {
        copy(other);
    }

    Student & operator++(){
        ++year;
        return *this;
    }

    Student operator++ (int){
        Student copy(*this);
        ++year;
        return copy;
    }

    Student &operator=(const Student &other) {
        if (this != &other) {
            delete[] name;
            copy(other);
        }

        return *this;
    }

    ~Student() {
        delete[] name;
    }

//    friend ostream &operator<<(ostream &out, const Student &s) {
//        return out << s.name << " " << s.year << " " << s.average;
//    }

    bool operator<(const Student &rhs) const {
        return average < rhs.average;
    }

    bool operator>(const Student &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Student &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Student &rhs) const {
        return !(*this < rhs);
    }
};

class Faculty {
    char name[50];
    Student *students;
    int count;
public:
    Faculty(char *name = "") {
        strcpy(this->name, name);
        students = new Student[0];
        count = 0;
    }

    Faculty &operator+=(Student &newStudent) {

        Student *tmp = new Student[count + 1];
        for (int i = 0; i < count; i++) {
            tmp[i] = students[i];
        }
        tmp[count] = newStudent;
        ++count;
        delete[] students;
        students = tmp;

        return *this;
    }

    friend ostream &operator<<(ostream &out, const Faculty &f) {
        out << f.name << endl;
        out << f.count << endl;
        for (int i = 0; i < f.count; i++) {
            out << f.students[i] << endl;
        }
        return out;
    }

    Faculty & operator++(){
        for (int i=0;i<count;i++){
            ++students[i];
        }
        return *this;
    }


};

int main() {
    Student s("Stefan", 8.0, 4);
    Student s2("Petko", 9.0, 2);

    cout << s2++ << endl;

    Faculty f ("FINKI");

    f+=s;
    f+=s2;

    cout << f;

//    int x = 5;
//    cout << ++x << endl;
//    cout << x++ << endl;
//    cout << x << endl;


    return 0;
}