//
// Created by Stefan Andonov on 20.3.24.
//


#include<iostream>

using namespace std;

class LibraryMember {
private:
    char name[50];
    int id;
public:
    LibraryMember(char *name, int id) {
        strcpy(this->name, name);
        this->id = id;
    }

    const char *getName() const {
        return name;
    }

    int getId() const {
        return id;
    }
};

class Book {
private:
    char name[50];
    char author[50];
    bool isAvailable;
    char rentedBy [50];
public:
    Book(char *name = "book", char *author = "Stefan", bool isAvailable = true) {
        strcpy(this->name, name);
        strcpy(this->author, author);
        this->isAvailable = isAvailable;
        strcpy(this->rentedBy, "NONE");
    }

    Book(const Book &other) {
        cout << "COPY CONST BOOK" << endl;
        strcpy(this->name, other.name);
        strcpy(this->author, other.author);
        this->isAvailable = other.isAvailable;
        strcpy(this->rentedBy, other.rentedBy);
    }

    void print() {
        cout << name << " (" << author << ") " << (isAvailable ? "YES " : "NO ") << (!isAvailable ? rentedBy : "") << endl;
    }

    const char *getName() const {
        return name;
    }

    const char *getAuthor() const {
        return author;
    }

    bool getIsAvailable() const {
        return isAvailable;
    }

    void changeAvailability (){
        isAvailable = !isAvailable;
    }

    void setRentedBy(const char * rentedBy){
        strcpy(this->rentedBy, rentedBy);
    }
};

class Library {
    char name[50];
    Book books[300]; //300 times default constructor of Book will be called
    int count;
public:
    Library(char *name = "City Library") {
        strcpy(this->name, name);
        count = 0;
    }

    Library(const Library &other) {

        strcpy(this->name, other.name);
        this->count = other.count;
//        strcpy(this->books, other.books); NO GOD NO!
        for (int i = 0; i < count; i++) {
            this->books[i] = other.books[i];
        }
    }

    void addBook(Book book) {
        if (count < 300) {
            books[count] = book;
            ++count;
        } else {
            cout << "Capacity filled" << endl;
        }
    }

    void print() {
        cout << name << endl;
        cout << count << endl;
        for (int i = 0; i < count; i++) {
            books[i].print();
        }
    }

    friend bool checkOutBook(LibraryMember member, Library & library, char *title, char *author);
};


bool checkOutBook(LibraryMember member, Library & library, char *title, char *author) {
    for (int i = 0; i < library.count; i++) {
        if (strcmp(library.books[i].getAuthor(), author) == 0
            && strcmp(library.books[i].getName(), title) == 0 && library.books[i].getIsAvailable()){

            library.books[i].changeAvailability();
            library.books[i].setRentedBy(member.getName());
            return true;
        }
    }

    return false;
}

int main() {
    Library library("Stefan's library");
    Book book("Angels and Demons", "Dan Brown", true);
    Book book2("DaVinci Code", "Dan Brown", true);

    library.addBook(book);
    library.addBook(book2);

    library.print();

    LibraryMember member("Owner", 1);

    checkOutBook(member, library, "Angels and Demons", "Dan Brown");

    library.print();

//    book.print();
    return 0;
}