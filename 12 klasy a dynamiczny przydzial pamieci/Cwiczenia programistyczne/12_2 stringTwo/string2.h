#ifndef STRING2_H_
#define STRING1_H_

#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
	char * str;										// wkaznik ciagu
	int len;										// dlugosc ciagu
	static int num_strings;							//liczba obiketow klasy
	static const int CINLIM = 80;					// limit dlugosci ciagu na wejsciu
//		enum { CINLIM = 80 };
//		int CINLIM = 80;					
public:

	//Konstruktory i pozostale metody klasy
	String(const char * s);							// konstruktor
	String();										// konstruktor domyslny
	String(const String&);							// konstruktor kopiujacy
	~String();										// destruktor
	int length() const { return len; }

	//metody przeciazajace operatory
	String & operator=(const String &);
	String & operator=(const char *);
	String operator+(const String &str1, const String &str2);
	char & operator[](int i);
	const char & operator[](int i) const;

	//Funkcje zaprzyjaznione przeciazajace operatory
	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend ostream & operator<<(ostream &os, const String &st);
	friend istream & operator>>(istream &is, String &st);
	

	//metoda statyczna
	static int HowMany();


};



#endif
