//
// Created by Stefan Andonov on 21.3.24.
//

#include<iostream>

using namespace std;

class LibraryMember {
private:
    int id;
    char name[50];
public:
    LibraryMember(int id = 0, char *name = "Stefan") {
        this->id = id;
        strcpy(this->name, name);
    }

    friend class Book;
};

class Book {
private:
    char title[50];
    char author[50];
    bool isAvailable;
    LibraryMember rentedBy;
public:
    Book(char *title = "no name", char *author = "no author", bool isAvailable = true) {
        strcpy(this->title, title);
        strcpy(this->author, author);
        this->isAvailable = isAvailable;
    }

    Book(const Book &other) {
        strcpy(this->title, other.title);
        strcpy(this->author, other.author);
        this->isAvailable = other.isAvailable;
    }

    void print() {
        cout << title << " (" << author << ") " << (isAvailable ? "YES" : "NO") << " " << (!isAvailable ? rentedBy.name : "") <<  endl;
    }

    friend class Library;

    const char *getTitle() const {
        return title;
    }

    const char *getAuthor() const {
        return author;
    }

    bool getIsAvailable() const {
        return isAvailable;
    }

    const LibraryMember &getRentedBy() const {
        return rentedBy;
    }

    void setIsAvailable (bool isAvailable) {
        this->isAvailable = isAvailable;
    }

    void setRentedBy (LibraryMember & member){
        this->rentedBy = member;
    }
};

class Library {
private:
    char name[50];
    Book books[1000]; //1000 pati default constructor na Book
    int n;
public:
    Library(char *name = "Brakja Miladinovci") {
        strcpy(this->name, name);
        n = 0;
    }

    void addBook(Book &book) {
        if (n == 1000) {
            cout << "Capacity full" << endl;
        } else {
            books[n] = book;
            ++n;
        }
    }

    void print() {
        cout << name << endl;
        for (int i = 0; i < n; i++) {
            books[i].print();
        }
    }

    friend void checkOutBook(LibraryMember member, Library & library, char *title, char *author);
};


void checkOutBook(LibraryMember member, Library & library, char *title, char *author) {
    for (int i = 0; i < library.n; i++) {
        if (strcmp(library.books[i].getTitle(), title) == 0 && strcmp(library.books[i].getAuthor(), author) == 0 &&
            library.books[i].getIsAvailable()) {
            library.books[i].setRentedBy(member);
            library.books[i].setIsAvailable(false);
        }
    }
}

int main() {

    Book b("Angels and demons", "Dan Brown", true);
    Book b1("DaVinci Code", "Dan Brown", true);
    Book b2("Lost symbol", "Dan Brown", true);
    Book b3("Inferno", "Dan Brown", true);

    Library library("Stefan's library");

    LibraryMember member; //id = 0, name = Stefan default constructor

    library.addBook(b);
    library.addBook(b1);
    library.addBook(b2);
    library.addBook(b3);

    library.print();

    checkOutBook(member, library, "Lost symbol", "Dan Brown");

    library.print();
    return 0;
}