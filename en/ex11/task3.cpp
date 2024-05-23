//
// Created by Stefan Andonov on 26.4.24.
//


#include<iostream>
#include<cstring>
#include<cctype>
#include<fstream>

using namespace std;

bool isVowel(char c) {
    switch (tolower(c)) {
        case 'a':
        case 'e':
        case 'i':
        case 'u':
        case 'o':
            return true;
        default:
            return false;
    }
}

int main() {
    ifstream fin("/Users/stefanandonov/CLionProjects/OOP_2024/en/ex11/input1.txt");

    char c; //current character that you are reading

    int vowelsPerLine = 0;
    int linesWithMoreThan10Vowel = 0;
    int totalCount = 0;
    while (fin.get(c)) {
        if (c == '\n') {
            cout << endl << vowelsPerLine << endl;
            if (vowelsPerLine > 10) {
                linesWithMoreThan10Vowel++;
            }
            vowelsPerLine = 0;
        }
        if (isVowel(c)) {
            cout << c;
            vowelsPerLine++;
            totalCount++;
        }
    }
    cout << endl << vowelsPerLine << endl;
    if (vowelsPerLine > 10) {
        linesWithMoreThan10Vowel++;
    }

    cout << "A total of " << linesWithMoreThan10Vowel << " rows have more than 10 vowels." << endl;
    cout << "The file has a total of " << totalCount << " vowels." << endl;


}