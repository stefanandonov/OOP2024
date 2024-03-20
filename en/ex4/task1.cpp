//
// Created by Stefan Andonov on 20.3.24.
//


#include<iostream>

using namespace std;

class Team {
private:
    char name[50];
    int foundingYear;
    char city[50];
public:
    //2in1 constructor

    Team() {
        cout << "TEAM DEFAULT CONSTRUCTOR CALLED" << endl;
        strcpy(this->name, "");
        strcpy(this->city, "");
        this->foundingYear = 1800;
    }

    Team(char *name, int foundingYear, char *city) {
        cout << "TEAM CONSTRUCTOR CALLED" << endl;
        strcpy(this->name, name);
        strcpy(this->city, city);
        this->foundingYear = foundingYear;
    }

    Team(const Team &other) {
        cout << "TEAM COPY-CONSTRUCTOR CALLED" << endl;
        strcpy(this->name, other.name);
        strcpy(this->city, other.city);
        this->foundingYear = other.foundingYear;
    }

    void print() {
        cout << name << " - " << city << " (" << foundingYear << ")" << endl;
    }

    void setFoundingYear(int foundingYear) {
        Team::foundingYear = foundingYear;
    }

    const char *getName() const {
        return name;
    }

    int getFoundingYear() const {
        return foundingYear;
    }

    const char *getCity() const {
        return city;
    }
};

class Game {
private:
    Team home;
    Team away;
    int goalsHome;
    int goalsAway;
public:
    Game(Team &home, Team &away, int goalsHome, int goalsAway) {
        this->home = home;
        this->away = away;
        this->goalsAway = goalsAway;
        this->goalsHome = goalsHome;
    }

    void print() {
        cout << "Home team: ";
        home.print();
        cout << "Away team: ";
        away.print();
        cout << "Result: " << goalsHome << ":" << goalsAway << endl;
    }

    friend void rematch(Game & game1, Game & game2);
};

void rematch(Game & game1, Game & game2) {
    if (strcmp(game1.home.getName(), game2.away.getName()) == 0
        && strcmp(game1.away.getName(), game2.home.getName()) == 0) {
        int totalHomeGoals = game1.goalsHome + game2.goalsAway;
        int totalAwayGoals = game1.goalsAway + game2.goalsHome;

        if (totalHomeGoals > totalAwayGoals) {
            cout << "WINNER: ";
            game1.home.print();
        } else if (totalHomeGoals < totalAwayGoals) {
            cout << "WINNER: ";
            game2.home.print();
        } else {
            cout << "DRAW MATCH" << endl;
        }
    } else {
        cout << "Teams mismatch" << endl;
    }
}

int main() {
    Team team("Real Madrid", 1890, "Madrid");
    Team team2("Barca", 1899, "Barcelona");

    Game game(team, team2, 4, 2); //copy-constructor of class Team us called IMPLICITLY
    game.print();

    Game game2 (team2, team, 2, 3);
    game.print();

    rematch(game, game2);


    return 0;
}