//
// Created by Stefan Andonov on 26.4.24.
//

#include<iostream>
using namespace std;

class TennisPlayer { //base class
protected:
    string name;
public:
    TennisPlayer(const string &name) : name(name) {}

    virtual void print () {
        cout << "Regular tennis player: " << name << endl;
    }

};

class RankedTennisPlayer : public TennisPlayer {
private:
    int rank;
public:
    RankedTennisPlayer(const string &name, int rank) : TennisPlayer(name), rank(rank) {}

    void print () {
        cout << "Ranked tennis player: " << name << " Rank: "<< rank << endl;
    }

};

int main () {

    //this is simple inheritance
//    TennisPlayer tp ("Stefan");
//    tp.print();
//
//    RankedTennisPlayer rtp ("Stefan", 100);
//    rtp.print();
//
//    TennisPlayer tp2 = rtp;
//    tp2.print();

    //polymorphism

    TennisPlayer * tp = new TennisPlayer("Stefan");

    TennisPlayer * tp2 = new RankedTennisPlayer("Stefan", 100);

    tp->print();
    tp2->print();


    return 0;
}
