//
// Created by Stefan Andonov on 17.4.24.
//

#include<iostream>
#include<cstring>

using namespace std;


enum GENDER {
    MALE, //0
    FEMALE //1
};

class Person { //base class
protected:
    string name;
    int age;
    GENDER gender;
public:
    Person(const string &name, int age, GENDER gender) : name(name), age(age), gender(gender) {}

    friend ostream &operator<<(ostream &os, const Person &person) {
        os << "name: " << person.name << " age: " << person.age << " gender: " << (person.gender==MALE ? "MALE" : "FEMALE");
        return os;
    }
};


class Student : public Person {
private:
    int index;
    int yearOfStudies;
    double GPA;
public:
    Student(const string &name, int age, GENDER gender, int index, int yearOfStudies, double gpa) : Person(name, age,
                                                                                                           gender) {
        this->index = index;
        this->yearOfStudies = yearOfStudies;
        this->GPA = gpa;
    }

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << static_cast<const Person &>(student) << " index: " << student.index << " yearOfStudies: "
           << student.yearOfStudies << " GPA: " << student.GPA;
        return os;
    }

};

int main() {
    Person person("Stefan", 27, MALE);
    cout << person << endl;

    Student student ("Stefan", 19, MALE, 151020, 1, 9.4);
    cout << student << endl;

    Person second = student;
    cout << second << endl;
    return 0;
}