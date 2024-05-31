#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

void wtf() {
    ofstream fout("input.txt");

    string fname, lname;
    int points;
    string line;

    while (getline(std::cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff1() {
    ifstream fin("output1.txt");
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}

void rff2() {
    ifstream fin("output2.txt");
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}






class Book {
private:
    string title;
    string author;
    int published;
public:

    Book(const string &title = "", const string &author = "", int published = 1900) : title(title), author(author),
                                                                                      published(published) {}

    ~Book() {

    }

    Book &operator=(const Book &b) {

        published = b.published;
        title = b.title;
        author = b.author;
        return *this;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    int getYear() {
        return published;
    }

        bool operator==(const Book &rhs) const {
        return title == rhs.title &&
               author == rhs.author &&
               published == rhs.published;
    }

    bool operator!=(const Book &rhs) const {
        return !(rhs == *this);
    }
};

class BookAlreadyExistsException {
private:
    Book b;

public:
    BookAlreadyExistsException(Book name) {
        this->b = name;
    }

    void message() {
        cout << "Book \"" << b << "\" already exists in the library" << endl;
    }
};


class Library {
private:
    string name;
    Book *collection;
    int size;
public:
    Library(string &n) {
        size = 0;
        name = n;
        collection = new Book[0];
    }

    ~Library() {
//        delete[] name;
    }

    Library &operator+=(const Book &b) {
        for (int i = 0; i < size; i++) {
            if (collection[i] == b) {
                throw BookAlreadyExistsException(b);
            }
        }

        Book *tmp = new Book[size + 1];
        for (int i = 0; i < size; i++) {
            tmp[i] = collection[i];
        }
        tmp[size++] = b;
        delete[] collection;
        collection = tmp;
        return *this;
    }


    friend ostream &operator<<(ostream &out, Library &lib) {
        out << lib.name << endl;
        for (int i = 0; i < lib.size; i++)
            out << lib.collection[i] << endl;
        return out;
    }

    int getBookCount() {
        return size;
    }

    Book *getBooksByAuthor(string author, int &count) {
        int countTmp = 0;
        for (int i = 0; i < size; i++) {
            if (collection[i].getAuthor() == author) {
                countTmp++;
            }
        }

        if (countTmp == 0) {
            return nullptr;
        }

        Book *matchingBooks = new Book[countTmp];
        int index = 0;
        for (int i = 0; i < size; i++) {
            if (collection[i].getAuthor() == author) {
                matchingBooks[index++] = collection[i];
            }
        }

        count = countTmp;
        return matchingBooks;
    }
};

int main() {


    wtf();


    //YOUR CODE STARTS HERE


    ifstream ifs("input.txt");

    int books;
    string libraryName;

    getline(ifs, libraryName);

    ifs >> books;

    ifs.ignore();

    string name, a;
    int year;

    Library library(libraryName);
    for (int i = 0; i < books; i++) {
        getline(ifs, name);
        getline(ifs, a);
        ifs >> year;
        ifs.ignore();
        try {
            library += Book(name, a, year);
        }
        catch (BookAlreadyExistsException &e) {
            e.message();
        }
    }

    ifs.close();

    ofstream ofs1("output1.txt");

    ofs1 << library;

    ofs1.close();

    //DO NOT MODIFY THIS PART

    string author;
    getline(std::cin, author);



    //DO NOT MODIFY THE PART ABOVE, CONTINUE AFTER THIS COMMENT

    ofstream ofs2("output2.txt");

    int n;
    Book *collection = library.getBooksByAuthor(author, n);

    if (collection == nullptr) {
        ofs2 << "None" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            ofs2 << collection[i] << endl;
        }
    }


    ofs2.close();


    //YOUR CODE ENDS HERE
    rff1();
    cout << "Books written by " << author << " are: " << endl;
    rff2();

    return 0;
}



