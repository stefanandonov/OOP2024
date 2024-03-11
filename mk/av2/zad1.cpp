//
// Created by Stefan Andonov on 7.3.24.
//

#include<iostream>
using namespace std;

class FinkiStudent {
private:
    bool willForLife;
    int year;
    int index;
public:
    //2in1 nescafe
    FinkiStudent(bool _willForLife = false, int _year = 1, int _index = 151020){
        willForLife = _willForLife;
        year = _year;
        index = _index;
    }

    ~FinkiStudent(){

    }

    void print(){
        cout<< index << " " << willForLife << " " << year << " " << endl;
    }

};

int main () {

    FinkiStudent s1;

    FinkiStudent s2(true, 4, 202012);

    FinkiStudent s3(true);

    FinkiStudent s4(true, 2);

    s1.print();

    s2.print();

    s3.print();

    s4.print();


    return 0;
}