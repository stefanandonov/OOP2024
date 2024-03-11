//
// Created by Stefan Andonov on 7.3.24.
//

#include<iostream>

using namespace std;

class Email {
private:
    char sender[40];
    char receiver[40];
    char subject[200];
    char body[3000];
public:
    //2in1 nescafe
    Email(char *_sender = "stefan.andonov@finki.ukim.mk",
          char *_receiver = "info@finki.ukim.mk",
          char *_subject = "NO SUBJECT",
          char *_body = "NO BODY") {
        strcpy(sender, _sender);
        strcpy(receiver, _receiver);
        strcpy(subject, _subject);
        strcpy(body, _body);
    }

    void display() {
        cout << "Sender:\t\t\t" << sender << endl;
        cout << "Receiver:\t\t" << receiver << endl;
        cout << "Subject:\t\t" << subject << endl;
        cout << "Message" << endl;
        cout << "----------------------------------------" << endl;
        cout << body << endl;
        cout << "----------------------------------------" << endl;
    }
};

bool validateEmail(char *email) {

    char *atEmail = strchr(email, '@');

    if (atEmail == nullptr) {
        return false;
    }

    char *firstDotPointer = strchr(atEmail, '.');

    return firstDotPointer != nullptr;

//    int atIdx = -1;
//    for (int i = 0; i < strlen(email); i++) {
//        if (email[i] == '@') {
//            atIdx = i;
//            break;
//        }
//    }
//
//    if (atIdx == -1) {
//        return false;
//    }
//
//    for (int i = atIdx + 1; i < strlen(email); i++) {
//        if (email[i]=='.'){
//            return true;
//        }
//    }
//
//    return false;
}

int main() {
    //5 ways to create an email using the above constructor
//    Email email;
//    Email email2 ("gjorgj@finki.ukim.mk");
//    Email email3 ("gjorgj@finki.ukim.mk", "ivan@finki.ukim.mk");
//    Email email4 ("gjorgj@finki.ukim.mk", "ivan@finki.ukim.mk", "subject nekojsi");
//    Email email5 ("gjorgj@finki.ukim.mk", "ivan@finki.ukim.mk", "subject", "ova e poraka so konstruktor so 4 argumenti");
//    email.display();
//    email2.display();
//    email3.display();
//    email4.display();
//    email5.display();

    char sender[40];
    char receiver[40];
    char subject[200];
    char body[3000];

    cin.getline(sender, 40);
    cin.getline(receiver, 40);
    cin.getline(subject, 200);
    cin.getline(body, 200);


    if (validateEmail(sender)) {
        if (validateEmail(receiver)) {
            Email email(sender, receiver, subject, body);
            email.display();
        } else {
            cout << receiver << " is not a valid email address" << endl;
        }
    } else {
        cout << sender << " is not a valid email address" << endl;
    }

    return 0;
}