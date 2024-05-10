//
// Created by Stefan Andonov on 10.5.24.
//


#include<iostream>

using namespace std;

class Animal { //abstract class
protected:
    string name;
    int age;
public:
    Animal(const string &name, int age) : name(name), age(age) {}

    virtual void makeSound() = 0; //pure-virtual method -> abstract class just by at least one pure virtual method
};

class Cat : public Animal {
public:
    Cat(const string &name, int age) : Animal(name, age) {}

    void makeSound() {
        cout << "The cat with name " << name << " and age" << age << " makes the sound MJAUUUUU" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(const string &name, int age) : Animal(name, age) {}

    void makeSound() override {
        cout << "The dog with name " << name << " and age" << age << " makes the sound AFF" << endl;
    }
};

void printStatistics (Animal ** animals, int n){
    int cats = 0, dogs = 0;
    for (int i=0;i<n;i++){
        Cat * castedCat = dynamic_cast<Cat *>(animals[i]);

        if (castedCat){
            ++cats;
        } else {
            ++dogs;
        }
    }

    cout << "Cats: " << cats << " Dogs: " << dogs;
}

int main() {
//    Animal a ("tom",10); NOT ALLOWED!
//    Animal * a1 = new Cat ("tom",10);
//    Animal * a2 = new Dog("jack", 5);
//
//    a1->makeSound();
//    a2->makeSound();

    int n;
    cin >> n;

    Animal **animals = new Animal *[n];

    for (int i = 0; i < n; i++) {
        int type, age;
        string name;
        cin >> type >> name >> age;
        if (type == 1) { //cat
            animals[i] = new Cat(name, age);
        } else {
            animals[i] = new Dog(name, age);
        }
    }

    for (int i = 0; i < n; i++) {
        animals[i]->makeSound();
    }

    printStatistics(animals, n);

    return 0;
}