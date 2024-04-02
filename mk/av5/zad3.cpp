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

    Student &operator=(const Student &other) {
        if (this != &other) {
            delete[] name;
            copy(other);
        }

        return *this;
    }

    friend ostream &operator<<(ostream &out, const Student &s) {
        return out << s.name << " " << s.year << " " << s.average << endl;
    }
};

class Course {
    char name[50];
    Student *students;
    int count;
    int capacity;
public:
    Course(char *name = "", int capacity = 10) {
        strcpy(this->name, name);
        this->capacity = capacity;
        students = new Student[this->capacity];
        count = 0;
    }

    Course &operator+=(Student &other) {
        if (count == capacity) {
            Student *tmp = new Student[2 * capacity];
            capacity *= 2;
            for (int i = 0; i < count; i++) {
                tmp[i]=students[i];
            }
            delete [] students;
            students = tmp;
        }

        students[count]=other;
        count++;

        return *this;
    }
};

int main() {
    Student s("Stefan", 8.0, 4);

    cout << s << endl;
    return 0;
}