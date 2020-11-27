
#include<iostream>
#include <string>
#include "movie.h"

Movie::Movie(const std::string &nazwa, const std::string &ocena, const int obejrzanych) {
    name = nazwa;
    rating = ocena;
    watched = obejrzanych;

}
/*
 Movie::Movie(const Movie &source){
    name = new std::string;
    *name = source.name;

    rating = new std::string;
    *rating = source.rating;

    watched = new int;
    *watched = source.watched;
 }

  Movie::~Movie(){

  }

  void Movie::display const{
    cout << name << ", " << rating << ", "<< watched << endl;   // Ex Big, PG-13, 2

  }
*/
