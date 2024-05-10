//
// Created by Stefan Andonov on 10.5.24.
//


#include<iostream>
using namespace std;

class Vehicle {
protected:
    int acceleration;
public:
    explicit Vehicle(int acceleration = 1) : acceleration(acceleration) {
        cout << "VEHICLE CONST" << endl;
    }

    ~Vehicle(){
        cout << "VEHICLE DEST" << endl;
    }

    virtual void accelerate() {
        acceleration+=1;
        cout << "VEHICLE ACCELERATING" << endl;
    }

    virtual int getAcceleration() const {
        return acceleration;
    }
};

class Car : virtual public Vehicle {
public:
    explicit Car(int acceleration = 10) : Vehicle(acceleration) {
        cout << "CAR CONST" << endl;
    }

    ~Car() {
        cout << "CAR DEST" << endl;
    }

    void accelerate() override {
        acceleration+=2;
        cout << "CAR ACCELERATING" << endl;
    }

};

class Jet : virtual public Vehicle {
public:
    explicit Jet(int acceleration = 100) : Vehicle(acceleration) {
        cout << "JET CONST" << endl;
    }

    ~Jet() {
        cout << "JET DEST" << endl;
    }

    void accelerate() override {
        acceleration+=50;
        cout << "JET ACCELERATING" << endl;
    }
};

class JetCar: public Jet, public Car {
public:
    JetCar(int a) {
        this->acceleration = a;
        cout << "JETCAR CONST" << endl;
    }

    ~JetCar(){
        cout << "JETCAR DEST" << endl;
    }

    void accelerate() override {
        this->acceleration+=25;
        cout << "JETCAR ACCELERATING" << endl;
    }
};

int main (){

    Vehicle ** vehicles = new Vehicle * [4];

    vehicles[0] = new Vehicle(1);
    vehicles[1] = new Car (5);
    vehicles[2] = new Jet(100);
    vehicles[3] = new JetCar(25);

    for (int i=0;i<3;i++){
        cout << vehicles[i]->getAcceleration() << endl;
        vehicles[i]->accelerate();
        cout << vehicles[i]->getAcceleration() << endl;
    }

//    JetCar jc(25);
//
//    cout << jc.getAcceleration() << endl;
//    jc.accelerate();
//    cout << jc.getAcceleration() << endl;
    return 0;
}