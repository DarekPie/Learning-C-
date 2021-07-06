#include "winec.h"
#include <iostream>
#include <cstring>
#include <string>
#include <valarray>

using std::cout;
using std::endl;
using std::cin;

Wine::Wine() : label("none"), years(0), data(ArrayInt(0), ArrayInt(0))
{
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : label(l), years(y), data(ArrayInt(yr, y), ArrayInt(bot, y))
{
}


Wine::Wine(const char * l, int y) : label(l), years(y), data(ArrayInt(y), ArrayInt(y))
{
}

void Wine::Show() const
{
	//cout << "liczbaRocznikow " << liczbaRocznikow << endl;
	//cout << "wineName " << wineName << endl;

	//cout << "Wino: " << wineName << endl;
	//cout << "\tRocznik\t\tButelki\n";
	//for (int i = 0; i < liczbaRocznikow; i++)
	//	cout << "\t" << wina.first()[i] << "\t\t" << wina.second()[i] << endl;

	cout << "Wino: " << label << endl;
	cout << "Rocznik " << " Butelki " << endl;
	for (int i = 0; i < years; ++i)
	{
		cout << data.second()[i] << "	";
		cout << data.first()[i] << endl;
	}

}

void Wine::GetBottles()
{
	//cout << "Podaj dane o winie " << wineName << " dla " << liczbaRocznikow << " rocznikow:\n";
	//
	//for (int i = 0; i < liczbaRocznikow; i++)
	//{
	//	cout << "Podaj rocznik: ";
	//	cin >> wina.first()[i];
	//	cout << "Podaj liczbe butelek: ";
	//	cin >> wina.second()[i];
	//}

	int y, b;			// year, bottle

	cout << "Wino: " << label << " dla  " << years << " rocznikow." << endl;
	for (int i = 0; i < years; i++)
	{
		cout << "Wprowadz rocznik: ";
		cin >> y;
		data.first()[i] = y;
		cout << "Wprowadz liczbe butelek tego rocznika: ";
		cin >> b;
		data.second()[i] = b;
	}

}

int Wine::sum() const
{
	//int suma = 0;
	//for (int i = 0; i < liczbaRocznikow; i++)
	//	suma += wina.second()[i];

	//return suma;

	return data.second().sum();
}