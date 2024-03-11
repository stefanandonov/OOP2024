//
// Created by Stefan Andonov on 7.3.24.
//

#include<iostream>
using namespace std;

enum POSITION {
    EMPLOYEE, //0
    TEAM_LEAD, //1
    DIRECTOR //2
};

class Employee{
private:
    char name [50];
    double salary;
    POSITION position;
public:
    Employee(char *_name = "Finkash", double _salary = 0, int _position = 0) {
        salary = _salary;
        position = (POSITION) _position;
        strcpy(name, _name);
    }

    void print (){
        cout << name << " " << salary << " ";

        switch (position) {
            case EMPLOYEE:
                cout << "employee" << endl; break;
            case TEAM_LEAD:
                cout << "team lead" << endl; break;
            default:
                cout << "Director" << endl; break;
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


void sort (Employee employees[], int n){
    for (int i=0;i<n;i++){
        for (int j=i;j<n-1;j++){
            if (employees[j].getSalary()<employees[j+1].getSalary()){
                swap(employees[j],employees[j+1]);
            }
        }
    }
}

int main () {
    int n;
    cin >> n;

    Employee employees[10]; //se povikuva default constructor, 10 pati

    char name [50];
    double salary;
    int position;


    for (int i=0;i<n;i++){
        cin >> name >> salary >> position;
        employees[i] = Employee(name, salary, position);
    }

    sort(employees, n);


    for (int i=0;i<n;i++){
        employees[i].print();
    }

    return 0;
}