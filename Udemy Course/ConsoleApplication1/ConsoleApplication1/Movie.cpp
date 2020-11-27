
#include<iostream>
#include <string>
#include "Movie.h"

Movie::Movie(const std::string &nazwa, const std::string &ocena, const int obejrzanych) {
	name = nazwa;
	rating = ocena;
	watched = obejrzanych;

}

 Movie::Movie(const Movie &source){
	//name = new std::string;
	//*name = source.name;

	//rating = new std::string;
	//*rating = source.rating;

	//watched = new int;
	//*watched = source.watched;

	 name = source.name;
	 rating = source.rating;
	 watched = source.watched;
 }

  Movie::~Movie(){

  }
  
  void Movie::display() const {
	std::cout << name << ", " << rating << ", "<< watched << std::endl;   // Ex Big, PG-13, 2

  }

