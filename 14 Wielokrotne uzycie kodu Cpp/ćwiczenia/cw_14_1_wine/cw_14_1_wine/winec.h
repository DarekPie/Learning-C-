#ifndef WINE_H_
#define WINE_H_

#include <iostream>
#include <string>
#include <valarray>


template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;

public:
	T1 & first();
	T2 & second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
	Pair() {}
};

template<class T1, class T2>
T1 & Pair<T1, T2>::first()
{
	return a;
}

template<class T1, class T2>
T2 & Pair<T1, T2>::second()
{
	return b;
}




class Wine
{
	private:
		typedef std::valarray<int> ArrayInt;
		typedef Pair<ArrayInt, ArrayInt> PairArray;
		std::string wineName;
//ALIASY ! Pair<std::valarray<int>, std::valarray<int>> wina ->  Pair<ArrayInt, ArrayInt> wina -> PairArray wina ALIASY!!!
		PairArray wina;									// podajesz tutaj roczniki wina i liczbe butelek
		int liczbaRocznikow;

	public:
		Wine() : wineName( "brak" ), wina(), liczbaRocznikow(0) {}
		// l - label, y- liczba lat, yr - rocznik, bot - liczba butelek (skladowa)
		// valarray<double> v4(gpa, 4); - gpa- tablica 4 elementow zainicjalizowana za pomoca czterech pierwszych elementow tablicy gpa
		Wine(const char * l, int y, int yr[], int bot[])	: wineName(l), liczbaRocznikow(y), wina(ArrayInt(yr, y), ArrayInt(bot, y)) {}

		// l - label, y- liczba roczników danego wina
		// vallarray<int> v2(8); - Tablica liczb calkowitych, 8 elementow. 
		Wine(const char * l, int y)							: wineName(l), liczbaRocznikow(y), wina(ArrayInt(y), ArrayInt(y)) {}

		void Show();
		void GetBottles();				// pobiera roczniki i liczbe butelek prosi uzytkownika o podanie ich, 
		PairArray Label();					// zwraca referencje do nazwy wina
		//



};


#endif // !WINE_H_
