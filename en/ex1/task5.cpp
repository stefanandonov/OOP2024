//
// Created by Stefan Andonov on 1.3.24.
//

#include<iostream>

using namespace std;

int intcmp(int a, int b) {
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    } else {
        return 0;
    }
}

struct City {
    char name[50];
    int population;

    void read() {
        cin >> name >> population;
    }

    void print() {
        cout << "Capital name: " << name << " Population: " << population << endl;
    }
};

struct Politician {
    char name[50];
    char party[50];

    void read() {
        cin.ignore();
        cin.getline(name, 50);
//        cin.ignore();
        cin >> party;
    }

    void print() {
        cout << "President: " << name << "(" << party << ")" << endl;
    }
};

struct Country {
    char name[100];
    int population;
    City capital;
    Politician president;

    void read() {
        cin.ignore();
        cin.getline(name, 50);
        cin >> population;
        capital.read();
        president.read();
    }

    void print() {
        cout << name << " " << population << endl;
        capital.print();
        president.print();
    }

    int cmp(Country other) {
        return intcmp(capital.population, other.capital.population);
    }
};

Country max(Country *countries, int n) {
    Country max = countries[0];
    for (int i = 0; i < n; i++) {
        if (countries->capital.population > max.capital.population) {
            max = countries[i];
        }
    }
    return max;
}


int main() {
    Country countries[10];

    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        countries[i].read();
    }

//    for (int i = 0; i < n; i++) {
//        countries[i].print();
//    }

    max(countries, n).print();
}