//
// Created by Stefan Andonov on 9.5.24.
//

#include<iostream>

using namespace std;

class Vehicle {
protected:
    int acceleration;
public:
    explicit Vehicle(int a = 1) {
        acceleration = a;
        cout << "VEHICLE CONSTRUCTOR" << endl;
    }

    ~Vehicle() {
        cout << "VEHICLE DESTRUCTOR" << endl;
    }

    virtual void accelerate() {
        cout << "Vehicle accelerating" << endl;
        acceleration += 1;
    }

    int getAcceleration() const {
        return acceleration;
    }
};

class Car : virtual public Vehicle {
public:

    Car(int a = 1) : Vehicle(a) {
        cout << "CAR CONSTRUCTOR" << endl;
    }

    ~Car() {
        cout << "CAR DESTRUCTOR" << endl;
    }

    void accelerate() override {
        cout << "Car accelerating" << endl;
        acceleration += 2;
    }
};

class Jet : virtual public Vehicle {
public:

    Jet(int a = 1) : Vehicle(a) {
        cout << "JET CONSTRUCTOR" << endl;
    }

    ~Jet() {
        cout << "JET DESTRUCTOR" << endl;
    }

    void accelerate() override {
        cout << "Jet accelerating" << endl;
        acceleration += 10;
    }
};

class JetCar : public Jet, public Car {
public:
    JetCar(int a = 1) {
        this->acceleration = a;
        cout << "JETCAR CONSTRUCTOR" << endl;
    }

    ~JetCar() {
        cout << "JETCAR DESTRUCTOR" << endl;
    }

    void accelerate() override {
        cout << "JetCar accelerating" << endl;
        this->acceleration += 20;
    }
};


int main() {

//    JetCar jetcar(100);

    Vehicle **vehicle = new Vehicle *[4];
    vehicle[0] = new Vehicle();
    vehicle[1] = new Car (5);
    vehicle[2] = new Jet (200);
    vehicle[3] = new JetCar(50);


    for (int i=0;i<4;i++){
        vehicle[i]->accelerate();
    }

    for (int i=0;i<4;i++){
        cout << vehicle[i]->getAcceleration() << endl;
    }

    return 0;
}