//
// Created by Stefan Andonov on 1.3.24.
//

#include<iostream>

using namespace std;

struct Movie {
    char title[100];
    double rating;
    char genre[40];

    void read() {
        //The_Godfather 9.2 Drama
        cin >> title >> rating >> genre;
    }

    void print() {
        cout << title << " " << rating << endl;
    }
};

struct StreamingPlatform {
    char name[40];
    Movie movies[30];
    int nOfMovies;

    void read() {
        /*
         *  Netflix 3
            The_Godfather 9.2 Drama
            Inception 8.8 Sci-Fi
            Pulp_Fiction 8.9 Crime
         * */

        cin >> name >> nOfMovies;
        for (int i = 0; i < nOfMovies; i++) {
            movies[i].read();
        }
    }

    void print() {
        /*
         *  Netflix
            The_Godfather 9.2
            Inception 8.8
            Pulp_Fiction 8.9
         * */
        cout << name << endl;
        for (int i = 0; i < nOfMovies; i++) {
            movies[i].print();
        }
    }

    int numberOfMoviesFrom(char *genre) {
        int counter = 0;
        for (int i = 0; i < nOfMovies; i++) {
            if (strcmp(movies[i].genre, genre) == 0) {
                ++counter;
            }
        }
        return counter;
    }
};


void showBestStreamingService(StreamingPlatform *sp, int size, char *genre) {
    StreamingPlatform max = sp[0];
    for (int i = 0; i < size; i++) {
        if (sp[i].numberOfMoviesFrom(genre) > max.numberOfMoviesFrom(genre)){
            max = sp[i];
        }
    }

    cout << "Best streaming service is: " << max.name << endl;
}

int main() {

    /*
     *  2
        Netflix 3
        The_Godfather 9.2 Drama
        Inception 8.8 Sci-Fi
        Pulp_Fiction 8.9 Crime
        Hulu 2
        Fight_Club 8.8 Drama
        Forrest_Gump 8.8 Drama
        Drama
     * */
    StreamingPlatform sp[10];

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        sp[i].read();
    }

    char genre[40];
    cin >> genre;


    for (int i = 0; i < n; i++) {
        sp[i].print();
    }

    showBestStreamingService(sp,n,genre);
}