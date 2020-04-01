#include "cd.h"
#include <iostream>
#include <cstring>


Cd::Cd(const char *s1, const char *s2, int n, double x)
{
	strcpy_s(performer, 51, s1);
	strcpy_s(label, 30, s2);
	selections = n;
	playtime = x;	
}

Cd::Cd(const Cd & d)
{
	strcpy_s(performer, 51, d.performer);
	strcpy_s(label, 30, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performer[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0;

}


void Cd::Report() const
{
	std::cout << "\nNazwa wykonawcy:          " << performer << std::endl;
	std::cout << "nazwa p³yty:              " << label << std::endl;
	std::cout << "Liczba utworow na plycie: " << selections << std::endl;
	std::cout << "Dlugosc plyty w minutach: " << playtime << std::endl;

}

Cd & Cd::operator=(const Cd & d)
{
	if (this == &d)
		return *this;

	//delete performer;
	//delete label;

	strcpy_s(performer, 51, d.performer);
	strcpy_s(label, 30, d.label);

	selections = d.selections;
	playtime = d.playtime;

	return *this;
}

Classic::Classic(const char * s1, const char * s2, const char * s3, int n, double x) : Cd(s1, s2, n, x)
{
	strcpy_s(mainLabel, 51, s3);
}

Classic::Classic(const Classic & e) : Cd(e)
{
	strcpy_s(mainLabel, 51, e.mainLabel);
}

Classic::Classic() :Cd()
{
	mainLabel[0] = '\0';
}

void Classic::Report() const
{	
	Cd::Report();
	std::cout << "Nazwa glownego utworu:   "<< mainLabel <<  std::endl;
}

Classic & Classic::operator=(const Classic & e)
{
	if (this == &e)
		return *this;

	Cd::operator=(e); // kopiowanie danej z klasy bazowej
	strcpy_s(mainLabel, 51, e.mainLabel);
	return *this;
}
