#include "cd.h"
#include <iostream>
#include <cstring>


Cd::Cd(const char *s1, const char *s2, int n, double x)
{
	int lenghPerformer = std::strlen(s1) + 1;
	int lenghLabel = std::strlen(s2) + 1;
	performer = new char[lenghPerformer];
	label = new char[lenghLabel];
	strcpy_s(performer, lenghPerformer, s1);
	strcpy_s(label, lenghLabel, s2);

	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	int lenghPerformer = std::strlen(d.performer) + 1;
	int lenghLabel = std::strlen(d.label) + 1;
	performer = new char[lenghPerformer];
	label = new char[lenghLabel];
	strcpy_s(performer, 51, d.performer);
	strcpy_s(label, 30, d.label);

	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performer = '\0';
	label = '\0';
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

	delete performer;
	delete label;

	int lenghPerformer = std::strlen(d.performer) + 1;
	int lenghLabel = std::strlen(d.label) + 1;
	performer = new char[lenghPerformer];
	label = new char[lenghLabel];
	strcpy_s(performer, lenghPerformer, d.performer);
	strcpy_s(label, lenghLabel, d.label);

	selections = d.selections;
	playtime = d.playtime;

	return *this;
}

Classic::Classic(const char * s1, const char * s2, const char * s3, int n, double x) : Cd(s1, s2, n, x)
{
	int lenghMainLabel = strlen(s3) + 1;
	mainLabel = new char[lenghMainLabel];	
	strcpy_s(mainLabel, lenghMainLabel, s3);
}

Classic::Classic(const Classic & e) : Cd(e)
{
	int lenghMainLabel = strlen(e.mainLabel) + 1;
	mainLabel = new char[lenghMainLabel];
	strcpy_s(mainLabel, lenghMainLabel, e.mainLabel);
}

Classic::Classic() : Cd()
{
	mainLabel = '\0';
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << "Nazwa glownego utworu:   " << mainLabel << std::endl;
}

Classic & Classic::operator=(const Classic & e)
{
	if (this == &e)
		return *this;

	Cd::operator=(e); // kopiowanie danej z klasy bazowej
	int lenghMainLabel = strlen(e.mainLabel) + 1;
	mainLabel = new char[lenghMainLabel];
	strcpy_s(mainLabel, lenghMainLabel, e.mainLabel);
	return *this;
}
