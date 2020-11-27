
#include <iostream>
#include "Movie.h"

int main()
{
    std::cout << "Hello World!\n";

	Movie film("Bogowie Wojny", "PG", 3);
	film.display();

	Movie kolejny(film);
	kolejny.display();3,3


}

