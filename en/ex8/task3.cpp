//
// Created by Stefan Andonov on 26.4.24.
//

#include<iostream>

using namespace std;

class User {
    char *username;
    char *companyName;
    int position;

    void copy(const User &u) {
        this->username = new char[strlen(u.username) + 1];
        strcpy(this->username, u.username);
        this->companyName = new char[strlen(u.companyName) + 1];
        strcpy(this->companyName, u.companyName);
        this->position = u.position;
    }

public:
    User(char *username = "", char *companyName = "", int position = 0) {
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
        this->companyName = new char[strlen(companyName) + 1];
        strcpy(this->companyName, companyName);
        this->position = position;
    }

    User(const User &u) {
        copy(u);
    }

    User &operator=(const User &u) {
        if (this != &u) {
            delete[] username;
            delete[] companyName;
            copy(u);
        }
        return *this;
    }

    ~User() {
        delete[] username;
        delete[] companyName;
    }

    char *getUsername() const {
        return username;
    }

    void setUsername(char *username) {
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
    }

    char *getCompanyName() const {
        return companyName;
    }

    void setCompanyName(char *companyName) {
        this->companyName = new char[strlen(companyName) + 1];
        strcpy(this->companyName, companyName);
    }

    int getPosition() const {
        return position;
    }

    void setPosition(int position) {
        this->position = position;
    }


    friend ostream &operator<<(ostream &os, const User &user) {
        return os << "Username: " << user.username
                  << " Company name: " << user.companyName
                  << " Position: " << user.position;
    }

    friend istream &operator>>(istream &in, User &user) {
        return in >> user.username >> user.companyName >> user.position;
    }

    bool operator==(User &u) {
        return strcmp(this->username, u.username) == 0;
    }
};

class Group {
protected:
    string name;
    User *users;
    int size;
public:
    Group(const string &name = "") : name(name) {
        this->size = 0;
        this->users = new User[this->size];
    }

    virtual void addMember(User &u) {
        for (int i = 0; i < size; i++) {
            if (users[i] == u) {
                return;
            }
        }


        User *tmp = new User[size + 1];
        for (int i = 0; i < size; i++) {
            tmp[i] = users[i];
        }
        tmp[size] = u;
        size++;
        delete[] users;
        users = tmp;
    }

    double averagePositions() const {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += users[i].getPosition();
        }
        return sum / size;
    }

    virtual double rating() const {
        //(10 - average level of the members' positions) * number of members / 100
        return (10.0 - averagePositions()) * size / 100.0;
    }

    /*
     *  Group: FINKI
        Members: 14
        Rating: 1
        Members list:
        1. Username: dejan Company name: FINKI Position: 1
        2. Username: ivan Company name: FINKI Position: 1
        3. Username: ana Company name: FINKI Position: 1
        4. Username: nevena Company name: FINKI Position: 1
        5. Username: ivica Company name: FINKI Position: 2
        6. Username: gjorgji Company name: FINKI Position: 2
        7. Username: kate Company name: FINKI Position: 3
        8. Username: hristina Company name: FINKI Position: 3
        9. Username: bobi Company name: FINKI Position: 3
        10. Username: tenev Company name: FINKI Position: 4
        11. Username: stojmenski Company name: FINKI Position: 4
        12. Username: stefan Company name: FINKI Position: 5
        13. Username: vlatko Company name: FINKI Position: 5
        14. Username: dimitar Company name: FINKI Position: 5
     * */

    friend ostream &operator<<(ostream &out, const Group &group) {
        out << "Group: " << group.name << endl;
        out << "Members: " << group.size << endl;
        out << "Rating: " << group.rating() << endl;
        out << "Members list:" << endl;
        for (int i = 0; i < group.size; i++) {
            out << i + 1 << ". " << group.users[i] << endl;
        }
        return out;
    }

};

class PrivateGroup : public Group {
    static int CAPACITY;
    const static double COEF;
public:
    PrivateGroup(const string &name = "") : Group(name) {}

    void addMember(User &u) override {
        if (size==CAPACITY){
            return;
        }
        Group::addMember(u);
    }

    double rating() const override {
        //(10 - average level of the positions of the members) * (number of members / group capacity) * private group coefficient
        return (10.0 - averagePositions()) * ((double)size / CAPACITY) * COEF;
    }

    static void setCapacity (int c) {
        CAPACITY = c;
    }
};

int PrivateGroup::CAPACITY = 10;
const double PrivateGroup::COEF = 0.8;



int main() {

    cout << "INTEGRATION TEST" << endl;
    char name[50];
    int nGroups;
    cin >> nGroups;
    Group **groups = new Group *[nGroups];
    for (int i = 0; i < nGroups; i++) {
        int type;
        cin >> type;
        cin >> name;
        if (type == 1) { //normal group
            groups[i] = new Group(name);
        } else { //private group
            groups[i] = new PrivateGroup(name);
        }
        int nUsers;
        cin >> nUsers;
        for (int j = 0; j < nUsers; j++) {
            User u;
            cin >> u;

            groups[i]->addMember(u);

        }
    }

    cout << "BEFORE CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }
    PrivateGroup::setCapacity(15);
    cout << "AFTER CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }

}