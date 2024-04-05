//
// Created by Stefan Andonov on 5.4.24.
//
#include<iostream>
#include<cstring>

using namespace std;

//your code here
class Vehicle {
private:
    char registration[9];
    char *driver;
    int location;
    int maxPassengers;
    int kms;

    void copy(const Vehicle &other) {
        this->location = other.location;
        this->maxPassengers = other.maxPassengers;
        this->kms = other.kms;
        strcpy(this->registration, other.registration);
        this->driver = new char[strlen(other.driver) + 1];
        strcpy(this->driver, other.driver);
    }

public:
    Vehicle(char *registration = "", char *driver = "", int location = 1, int maxPassengers = 4) {
        this->location = location;
        this->maxPassengers = maxPassengers;
        this->kms = 0;
        strcpy(this->registration, registration);
        this->driver = new char[strlen(driver) + 1];
        strcpy(this->driver, driver);
    }

    Vehicle(const Vehicle &v) {
        copy(v);
    }

    Vehicle &operator=(const Vehicle &v) {
        if (this != &v) {
            delete[] driver;
            copy(v);
        }

        return *this;
    }

    ~Vehicle() {
        delete[] driver;
    }

    friend ostream &operator<<(ostream &out, const Vehicle &v) {
        //ID: NE1234SA Driver's name: Stefan Passenger capacity: 3 Location: 2 kms driven: 0
        return out << "ID: " << v.registration << " Driver's name: " << v.driver << " Passenger capacity: "
                   << v.maxPassengers << " Location: " << v.location << " kms driven: " << v.kms;
    }

    bool operator==(const Vehicle &rhs) const {
        return strcmp(registration, rhs.registration) == 0;
    }

    bool operator!=(const Vehicle &rhs) const {
        return !(rhs == *this);
    }

    //v+=5;
    Vehicle &operator+=(int kms) {
        this->kms += kms;
        return *this;
    }

    int distance (int area){
        return abs(this->location-area);
    }

    friend class RideApp;
};

class RideApp {
private:
    char name[21];
    Vehicle *vehicles;
    int n;

    void copy(const RideApp &app) {
        this->n = app.n;
        strcpy(this->name, app.name);
        this->vehicles = new Vehicle[this->n]; //default constructor of Vehicle is called
//        strcpy(this->vehicles, app.vehicles); NOO PLEASE NOO GOD NO
        for (int i = 0; i < n; i++) {
            this->vehicles[i] = app.vehicles[i]; //operator = of Vehicle
        }
    }

public:
    RideApp(char *name = "") {
        strcpy(this->name, name);
        n = 0;
        vehicles = new Vehicle[n];
    }

    RideApp &operator+=(const Vehicle &other) {
        for (int i=0;i<n;i++){
            if (vehicles[i]==other){
                return *this;
            }
        }


        Vehicle *tmp = new Vehicle[n + 1]; //n+1 times default constructor
        for (int i = 0; i < n; i++) {
            tmp[i] = vehicles[i]; //n times the operator = from Vehicle is called
        }
        tmp[n++]=other;
        delete [] vehicles;
        vehicles = tmp;

        return *this;
    }

    friend ostream & operator << (ostream & out, const RideApp & app){
        out << app.name << endl;
        if (app.n==0){
            out << "EMPTY" << endl;
        }
        for (int i=0;i<app.n;i++){
            out << app.vehicles[i] << endl;
        }
        return out;
    }

    void addRide(int area, int passengers, int distanceKm){
        int idx = -1; //idx of the closest vehicle to the area `area`
        for (int i=0;i<n;i++){
            if (vehicles[i].maxPassengers>=passengers){
                if (idx == -1){
                    idx=i;
                } else {
                    if (vehicles[i].distance(area)<vehicles[idx].distance(area)){
                        idx = i;
                    } else if (vehicles[i].distance(area)==vehicles[idx].distance(area)) {
                        if (vehicles[i].kms < vehicles[idx].kms){
                            idx=i;
                        }
                    }
                }
            }
        }

        vehicles[idx].location=area;
        vehicles[idx]+=distanceKm;
    }
};

int main() {
    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "CONSTRUCTOR Vehicle" << endl;
        Vehicle vehicle("NE1234SA", "Stefan", 5, 4);
        cout << vehicle << endl;
        cout << "CONSTRUCTOR Vehicle OK" << endl;
    } else if (testCase == 2) {
        cout << "COPY-CONSTRUCTOR Vehicle" << endl;
        Vehicle vehicle = Vehicle("NE1234SA", "Stefan", 5, 4);
        cout << vehicle << endl;
        cout << "COPY-CONSTRUCTOR Vehicle OK" << endl;
    } else if (testCase == 3) {
        cout << "DEFAULT CONSTRUCTOR AND OPERATOR = Vehicle" << endl;
        Vehicle vehicle;
        Vehicle vehicle2("NE1234SA", "Stefan", 5, 4);
        vehicle = vehicle2;
        cout << vehicle << endl;
        cout << "DEFAULT CONSTRUCTOR AND OPERATOR = Vehicle OK" << endl;
    } else if (testCase == 4) {
        cout << "CONSTRUCTOR RideApp" << endl;
        char appName[50];
        cin >> appName;
        RideApp app(appName);
        cout << app;
        cout << "CONSTRUCTOR RideApp OK" << endl;
    } else if (testCase == 5) {
        cout << "RideApp signUpVehicle test" << endl;
        char appName[50];
        cin >> appName;
        RideApp app(appName);
        int n;
        cin >> n;
        char ID[9];
        char name[20];
        int location;
        int capacity;
        for (int i = 0; i < n; i++) {
            cin >> ID >> name >> location >> capacity;
            app += Vehicle(ID, name, location, capacity);
        }
        cout << app;
    } else if (testCase == 6) {
        cout << "RideApp addRide test" << endl;
        char appName[50];
        cin >> appName;
        RideApp app(appName);
        int n;
        cin >> n;
        char ID[6];
        char name[20];
        int location;
        int capacity;
        for (int i = 0; i < n; i++) {
            cin >> ID >> name >> location >> capacity;
            app+=Vehicle(ID, name, location, capacity);
        }
        cin >> n;
        for (int i = 0; i < n; i++) {
            int area, passengers, kms;
            cin >> area >> passengers >> kms;
            app.addRide(area, passengers, kms);
        }

        cout << app;
    }
    return 0;
}
