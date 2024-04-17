//
// Created by Stefan Andonov on 17.4.24.
//

#include<iostream>
#include<cstring>
using namespace std;

class TennisPlayer {
protected:
    string fullName;
    bool league;
public:
    TennisPlayer(const string &fullName, bool league = true) : fullName(fullName), league(league) {}

    TennisPlayer(const TennisPlayer & other){
        this->fullName = other.fullName;
        this->league = other.league;
    }

    friend ostream &operator<<(ostream &os, const TennisPlayer &player) {
        os << "Name: " << player.fullName << " Plays in a league? " << (player.league ? "yes" : "no");
        return os;
    }

    void setLeague(bool league) {
        TennisPlayer::league = league;
    }
};

class RankedTennisPlayer : public TennisPlayer {
private:
    int rank;
public:
    RankedTennisPlayer(const string &fullName, int rank) : TennisPlayer(fullName), rank(rank) {}

    RankedTennisPlayer(const TennisPlayer & tp, int rank) : TennisPlayer(tp){
        this->rank = rank;
        this->league = true;
    }

    friend ostream &operator<<(ostream &os, const RankedTennisPlayer &player) {
        os << "Name: " << player.fullName << " Plays in a league? " << (player.league ? "yes" : "no") << " rank: " << player.rank;
        return os;
    }
};

int main (){
    TennisPlayer player ("Stefan Andonov", false);
    cout << player << endl;

//

    RankedTennisPlayer rtp ("Novak Gjokovic", 1);
    cout << rtp << endl;

    rtp.setLeague(false); //retirement

    cout << rtp << endl;

    RankedTennisPlayer rtpStefan (player, 10000);
    cout << rtpStefan << endl;

    return 0;
}