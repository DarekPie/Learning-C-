#pragma once

#include <string>
#include <valarray>
#include <iostream>

template <typename T1, typename T2>
class Pair
{
	private:
		T1 a;
		T2 b;

	public:
		Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
		Pair() {}
		Pair(const Pair<T1, T2> & p) {}
		T1 & first();
		T2 & second();
		T1 first() const { return a; }
		T2 second() const { return b; }
};

template <typename T1,  typename T2>
T1 & Pair<T1, T2>::first()
{
	return a;
}

template <typename T1, typename T2>
T2 & Pair<T1, T2>::second()
{
	return b;
}


class Wine : private std::string, private Pair<std::valarray<int>, std::valarray<int>>
{
	private:
		typedef std::valarray<int> ArrayInt;
		typedef Pair<ArrayInt, ArrayInt> PairInt;
		int years;

	public:
		Wine() {}
		Wine(const char * l, int y, const int yr[], const int bat[]) : std::string(l), years(y), PairInt(ArrayInt(yr, y), ArrayInt(bat, y)) {}
		Wine(const char * l, int y) : std::string(l), years(y), PairInt(ArrayInt(y), ArrayInt(y)) {}
		// nie uzywamy konstruktora kopiujacego, uzywamy domyœlnego 
		void GetBottles();
		const std::string & Label() const { return (const std::string &) (*this); }  
		const int sum() const { return PairInt::second().sum(); }
		void Show() const;
};