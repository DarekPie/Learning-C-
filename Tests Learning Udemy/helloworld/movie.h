#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#include<iostream>
#include <string>

class Movie {
    private:
        std::string name;
        std::string rating;         // G, PG, PG-13, R
        int watched;
    public:
        Movie(const std::string &nazwa, const std::string &ocena, const int obejrzanych);
   /*     Movie(const Movie &source);
        ~Movie();

        std::string get_name() {return name;}
        std::string get_rating(){return rating; }
        int get_watched() {return watched;}

        void set_name(std::string imie) {name = imie;}
        void set_rating(std::string ocena) {rating = ocena;}
        int set_watched(int ogladanych) {watched = ogladanych;}

        void increment_watched(){++watched;}
        void display() const;       // Ex Big, PG-13, 2

*/
};

#endif // MOVIE_H_INCLUDED
