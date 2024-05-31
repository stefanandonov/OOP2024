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
    int year;
public:
    Book(const string &title = "", const string &author = "", int year = 1900) : title(title), author(author),
                                                                                 year(year) {}

    friend ostream &operator<<(ostream &os, const Book &book) {
        os << book.title << " " << book.author << " " << book.year;
        return os;
    }

    bool operator==(const Book &rhs) const {
        return title == rhs.title &&
               author == rhs.author &&
               year == rhs.year;
    }

    bool operator!=(const Book &rhs) const {
        return !(rhs == *this);
    }

    friend class Library;
};

class BookAlreadyExistsException {
private:
    Book b;
public:
    BookAlreadyExistsException(const Book &b) {
        this->b = b;
    }

    void message() {
        cout << "Book \"" << b << "\" already exists in the library" << endl;

    }


};

class Library {
private:
    string name;
    int n;
    Book *books;
public:
    Library(const string &name = "") {
        this->name = name;
        n = 0;
        books = new Book[n];
    }

    Library &operator+=(const Book &b) {
        for (int i = 0; i < n; i++) {
            if (books[i] == b) {
                throw BookAlreadyExistsException(b);
            }
        }


        Book *tmp = new Book[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = books[i];
        }
        tmp[n] = b;
        ++n;
        delete[] books;
        books = tmp;

        return *this;
    }

    friend ostream &operator<<(ostream &out, const Library &l) {
        out << l.name << endl;
        for (int i = 0; i < l.n; i++) {
            out << l.books[i] << endl;
        }
        return out;
    }

    ~Library() {
        delete[] books;
    }

    Book *getBooksByAuthor(string & author, int & numberFound){
        numberFound = 0;

        for (int i=0;i<n;i++){
            if (books[i].author==author){
                ++numberFound;
            }
        }

        if (numberFound==0){
            return nullptr;
        }

        Book * result = new Book[numberFound];
        int j=0;

        for (int i=0;i<n;i++){
            if (books[i].author==author){
                result[j] = books[i];
                j++;
            }
        }

        return result;

    }
};


int main() {


    wtf();


    //YOUR CODE STARTS HERE

    ifstream in("input.txt");

    string libraryName;
    getline(in, libraryName);

    int n;
    in >> n;

    in.ignore();

    Library library(libraryName);

    string title, auth;
    int year;
    for (int i = 0; i < n; i++) {
        getline(in, title);
        getline(in, auth);
        in >> year;
        in.ignore();

//        cout << title << " " << auth << " " << year << endl;
        Book b(title, auth, year);
        try {
            library += b;
        } catch (BookAlreadyExistsException &e) {
            e.message();
        }
    }

    in.close();

    ofstream out("output1.txt");
    out << library;
    out.close();



    //DO NOT MODIFY THE NEXT PART

    string author;
    getline(std::cin, author);

    //DO NOT MODIFY THE PART ABOVE, CONTINUE AFTER THIS COMMENT

    out = ofstream("output2.txt");
    int num;
    Book * result = library.getBooksByAuthor(author, num);

    if (num==0){
        out << "None" << endl;
    } else {
        for (int i=0;i<num;i++){
            out << result[i] << endl;
        }
    }

    out.close();


    //YOUR CODE ENDS HERE
    rff1();
    cout << "Books written by " << author << " are: " << endl;
    rff2();

    return 0;
}



