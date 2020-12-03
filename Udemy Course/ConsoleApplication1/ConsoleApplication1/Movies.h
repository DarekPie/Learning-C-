#ifndef MOVIES_H_
#define MOVIES_H_
#include <vector>
#include <string>
#include "Movie.h"

class Movies {
	private:
		std::vector<Movie> movies;

	public:
		Movies();
		~Movies();
		bool add_movie(std::string name, std::string rating, int watched);
		bool increment_watched(std::string name);
		void display() const;
};

#endif // !1

