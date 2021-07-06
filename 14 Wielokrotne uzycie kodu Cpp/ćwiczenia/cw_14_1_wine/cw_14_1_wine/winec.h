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
	Pair(const Pair<T1, T2> & p);
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
		
//ALIASY ! Pair<std::valarray<int>, std::valarray<int>> wina ->  Pair<ArrayInt, ArrayInt> wina -> PairArray wina ALIASY!!!
		std::string label;			// nazwa wina
		PairArray data;				//  liczba poszczegolnych rocznikow
		int years;

	public:
		Wine(); //: wineName( "brak" ), wina(), liczbaRocznikow(0) {}

		// l - label, y- liczba lat, yr - rocznik, bot - liczba butelek (skladowa)
		// valarray<double> v4(gpa, 4); - gpa- tablica 4 elementow zainicjalizowana za pomoca czterech pierwszych elementow tablicy gpa
		Wine(const char * l, int y, const int yr[], const int bot[]);	//: wineName(l), liczbaRocznikow(y), wina(ArrayInt(yr, y), ArrayInt(bot, y)) {}

		// l - label, y- liczba roczników danego wina
		// vallarray<int> v2(8); - Tablica liczb calkowitych, 8 elementow. 
		Wine(const char * l, int y);							//: wineName(l), liczbaRocznikow(y), wina(ArrayInt(y), ArrayInt(y)) {}
//		Wine(const Wine & w);

		void Show() const;
		void GetBottles();				// pobiera roczniki i liczbe butelek prosi uzytkownika o podanie ich, 
		const std::string & Label() const { return label; }			// zwraca referencje do nazwy wina
		int sum() const;



};


#endif // !WINE_H_
