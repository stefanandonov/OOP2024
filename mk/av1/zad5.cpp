//
// Created by Stefan Andonov on 29.2.24.
//

#include<iostream>

using namespace std;

struct ArtPiece {
    char author[100];
    double price;
    int type; //1 - painting, 2 = sculpture

    void read() {
        cin >> author >> price >> type;
    }

    void print() {
        cout << author << " " << price << " " << type << endl;
    }
};

struct Gallery {
    char name[100];
    ArtPiece pieces[30];
    int n;

    void read() {
        cin >> name >> n;
        for (int i = 0; i < n; i++) {
            pieces[i].read();
        }
    }

    void print() {
        cout << name << endl;
        for (int i = 0; i < n; i++) {
            pieces[i].print();
        }
    }

    ArtPiece cheapest(int type) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (pieces[i].type == type) {
                if (idx == -1 || pieces[i].price <= pieces[idx].price) {
                    idx = i;
                }
            }
        }
        return pieces[idx];
    }
};

void bestOffer(Gallery *galleries, int n, int type) {
    Gallery best = galleries[0];

    for (int i = 1; i < n; i++) {
        if (galleries[i].cheapest(type).price <= best.cheapest(type).price) {
            best = galleries[i];
        }
    }

    cout << "Najevtino umetnicko delo tip " << (type == 1 ? "slika" : "skulptura")
         << "go nudi galerijata: "<< best.name << " so cena: "<< best.cheapest(type).price << endl;
}

int main() {
    int n;
    cin >> n;

    Gallery galleries[30];

    for (int i = 0; i < n; i++) {
        galleries[i].read();
    }

    int type;

    cin >> type;

    bestOffer(galleries, n, type);
    return 0;
}