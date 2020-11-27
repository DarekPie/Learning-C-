#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

#include<iostream>
#include <string>
#include <vector>
#include "movie.h"


class Movies {
    private:
    std::vector<Movie> movies;

    public:
        Movies();
        ~Movies();

        bool increment_watched(std::string name;);
        void display() const;

};

#endif // MOVIES_H_INCLUDED
