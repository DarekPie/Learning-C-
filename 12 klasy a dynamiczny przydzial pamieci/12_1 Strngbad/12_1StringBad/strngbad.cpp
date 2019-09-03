#include <cstring>
#include "strngbad.h"
using std::cout;

// inicjalizacja statycznej skladowej klasy
int StringBad::num_strings = 0;

//metody klasy

StringBad::StringBad(const char *s)
{
	len = std::strlen(s);		// ustalenie rozmiaru
	str = new char[len + 1];	// przydzial odpowiedniej ilosci pamieci
//	std::strcpy(str, s);		// inicjalizacja wksaznika
	strcpy_s(str, len + 1, s);
	num_strings++;

	cout << num_strings << " : \"" << str << "\" - obiekt utworzony.\n";	//komunikat diagnostyczny
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
//	std::strcpy(str, "C++");		// ciag domyslny
	strcpy_s(str, len+1, "C++");
	num_strings++;
	
	cout << num_strings << " : \"" << str << "\" - obiekt utworzony.\n";
}

StringBad::~StringBad()		// niezbedny teraz destruktor
{
	cout << "\"" << str << "\" - obiket usuniety, ";
	--num_strings;
	cout << "sa jeszcze " << num_strings << ".\n";
	delete[] str;
}

std::ostream & operator << (std::ostream & os, const StringBad & st)
{
	os << st.str;
	return os;
}