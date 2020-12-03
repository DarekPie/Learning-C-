#include <iostream>
#include "Movies.h"
//#include <vector>
#include "Movie.h"

Movies::Movies() {

}

Movies::~Movies()
{
}

bool Movies::add_movie(std::string name, std::string rating, int watched)
{
	for (Movie movie: movies) {
		if (movie.get_name() == name)
			return false;
	}

	Movie tempMovie(name, rating, watched);
	movies.push_back(tempMovie);
	return true;
}

bool Movies::increment_watched(std::string name)
{
	for (Movie &movie : movies) {
		if (movie.get_name() == name){
			movie.increment_watched();
		return true;
		}
	}
	return false;
}

void Movies::display() const
{
	if (movies.size() == 0)
		std::cout << "Sorry, there are no movies\n" << std::endl;
	else {
		std::cout << "\n========================" << std::endl;
		for (const auto &movie : movies)
			movie.display();
		std::cout << "\n========================" << std::endl;
	}
}
