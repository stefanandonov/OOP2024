//
// Created by Stefan Andonov on 21.3.24.
//

#include<iostream>
using namespace std;

class Student {
private:
    int index; //231001, 231002, 231003, ...
    char name [50];
    double average;
    static int TOTAL_STUDENTS;
    static double SUM_OF_AVERAGES;

public:
    Student(char * name, double average){
        strcpy(this->name, name);
        this->average = average;
        index = 231001 + TOTAL_STUDENTS;
        TOTAL_STUDENTS++;
        SUM_OF_AVERAGES+=average;
    }

    void print(){
        cout << index << " " << name << " " << average << endl;
    }

    static double averageOfAllStudents(){
        return SUM_OF_AVERAGES / TOTAL_STUDENTS;
    }
};

int Student::TOTAL_STUDENTS = 0;
double Student::SUM_OF_AVERAGES = 0.0;

int main (){
    Student stefan ("Stefan", 9.0);
    cout << Student::averageOfAllStudents() << endl;

    Student petko ("Petko", 9.18);
    cout << Student::averageOfAllStudents() << endl;

    Student riste ("Riste", 9.1);
    cout << Student::averageOfAllStudents() << endl;

    Student trajce ("Trajce", 9.2);
    cout << Student::averageOfAllStudents() << endl;

    Student ana ("Ana", 10.0);
    cout << Student::averageOfAllStudents() << endl;

    stefan.print();
    petko.print();
    riste.print();
    trajce.print();
    ana.print();
    return 0;
}