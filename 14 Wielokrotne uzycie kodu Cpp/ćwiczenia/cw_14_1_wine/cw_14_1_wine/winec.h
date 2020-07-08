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
		PairArray wina;									// podajesz tutaj roczniki wina i liczbe butelek
		int liczbaRocznikow;

	public:
		Wine() : wina(0, 0), liczbaRocznikow(0) {}
		// l - label, y- liczba lat, yr - rocznik, bot - liczba butelek (skladowa)
		Wine(const char * l, int y, const int yr[], const int bot[]);
		// l - label, y- liczba lat
		Wine(const char * l, int y);
		void GetBottles();				// pobiera roczniki i liczbe butelek
		PairArray Label();					// zwraca referencje do nazwy wina




};


#endif // !WINE_H_
