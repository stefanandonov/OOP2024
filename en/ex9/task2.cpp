//
// Created by Stefan Andonov on 10.5.24.
//


#include<iostream>
#include<cmath>

using namespace std;

class Shape {
protected:
    double height;
public:
    Shape(double height) : height(height) {}

    void print() {
        cout << getShapeType() << " with volume of " << volume() << endl;
    }

    virtual string getShapeType() = 0;

    virtual double volume() = 0;

    double getHeight() const {
        return height;
    }

    bool operator<(Shape &rhs) {
        return volume() < rhs.volume();
    }

    bool operator>(Shape &rhs) {
        return rhs < *this;
    }

    bool operator<=(Shape &rhs) {
        return !(rhs < *this);
    }

    bool operator>=(Shape &rhs) {
        return !(*this < rhs);
    }


};

class Cylinder : public Shape {
private:
    double radius;
public:
    Cylinder(double height, double radius) : Shape(height), radius(radius) {}

    double volume() override {
        return pow(radius, 2) * M_PI * height;
    }

    string getShapeType() override {
        return "Cylinder";
    }
};

//class Cone : public Shape{
//private:
//    double radius;
//public:
//    Cone(double height, double radius) : Shape(height), radius(radius) {}
//
//    void print() override {
//        cout << "Cone with volume of " << volume() << endl;
//    }
//
//    double volume() override {
//        return (pow(radius,2) * M_PI * height)/3;
//    }
//};

class Cone : public Cylinder {
public:
    Cone(double height, double radius) : Cylinder(height, radius) {}

    double volume() override {
        return Cylinder::volume() / 3;
    }

    string getShapeType() override {
        return "Cone";
    }
};

class Cuboid : public Shape {
private:
    double a, b;
public:
    Cuboid(double height, double a, double b) : Shape(height), a(a), b(b) {}

    string getShapeType() override {
        return "Cuboid";
    }

    double volume() override {
        return a * b * height;
    }
};


class Cube : public Shape {
public:
    explicit Cube(double height) : Shape(height) {}

    string getShapeType() override {
        return "Cube";
    }

    double volume() override {
        return pow(height,3);
    }
};

Shape * maxShape (Shape ** shapes, int n){
    Shape * max = shapes[0];
    for (int i=0;i<n;i++){
        if (*shapes[i] > *max){
            max = shapes[i];
        }
    }
    return max;
}

int shapesWithoutCircleBase (Shape ** shapes, int n){
    int counter = 0;
    for (int i=0;i<n;i++){
        if (dynamic_cast<Cuboid *>(shapes[i]) || dynamic_cast<Cube *>(shapes[i])){
            ++counter;
        }
    }
    return counter;
}

int main() {
    int n;
    cin >> n;

    Shape **shapes = new Shape *[n];

    for (int i = 0; i < n; i++) {
        int type;
        double height;
        cin >> type >> height;

        if (type == 1) { //cylinder
            double radius;
            cin >> radius;
            shapes[i] = new Cylinder(height, radius);
        } else if (type == 2) { //cone
            double radius;
            cin >> radius;
            shapes[i] = new Cone(height, radius);
        } else if (type == 3) { //3==cuboid
            double a, b;
            cin >> a >> b;
            shapes[i] = new Cuboid(height, a, b);
        } else { //4 = cube
            shapes[i] = new Cube(height);
        }
    }

    for (int i=0;i<n;i++){
        shapes[i]->print();
    }

    cout << "SHAPE WITH MAX VOLUME" << endl;
    maxShape(shapes, n)->print();
    cout << "SHAPES WITHOUT CIRCLE BASE" << endl;
    cout << shapesWithoutCircleBase(shapes,n) << endl;
    return 0;
}