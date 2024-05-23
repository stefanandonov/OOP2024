#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

enum Type {
    academic, roman
};

class Book {
private:
    char title[30];
    int id;
    static int TOTAL;
    const static int ID_init;
    Type type;
    float price;
public:
    Book() {}

    Book(const char *title, int type, float price) {
        strcpy(this->title, title);
        TOTAL++;
        id = ID_init + TOTAL;
        this->type = (Type) type;
        this->price = price;
    }

    friend ostream &operator<<(ostream &out, const Book &b) {
        out << b.id << " - " << b.title << " ";
        if (b.type == academic)
            out << "academic ";
        else
            out << "roman ";
        out << b.price << endl;
        return out;
    }

    Book &operator+=(float amount) {
        price += amount;
        return *this;
    }

    bool isSame(const Book &b) {
        return id == b.id;
    }

    Type getType() {
        return type;
    }

    float getPrice() {
        return price;
    }
};

int Book::TOTAL = 0;
const int Book::ID_init = 777550;

class BookStore {
private:
    char name[20];
    vector<Book> books;
public:
    BookStore(const char *name = "") {
        strcpy(this->name, name);
    }

    BookStore(const BookStore &b) {
        strcpy(this->name, b.name);
        this->books = b.books;
    }

    BookStore &operator=(const BookStore &b) {
        if (this != &b) {

            strcpy(this->name, b.name);
            this->books=b.books;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &out, const BookStore &b) {
        out << b.name << endl;
        for (int i = 0; i < b.books.size(); i++) {
            out << b.books[i];
        }
        return out;
    }

    bool operator>(const BookStore &b) {
        return this->books.size() > b.books.size();
    }

    BookStore &operator+=(const Book &a) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].isSame(a)) {
                return *this;
            }
        }
        books.push_back(a);
        return *this;
    }

    void createMarketPrice() {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getType() == academic) {
                float fee = books[i].getPrice() * 0.05f;
                books[i] += fee;
            } else {
                float fee = books[i].getPrice() * 0.03f;
                books[i] += fee;
            }
        }
    }

    ~BookStore() {
//
    }
};

BookStore best(BookStore *books, int n) {
    BookStore b = books[0];
    for (int i = 1; i < n; i++) {
        if (books[i] > b) {
            b = books[i];
        }
    }
    return b;
}

