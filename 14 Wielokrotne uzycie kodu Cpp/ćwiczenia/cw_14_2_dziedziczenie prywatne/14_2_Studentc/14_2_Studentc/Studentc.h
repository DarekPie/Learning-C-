#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
	typedef std::valarray<double> ArrayDb;							// typdef - dzieki czemu nie trzeba uzywac wszedzie w kodzie std::valarray<double>
	std::string name;			// Obiekt zawierany
	ArrayDb scores;				// Obiekt zawierany
	//Prywatna metoda do wyswietlania wynikow
	std::ostream & arr_out(std::ostream &os) const;
public:
	Student() : name("Brak"), scores() {}
	Student(const std::string & s) : name(s), scores() {}
	explicit Student(int n) : name("Brak"), scores(n) {}		// explicit powoduje wychwyceniu wyjatku zwiazanego z utworzeniem tablicy pustych obiektow
	Student(const std::string & s, int n) : name(s), scores(n) {}				// ? 
	Student(const std::string & s, const ArrayDb & a) : name(s), scores(a) {}				// score - tablica wartosci typu ArrayDb wiec double
	Student(const char * str, const double * pd, int n) : name(str), scores(pd, n) {}		//score - tablica n elementow zainicjalizowana 																						//za pomoc czterech pierwszych elementow tablicy pd
	~Student() {}

	double Average() const;
	const std::string & Name() const;
	double &operator[](int i);
	double operator[](int i) const;

	//Funkcje zaprzyjaznione
	//Wejscie
	friend std::istream &operator>>(std::istream & is, Student & stu);		// 1 slowo
	friend std::istream &getline(std::istream & is, Student & stu);			// 1 linia

	//Wyjscie 
	friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};

#endif
