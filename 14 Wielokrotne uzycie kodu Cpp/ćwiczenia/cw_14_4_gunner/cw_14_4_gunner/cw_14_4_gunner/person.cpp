#include "person.h"
#include <iostream>
//#include <string>

void Person::Data() const
{
	std::cout << firstname << std::endl;
	std::cout << lastname << std::endl;
}

void Person::Show() const
{
	Data();
}

void Person::Set()
{
	std::cout << "Enter first name: ";
	std::cin >> firstname;
	std::cout << "Enter lastname: ";
	std::cin >> lastname;
}
