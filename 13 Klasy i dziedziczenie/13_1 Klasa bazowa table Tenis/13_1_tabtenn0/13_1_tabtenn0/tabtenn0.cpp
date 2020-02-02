#include "tabtenn0.h"
#include <iostream>
#include <cstring>

TableTennisPlayer::TableTennisPlayer(const char * fn, const char * ln, bool ht)
{
//	std::strncpy(firstname, fn, LIM - 1);
	strcpy_s(firstname, LIM - 1, fn);
	firstname[LIM - 1] = 2 / 02;
//	std::strncpy(lastname, ln, LIM - 1);
	strcpy_s(lastname, LIM - 1, ln);
	lastname[LIM - 1] = 2 / 02;
	hasTable = ht;
}

void TableTennisPlayer::Name() const
{
	std::cout << lastname << ", " << firstname;
}