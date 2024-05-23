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
    ofstream fout ("/Users/stefanandonov/CLionProjects/OOP_2024/en/ex11/output.txt");

    string line;
    int linesWithMoreThan10Vowel = 0;
    int totalCount = 0;
    while (getline(fin, line)) {
        fout << line << endl;
        int vowels = 0;
        for (int i = 0; i < line.length(); i++) {
            if (isVowel(line[i])) {
                ++vowels;
                ++totalCount;
            }
        }

        if (vowels>10){
            ++linesWithMoreThan10Vowel;
        }

    }

    fout << "A total of " << linesWithMoreThan10Vowel << " rows have more than 10 vowels." << endl;
    fout << "The file has a total of " << totalCount << " vowels." << endl;


}