#include <cstring>
#include "string2.h"
#include <cctype>
using std::cin;
using std::cout;
using std::ostream;
using std::istream;

//inicjalizacja statycznej skladowej klasy
int String::num_strings = 0;

//metoda statyczna
int String::HowMany() { return num_strings; }

//metody klasy
String::String(const char * s)				// kontruuje obiekt String z ciagu C
{
	len = std::strlen(s);					// ustawia dlugosc ciagu
	str = new char[len + 1];				// przydzia� pami�ci
//	std::strcpy(str, s);					// inicjalizacja wskaznika ciagu
	strcpy_s(str, len + 1, s);
	num_strings++;							// aktualizacja licznika obiektow
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';							// domy�lny ci�g obiekt�w klasy
	num_strings++;
}

String::String(const String & st)
{
	num_strings++;						// aktualizacja skladowej statycznej
	len = st.len;							// ta sama dlugosc ciagu
	str = new char[len + 1];				// przydzial pamieci
//	std::strcpy(str, st.str);				// skopiowanie ciagu
	strcpy_s(str, len + 1, st.str);
}

String::~String()
{
	--num_strings;							// koniecznie
	delete[] str;							// koniecznie
}
// Metody przeciazajace operatory
// Przypisywanie obiektu klast String do innego obiektu tej klasy
String & String::operator=(const String & st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	//	std::strcpy(str, st.str);
	strcpy_s(str, len + 1, st.str);
	return *this;
}

// Przypisanie ciagu C do obiektu klast String
String & String::operator=(const char * s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	//	std::strcpy(str, s);
	strcpy_s(str, len + 1, s);
	return *this;
}

String operator + (String const &c1, String const &c2)
{


	String ZwrotSumy; 
	delete[] ZwrotSumy.str;
	ZwrotSumy.len = c1.len + c2.len;
	ZwrotSumy.str = new char[ZwrotSumy.len + 1];
	strcpy_s(ZwrotSumy.str, c1.len + 1, c1.str);			// (char, int, char)
	//    strncat_s( dest, _countof(dest), "dachshunds", 15 );
	strncat_s(ZwrotSumy.str, ZwrotSumy.len + 1, c2.str, c2.len + 1);				// (char, char, int)

//	std::cout << ZwrotSumy.str << std::endl;
	return ZwrotSumy;
}



// pelny dostep do znakow ciagu (dla obiektow zwyklych)
char & String::operator[](int i)
{
	return str[i];
}

//dostep (do odczytu do znakow ciagu (dla obiektow const)
const char  & String::operator[](int i) const
{
	return str[i];
}

bool operator<(const String &st1, const String &st2)
{
	return(std::strcmp(st1.str, st2.str) < 0);
}

bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

// Wyprowadzenie ciagu na wyj�cie
ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}

//Wczytywanie ciagu z wejscia (uproszczone)
istream & operator>>(istream & is, String & st)
{
	char temp[80];
	is.get(temp, 80);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

void String::stringlow()
{
	//for (int i = 0; i < len; i++)
	//	putchar(tolower(str[i]));
	//std::cout << str;


	char * newstring;
	newstring = new char[len + 1];
	strcpy_s(newstring, len + 1, str);

	for (int i = 0; i < len; i++)
		newstring[i] = tolower(newstring[i]);

	strcpy_s(str, len + 1, newstring);

}

char * String::stringlow(const char * s)
{

	int dlugosc = std::strlen(s);
	char * newstring;
	newstring = new char[dlugosc + 1];
	strcpy_s(newstring, dlugosc + 1, s);

	for (int i = 0; i < len; i++)
		newstring[i] = tolower(newstring[i]);

//	strcpy_s(str, len + 1, newstring);

	return newstring;
}



void String::stringup()
{
	char * newstring;
	newstring = new char[len + 1];
	strcpy_s(newstring, len + 1, str);

	for (int i = 0; i < len; i++)
		newstring[i] = toupper(newstring[i]);

	strcpy_s(str, len + 1, newstring);
}

int String::has(const char * s)
{
	int howMany = 0;
	char * newstring;
	newstring = new char[len + 1];

	strcpy_s(newstring, len + 1, str);
	newstring = stringlow(newstring);
	s = stringlow(s);

	for (int i = 0; i < len; i++)
	{
		if (newstring[i] == s[0])
			howMany++;
	}

	return howMany;
}