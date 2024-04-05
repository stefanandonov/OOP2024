//
// Created by Stefan Andonov on 29.3.24.
//

#include<iostream>

using namespace std;

class Student {
private:
    char *name;
    float average;
    int year;

    void copy(const Student &other) {
        this->average = other.average;
        this->year = other.year;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }

public:
    Student(char *name = "", float average = 6.0, int year = 1) {
        this->average = average;
        this->year = year;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Student(const Student &s) {
        copy(s);
    }

    Student &operator=(const Student &s) {
        if (this != &s) {
            delete[] name;
            copy(s);
        }
        return *this;
    }

    ~Student() {
        delete[] name;
    }

    friend ostream &operator<<(ostream &out, const Student &s) {
        return out << s.name << " " << s.year << " " << s.average;
    }

    friend istream &operator>>(istream &in, Student &s) {
        return in >> s.name >> s.year >> s.average;
    }

    //++student;
    Student & operator++(){
        ++year;
        return *this;
    }

    //student++;
    Student operator++(int){
        Student copy(*this);
        ++year;
        return copy;
    }

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
    int n;

public:
    Faculty(char *name = "") {
        strcpy(this->name, name);
        n = 0;
        students = new Student[0];
    }

    Faculty &operator+=(const Student &s) {
        Student *tmp = new Student[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = students[i];
        }
        tmp[n] = s;
        ++n;
        delete[] students;
        students = tmp;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Faculty &f) {
        out << f.name << endl;
        for (int i = 0; i < f.n; i++) {
            cout << i+1 << ". " << f.students[i] << endl;
        }
        return out;
    }

    friend istream & operator >> (istream &in, Faculty & f){
        in >> f.name;
        int n;
        in >> n;
        for (int i=0;i<n;i++){
            Student s;
            in >> s;
            f+=s;
        }
        return in;
    }

    Faculty & operator++ (){
        for (int i=0;i<n;i++){
            ++students[i];
        }
        return *this;
    }

    Student & bestStudent(){
        int maxIdx;
        for (int i=0;i<n;i++){
            if (students[i]>students[maxIdx]){
                maxIdx = i;
            }
        }
        return students[maxIdx];
    }


};

int main() {


    Faculty f;

    cin >> f;
    cout << f;

    ++f.bestStudent();

    cout << f;


    int x = 5;
//    cout << ++x; //6
//    cout << x++; //6 because of postfix
//    cout << x; //7
    return 0;
}
