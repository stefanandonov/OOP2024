//
// Created by Stefan Andonov on 8.3.24.
//


#include<iostream>
using namespace std;

class FCSEStudent{
private:
    bool willForLife;
    int redbullsDrank;
    int year;
    char ID[7];
public:
    //2in1 nescafe
    FCSEStudent(bool _willForLife = false, int _redbullsDrank = 0, int _year = 1, char *_id = "151020") {
        willForLife = _willForLife;
        redbullsDrank = _redbullsDrank;
        year = _year;
        strcpy(ID, _id);
    }

    ~FCSEStudent(){

    }

    void print(){
        cout << ID << " " << year << " " << redbullsDrank << " " << willForLife << endl;
    }

};

int main (){
    FCSEStudent student;
    FCSEStudent student2 (true, 0, 4, "200001");
    FCSEStudent student3 (true, 0, 4);
    FCSEStudent student4 (true, 0);
    FCSEStudent student5 (true);

    student.print();
    student2.print();
    student3.print();
    student4.print();
    student5.print();

    return 0;
}