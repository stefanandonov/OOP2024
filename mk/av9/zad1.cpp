//
// Created by Stefan Andonov on 9.5.24.
//

#include<iostream>
using namespace std;

class Animal {
protected:
    string name;
public:
    Animal(const string &name) : name(name) {}

    virtual void makeSound() = 0;
};

class Cat : public Animal {
public:
    Cat(const string &name) : Animal(name) {}

    void makeSound() override {
        cout << "The cat " << name << " makes the sound: " << "MJAUUUUUU" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(const string &name) : Animal(name) {}

    void makeSound() override {
        cout << "The dog " << name << " makes the sound: " << "AF AF AF" << endl;
    }
};



int main () {

    Animal ** animals = new Animal * [2];

    Animal * animal1 = new Cat ("tomijerry");
    Animal * animal2 = new Dog("jack");

    for (int i=0;i<2;i++){
        int type;
        string name;
        cin >> type >> name;
        if (type==1){
            animals[i] = new Cat (name);
        } else {
            animals[i] = new Dog (name);
        }
    }

    for (int i=0;i<2;i++){
        if (dynamic_cast<Cat *>(animals[i])){
            cout << "CAT" << endl;
        } else {
            cout << "DOG" << endl;
        }
    }



    animal1->makeSound();
    animal2->makeSound();
    return 0;
}