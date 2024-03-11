//
// Created by Stefan Andonov on 29.2.24.
//

#include<iostream>

using namespace std;

struct City {
    char name[100];
    int population;

    void read() {
        cin >> name >> population;
    }

    void print() {
        cout << "Capital name: " << name << " with population: " << population;
    }
};

struct Politician {
    char name[100];
    char party[100];

    void read() {
        cin >> name >> party;
    }

    void print() {
        cout << "President " << name << " from party " << party;
    }
};

struct Country {
    char name[100];
    Politician president;
    City capital;
    int population;

    void read() {
        cin >> name;
        president.read(); //nikako cin >> president; cin >> president.read()
        capital.read();
        cin >> population;
    }

    void print() {
        cout << "Country name: " << name << " with population: " << population << " ";
        president.print();
        cout << " ";
        capital.print();
        cout << endl;
    }

    int cmp(Country other) {
        int diff = capital.population - other.capital.population;
        if (diff > 0) {
            return 1;
        } else if (diff < 0) {
            return -1;
        } else {
            return 0;
        }
    }
};

Country countryWithLargestCapitalPopulation(Country *countries, int n) {
    Country max = countries[0];
    for (int i = 1; i < n; i++) {
        if (countries[i].cmp(max)==1){
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
//        countries[i].print();
    }

    countryWithLargestCapitalPopulation(countries, n).print();

    return 0;
}