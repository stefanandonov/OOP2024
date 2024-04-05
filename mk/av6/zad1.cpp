#include<iostream>
#include<cstring>

using namespace std;

class Vehicle {
private:
    char id[9];
    char *driver;
    int location;
    int maxPassengers;
    double kms;

    void copy(const Vehicle &v) {
        strcpy(this->id, v.id);
        this->driver = new char[strlen(v.driver) + 1];
        strcpy(this->driver, v.driver);
        this->location = v.location;
        this->maxPassengers = v.maxPassengers;
        this->kms = v.kms;
    }

public:
    Vehicle(char *id = "", char *driver = "", int location = 1, int maxPassengers = 4) {
        strcpy(this->id, id);
        this->driver = new char[strlen(driver) + 1];
        strcpy(this->driver, driver);
        this->location = location;
        this->maxPassengers = maxPassengers;
        this->kms = 0;
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
        return out << "ID: " << v.id << " Driver's name: " << v.driver << " Passenger capacity: " << v.maxPassengers
                   << " Location: " << v.location << " kms driven: " << v.kms;
    }

//    friend ostream &operator<<(ostream &os, const Vehicle &vehicle) {
//        os << "ID: " << vehicle.id << " Driver's name: " << vehicle.driver << " Location: " << vehicle.location
//           << " Pass: " << vehicle.maxPassengers << " kms: " << vehicle.kms;
//        return os;
//    }

    bool operator==(const Vehicle &v) {
        return strcmp(this->id, v.id) == 0;
//        return this->id == v.id;
    }

    Vehicle &operator+=(double kms) {
        this->kms += kms;
        return *this;
    }

    int distance(int area) {
        return abs(this->location - area);
    }

    friend class RideApp;

};


class RideApp {
private:
    char name[21];
    Vehicle *vehicles;
    int n;

    void copy(const RideApp &app) {
        strcpy(this->name, app.name);
        this->n = app.n;
        vehicles = new Vehicle[this->n];
        for (int i = 0; i < n; i++) {
            vehicles[i] = app.vehicles[i];
        }
    }


public:
    RideApp(char *name = "") {
        strcpy(this->name, name);
        vehicles = new Vehicle[0];
        n = 0;
    }

    RideApp &operator+=(const Vehicle &other) {
        for (int i = 0; i < n; i++) {
            if (vehicles[i] == other) {
                return *this;
            }
        }

        Vehicle *tmp = new Vehicle[n + 1]; //default constructor od Vehicle
        for (int i = 0; i < n; i++) {
            tmp[i] = vehicles[i]; //operator = od Vehicle
        }
        tmp[n++] = other; //operator = od Vehicle
        delete[] vehicles;
        vehicles = tmp;

        return *this;
    }


    friend ostream &operator<<(ostream &out, const RideApp &app) {
        out << app.name << endl;
        if (app.n == 0) {
            out << "EMPTY" << endl;
        }

        for (int i = 0; i < app.n; i++) {
            out << app.vehicles[i] << endl;
        }
        return out;
    }

    void addRide(int area, int passengers, int distanceKm) {
        bool first = true;
        int idx = -1;
        int minDistance;

        for (int i = 0; i < n; i++) {
            if (vehicles[i].maxPassengers >= passengers) {
                if (first) {
                    first = false;
                    idx = i;
                    minDistance = vehicles[i].distance(area);
                } else {
                    if (vehicles[i].distance(area) < minDistance) {
                        idx = i;
                        minDistance = vehicles[i].distance(area);
                    }
                }
            }
        }

        vehicles[idx]+=distanceKm;
        vehicles[idx].location = area;


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
            app += Vehicle(ID, name, location, capacity);
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
