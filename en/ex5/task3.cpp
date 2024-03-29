//
// Created by Stefan Andonov on 29.3.24.
//

#include<iostream>
using namespace std;

class Student {
private:
    char * name;
    float average;
    int year;

    void copy (const Student &other){
        this->average = other.average;
        this->year = other.year;
        this->name = new char [strlen(other.name)+1];
        strcpy(this->name, other.name);
    }
public:
    Student(char *name = "", float average = 6.0, int year = 1)  {
        this->average = average;
        this->year = year;
        this->name = new char [strlen(name)+1];
        strcpy(this->name, name);
    }

    Student (const Student & s){
        copy(s);
    }

    Student & operator = (const Student &s){
        if (this!=&s){
            delete [] name;
            copy(s);
        }
        return *this;
    }

    friend ostream & operator << (ostream & out, const Student & s){
        return out << s.name << " " << s.year << " " << s.average;
    }

    friend istream & operator >> (istream & in, Student & s){
        return in >> s.name >> s.year >> s.average;
    }
};

class Course {
    char name [50];
    Student * students;
    int n;

public:
    Course(char * name = ""){
        strcpy(this->name, name);
        n = 0;
        students = new Student [0];
    }

    Course & operator+=(const Student & s){
        Student * tmp = new Student [n+1];
        for (int i=0;i<n;i++){
            tmp[i]=students[i];
        }
        tmp[n]=s;
        ++n;
        delete [] students;
        students = tmp;
        return *this;
    }
};

int main () {
    Student s;
    cin >> s;
    cout << s;
    return 0;
}
