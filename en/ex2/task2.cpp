
//
// Created by Stefan Andonov on 8.3.24.
//


#include<iostream>

using namespace std;

enum POSITION {
    EMPLOYEE, //0
    MANAGER, //1
    OWNER //2
};

class Employee {
private:
    char name[50];
    double salary;
    POSITION position;
public:
    //2in1 nescafe
    Employee(char *_name = "Stefan", double _salary = 18000, POSITION _position = EMPLOYEE) {
        strcpy(name, _name);
        salary = _salary;
        position = _position;
    }

    void print() {
        cout << name << " " << salary << " ";

        switch (position) {
            case EMPLOYEE:
                cout << "employee" << endl;
                break;
            case MANAGER:
                cout << "manager" << endl;
                break;
            default:
                cout << "owner" << endl;
                break;
        }
    }

    const char *getName() const {
        return name;
    }

    double getSalary() const {
        return salary;
    }

    void setSalary(double salary) {
        Employee::salary = salary;
    }

    POSITION getPosition() const {
        return position;
    }

    void setPosition(POSITION position) {
        Employee::position = position;
    }
};

void sort(Employee employees[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n - 1; j++) {
            if (employees[j].getSalary() < employees[j + 1].getSalary()) {
                swap(employees[j], employees[j + 1]);
            }
        }
    }
}

int main() {

    Employee employees[10]; //10 times the default constructor is called

    int n;
    cin >> n;

    char name[50];
    double salary;
    int position;
    for (int i = 0; i < n; i++) {
        cin >> name >> salary >> position;
        employees[i] = Employee(name, salary, (POSITION) position);
    }

    sort(employees, n);

    for (int i = 0; i < n; i++) {
        employees[i].print();
    }


    return 0;
}