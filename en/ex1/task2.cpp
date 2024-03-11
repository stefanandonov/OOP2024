//
// Created by Stefan Andonov on 1.3.24.
//

#include<iostream>

using namespace std;

int intcmp (int a, int b){
    if (a>b){
        return 1;
    } else if (a<b){
        return -1;
    } else {
        return 0;
    }
}

struct Date {
    int day;
    int month;
    int year;

    void read() {
        cin >> day >> month >> year;
    }

    void print() {
        cout << day << "." << month << "." << year << endl;
    }

    int cmp(Date other){

        int result = intcmp(year, other.year);
        if (result==0){
            result = intcmp(month, other.month);
            if (result==0){
                result = intcmp(day, other.day);
            }
        }
        return result;


//        if (year > other.year){
//            return 1;
//        } else if (year < other.year){
//            return -1;
//        } else { //year == other.year
//            if (month > other.month){
//                return 1;
//            } else if (month < other.month){
//                return -1;
//            } else {  //year == other.year && month==other.month
//                if (day > other.day){
//                    return 1;
//                } else if (day < other.day){
//                    return -1;
//                } else {
//                    return 0;
//                }
//            }
//        }
    }
};



int main() {
    Date date;
    Date date2;
    date.read();
    date.print();
    date2.read();
    date2.print();

    cout << date.cmp(date2); //1 -> date>date2, 0 -> date==date2, -1 date<date2
    return 0;
}