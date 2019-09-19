#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
using std::ostream;
using std::istream;
#include "cow.h"					

Cow::Cow()
{
	name[0] = '\0';
	int len = 2;
	hobby = new char[len];
	hobby[0] = '\0';
	weight = 0;
}


Cow::Cow(const char* nm, const char* ho, double wt)
{

	strcpy_s(name, 21, nm);

	int len = std::strlen(ho);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, ho);

	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strcpy_s(name, 21, c.name);

	int len = std::strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, c.hobby);

	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow & Cow::operator=(const Cow& c)
{

	if (this == &c)
		return *this;
	delete name;
	delete[] hobby;
	
	strcpy_s(name, 21, c.name);

	int len = std::strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, c.hobby);

	weight = c.weight;

	return *this;


}

void Cow::ShowCow() const
{
	cout << "Name " << name << std::endl;
	cout << "Hobby: " << hobby << std::endl;
	cout << "Weigh " << weight << std::endl;
}