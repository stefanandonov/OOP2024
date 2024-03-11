//
// Created by Stefan Andonov on 1.3.24.
//

#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

void cleanName (char * str){
    str[0] = toupper(str[0]);
    for (int i=1;i<strlen(str);i++){
        str[i] = tolower(str[i]);
    }
}

struct Student {
    char firstName[100];
    char lastName[100];
    char id[7];
    int numberOfGrades;
    int grades[40];

    void read(){
        cin >> firstName >> lastName >> id >> numberOfGrades;
        cleanName(firstName);
        cleanName(lastName);
        for (int i=0;i<numberOfGrades;i++){
            cin >> grades[i];
        }
    }

    double average(){
        double sum = 0;
        for (int i=0;i<numberOfGrades;i++){
            sum+=grades[i];
        }
        return sum/numberOfGrades;
    }

    void print(){
        cout << firstName << " " << lastName << " " << id << " " << average() << endl;
    }

    int cmp (Student other){
        if (average() > other.average()){
            return 1;
        } else if (average() < other.average()) {
            return -1;
        } else {
            return 0;
        }
    }
};

int main () {
    Student students[100];

    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        students[i].read();
    }

    for (int i=0;i<n;i++){
        for (int j=i;j<n-1;j++){
            if (students[j].cmp(students[j+1])==-1){
                swap(students[j],students[j+1]);
            }
        }
    }

    for (int i=0;i<n;i++){
        students[i].print();
    }
    return 0;
}