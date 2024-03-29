//
// Created by Stefan Andonov on 20.3.24.
//


#include<iostream>

using namespace std;

class Student {
    char name[50];
    double gpa;
    int index; //sequential number 231500, 231501, 231502, 231503, ...
    const static int START_INDEX;
    static int ENROLLED_STUDENTS;
    const static double MIN_AVERAGE_GRADE;
    const static double MAX_AVERAGE_GRADE;

    static double SUM_OF_GPA;

public:
    Student(char *name, double gpa) {
        strcpy(this->name, name);

        if (gpa < MIN_AVERAGE_GRADE) {
            this->gpa = MIN_AVERAGE_GRADE;
        } else if (gpa > MAX_AVERAGE_GRADE) {
            this->gpa = MAX_AVERAGE_GRADE;
        } else {
            this->gpa = gpa;
        }

        SUM_OF_GPA += this->gpa;

        this->index = START_INDEX + ENROLLED_STUDENTS;
        ENROLLED_STUDENTS++;
    }

    static double gpaOfAllStudent() {
        return SUM_OF_GPA / ENROLLED_STUDENTS;
    }

    void print() {
        cout << index << " " << name << " " << gpa << endl;
    }


};

const int Student::START_INDEX = 231500;
int Student::ENROLLED_STUDENTS = 0;
const double Student::MIN_AVERAGE_GRADE = 5.0;
const double Student::MAX_AVERAGE_GRADE = 10.0;
double Student::SUM_OF_GPA = 0.0;


int main() {
    Student s1("Stefan", 4.0);
    cout << Student::gpaOfAllStudent() << endl;
    Student s2("Petko", 10.5);
    cout << Student::gpaOfAllStudent() << endl;
    Student s3("Riste", 7.88);
    cout << Student::gpaOfAllStudent() << endl;
    Student s4("Ana", 10.0);
    cout << Student::gpaOfAllStudent() << endl;

    s1.print();
    s2.print();
    s3.print();
    s4.print();

    return 0;
}