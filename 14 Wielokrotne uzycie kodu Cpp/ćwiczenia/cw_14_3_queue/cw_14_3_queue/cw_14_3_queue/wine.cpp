#include "wine.h"

using std::cout;
using std::cin;
using std::endl;

void Wine::GetBottles()
{
	int y, b;			//rok, butelki
	std::cout << "Enter" << Label() << " date for " << years << " year(s)" << std::endl;
	for (int i = 0; i < years; ++i)
	{
		cout << "Enter years: ";
		cin >> y;
		PairInt::first()[i] = y;
	}
}

void Wine::Show() const
{
}
