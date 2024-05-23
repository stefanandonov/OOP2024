//
// Created by Stefan Andonov on 16.5.24.
//

#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

class EmbgLengthNotValidException {
private:
    string embg; //not valid embg
public:
    EmbgLengthNotValidException(const string &embg) : embg(embg) {

    }

    void message() {
        cout << "EMBG " << embg << " must be 13 digits long" << endl;
    }
};

class EmbgFormatNotValidException {
private:
    string embg; //not valid embg
public:
    EmbgFormatNotValidException(const string &embg) : embg(embg) {

    }

    void message() {
        cout << "EMBG " << embg << " must contain only digits" << endl;
    }
};

class Citizen {
    string name;
    string embg;
public:
    Citizen(const string &name, const string &embg) {

        if (embg.length() != 13) {
            throw EmbgLengthNotValidException(embg);
        }

        for (int i = 0; i < embg.length(); i++) {
            if (!isdigit(embg[i])) {
                throw EmbgFormatNotValidException(embg);
            }
        }

        this->embg = embg;
        this->name = name;
    }
};

int main() {
    string name;
    string embg;

    cin >> name >> embg;

    try {
        Citizen c(name, embg);
        cout << "Citizen created" << endl;
    } catch (EmbgLengthNotValidException &e) {
        e.message();
    } catch (EmbgFormatNotValidException &e) {
        e.message();
    }

    return 0;
}