////
//// Created by Stefan Andonov on 29.2.24.
////
//
//#include<iostream>
//using namespace std;
//
//struct Date {
//    int day;
//    int month;
//    int year;
//
//    void print (){
//        cout << day << "." << month << "." << year << endl;
//    }
//
//    void read (){
//        cin >> day >> month >> year;
//    }
//
//    int cmp (Date other){
//        int diff = year - other.year;
//        if (diff==0){
//            diff = month - other.month;
//            if (diff == 0){
//                diff = day - other.day;
//                if (diff == 0){
//                    return 0;
//                }
//            }
//        }
//
//        if (diff>0){
//            return 1;
//        } else {
//            return -1;
//        }
//
////        if (year > other.year){
////            return 1;
////        } else if (year < other.year){
////            return -1;
////        } else { //year == other.year
////            if (month > other.month){
////                return 1;
////            } else if (month < other.month){
////                return -1;
////            } else { //year == other.year && month == other.month
////                if (day > other.day){
////                    return 1;
////                } else if (day < other.day) {
////                    return -1;
////                } else {
////                    return 0;
////                }
////            }
////        }
//    }
//};
//
////void read (Date & date){
////    cin >> date.day >> date.month >> date.year;
////}
//
//int main () {
//    Date date1;
//    Date date2;
//    date1.read();
//    date2.read();
//
//    cout << date1.cmp(date2);
//
//
//    return 0;
//}