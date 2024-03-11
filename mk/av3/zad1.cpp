//
// Created by Stefan Andonov on 11.3.24.
//


#include<iostream>

using namespace std;

class Boy {
    char fullName[50];
    int age;
public:

    Boy() {
        cout << "BOY DEFAULT CONSTRUCTOR" << endl;
        strcpy(fullName, "Stefan");
        age = 18;
    }

    Boy(char *_fullName, int _age) {
        cout << "BOY CONSTRUCTOR WITH ARGUMENTS" << endl;
        strcpy(fullName, _fullName);
        age = _age;
    }

    Boy(const Boy &other) {
        cout << "BOY COPY CONSTRUCTOR" << endl;
        strcpy(fullName, other.fullName);
        age = other.age;
    }

    ~Boy() {}

    void print() {
        cout << "Boy: " << fullName << " " << age << endl;
    }

    const char *getFullName() const {
        return fullName;
    }

    int getAge() const {
        return age;
    }

};

class Girl {
    char fullName[50];
    int age;
public:

    Girl() {
        cout << "GIRL DEFAULT CONSTRUCTOR" << endl;
        strcpy(fullName, "Ana");
        age = 18;
    }

    Girl(char *_fullName, int _age) {
        cout << "GIRL CONSTRUCTOR WITH ARGUMENTS" << endl;
        strcpy(fullName, _fullName);
        age = _age;
    }

    Girl(const Girl &other) {
        cout << "GIRL COPY CONSTRUCTOR" << endl;
        strcpy(fullName, other.fullName);
        age = other.age;
    }

    ~Girl() {}

    void print() {
        cout << "Girl: " << fullName << " " << age << endl;
    }

    const char *getFullName() const {
        return fullName;
    }

    int getAge() const {
        return age;
    }

};

class Date {
private:
    Boy boy;
    Girl girl;
public:
    Date() {
        cout << "DATE DEFAULT CONSTRUCTOR" << endl;
    }

    Date(Boy &_boy, Girl &_girl) {
        cout << "DATE CONSTRUCTOR WITH ARGS" << endl;
        boy = _boy;
        girl = _girl;
    }

    void print() {
        cout << "Date participants:" << endl;
        boy.print();
        girl.print();
    }

    const Boy &getBoy() const {
        return boy;
    }

    const Girl &getGirl() const {
        return girl;
    }
};

bool isMatch(Boy & boy, Girl & girl) {
    return ((boy.getAge() - girl.getAge() <= 7)
            && (boy.getAge() - girl.getAge() >= 0));
}

int main() {

    Boy boy("Petko Petkovski", 28);
    Girl girl("Ana Anovska", 24);

    Boy cloneBoy = boy; //eksplicitno copy constructor
    Girl cloneGirl(girl); //eksplicitno

//    boy.print();
//    girl.print();

    if (isMatch(boy, girl)){ //ako nema referenca vo isMatch, togas tuka se povikuva implicitno copy-const
        Date date(cloneBoy, cloneGirl); //ako e gore bez referenca, ova e implicitno povikuvanje na copy constructor
        date.print();
    }


    return 0;
}