int main() {
    int testCase;
    cin >> testCase;
    if (testCase == 0) {
        cout << "TESTING BOOK CONSTRUCTOR" << endl;
        Book book1("Object-oriented programming", 0, 2300);
        Book book2("Discrete Mathematics", 0, 1800);
        Book book3("Crime and punishment", 1, 950);
        cout << "TEST PASSED" << endl;
    } else if (testCase == 1) {
        cout << "TESTING BOOK OPERATOR <<" << endl;
        Book book1("Object-oriented programming", 0, 2300);
        Book book2("Discrete Mathematics", 0, 1800);
        Book book3("Crime and punishment", 1, 950);
        cout << book1;
        cout << book2;
        cout << book3;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 2) {
        cout << "TESTING BOOK OPERATOR +=" << endl;
        Book book1("Object-oriented programming", 0, 2300);
        Book book2("Discrete Mathematics", 0, 1800);
        Book book3("Crime and punishment", 1, 950);
        cout << book1;
        cout << book2;
        cout << book3;
        book1 += 200;
        book2 += 300;
        book3 += 150;
        cout << "===== INCREASE =====" << endl;
        cout << book1;
        cout << book2;
        cout << book3;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 3) {
        cout << "TESTING BOOKSTORE CONSTRUCTOR" << endl;
        BookStore bookStore1("The Book Cellar");
        cout << bookStore1;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 4) {
        cout << "TESTING BOOKSTORE OPERATOR += and <<" << endl;
        Book book1("Object-oriented programming", 0, 2300);
        Book book2("Discrete Mathematics", 0, 1800);
        Book book3("Crime and punishment", 1, 950);
        BookStore bookStore1("The Book Cellar");
        bookStore1 += book1;
        bookStore1 += book2;
        bookStore1 += book3;
        cout << bookStore1;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 5) {
        cout << "TESTING BOOKSTORE OPERATOR += and <<" << endl;
        Book book1("Object-oriented programming", 0, 2300);
        Book book2("Discrete Mathematics", 0, 1800);
        Book book3("Crime and punishment", 1, 950);
        BookStore bookStore1("The Book Cellar");
        bookStore1 += book1;
        bookStore1 += book2;
        bookStore1 += book3;
        cout << bookStore1;
        bookStore1 += book1;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 6) {
        cout << "TESTING BOOKSTORE COPY-CONSTRUCTOR and OPERATOR =" << endl;
        Book book1("Object-oriented programming", 0, 2300);
        Book book2("Discrete Mathematics", 0, 1800);
        Book book3("Crime and punishment", 1, 950);
        Book book4("Anna Karenina", 1, 1200);
        Book book5("Calculus 1", 0, 1320);
        BookStore bookStore1("The Book Cellar");
        bookStore1 += book1;
        bookStore1 += book2;
        bookStore1 += book3;
        BookStore bookStore2(bookStore1);
        BookStore bookStore4;
        {
            BookStore bookStore3("Word Wizardry Books");
            bookStore3 += book4;
            bookStore3 += book5;
            bookStore4 = bookStore3;
        }
        cout << bookStore2;
        cout << bookStore4;
        cout << "TEST PASSED" << endl;

    } else if (testCase == 7) {
        cout << "TESTING BOOKSTORE OPERATOR > " << endl;
        Book book1("Object-oriented programming", 0, 2300);
        Book book2("Discrete Mathematics", 0, 1800);
        Book book3("Crime and punishment", 1, 950);
        Book book4("Anna Karenina", 1, 1200);
        Book book5("Calculus 1", 0, 1320);
        BookStore bookStore1("The Book Cellar");
        bookStore1 += book1;
        bookStore1 += book2;
        bookStore1 += book3;
        BookStore bookStore3("Word Wizardry Books");
        bookStore3 += book4;
        bookStore3 += book5;
        if (bookStore1 > bookStore3) {
            cout << "TEST PASSED" << endl;
        } else {
            cout << "TEST FAILED" << endl;
        }
    } else if (testCase == 8) {
        cout << "TESTING METHOD createMarketPrice()" << endl;
        char name[30], name1[30];
        int type, numofBookStores, numberOfBooks;
        float price;
        cin >> numofBookStores;
        cin.ignore();
        BookStore bookStores[10];
        for (int i = 0; i < numofBookStores; i++) {
            cin.getline(name, 20);
            bookStores[i] = BookStore(name);
            cin >> numberOfBooks;
            cin.ignore();
            Book books[10];
            for (int j = 0; j < numberOfBooks; j++) {
                cin >> name1 >> type >> price;
                cin.ignore();
                books[j] = Book(name1, type, price);
                bookStores[i] += books[j];
            }
        }
        for (int i = 0; i < numofBookStores; i++) {
            cout << bookStores[i];
            cout << "CREATED MARKET PRICES" << endl;
            bookStores[i].createMarketPrice();
            cout << bookStores[i];
        }

    } else if (testCase == 9) {
        cout << "TESTING METHOD best()" << endl;
        char name[30], name1[30];
        int type, numofBookStores, numberOfBooks;
        float price;
        cin >> numofBookStores;
        cin.ignore();
        BookStore bookStores[10];
        for (int i = 0; i < numofBookStores; i++) {
            cin.getline(name, 20);
            bookStores[i] = BookStore(name);
            cin >> numberOfBooks;
            cin.ignore();
            Book books[10];
            for (int j = 0; j < numberOfBooks; j++) {
                cin >> name1 >> type >> price;
                cin.ignore();
                books[j] = Book(name1, type, price);
                bookStores[i] += books[j];
            }
        }
        cout << best(bookStores, numofBookStores);
    }
    return 0;
}