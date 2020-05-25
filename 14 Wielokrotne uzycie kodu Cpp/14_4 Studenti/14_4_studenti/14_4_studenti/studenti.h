#ifndef STUDENTI_H_
#define STUDENTI_H_

#include <iostream>
#include <valarray>
#include <string>

class Student : private std::string, private std::valarray<double>			// Dziedziczenie prywatne podwójne!
{
	private:
		typedef std::valarray<double> ArrayDb;
		//Prywatna metdoa do wyswietlenia ocen
		std::ostream & arr_out(std::ostream & o) const;

	public:
		Student()											: std::string("Brak"), ArrayDb() {}
		Student(const std::string & s)						: std::string(s), ArrayDb() {}
		Student(int n)										: std::string("Brak"), ArrayDb(n) {}
		Student(const std::string & s, int n)				: std::string(s), ArrayDb(n) {}
		Student(const std::string & s, const ArrayDb & a)	: std::string(s), ArrayDb(a) {}
		Student(const char * str, const double * pd, int n) : std::string(str), ArrayDb(pd, n) {}
		~Student() {}
		double Avarege() const;
		double & operator[](int i);
		double operator[](int i) const;
		const std::string  & Name() const;
	//Funkcje zaprzyjaznione
		//Obsluga wejscia
		friend std::istream & operator>>(std::istream & is, Student & stu);			// 1 slowo
		friend std::istream & getline(std::istream & is, Student & stu);			// 1 linia
		//Obsluga wyjscia
		friend std::ostream & operator<<(std::ostream & os, const Student & stu);
		
}

#endif // !STUDENTI_H_

