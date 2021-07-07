#include "wine.h"

using std::cout;
using std::cin;
using std::endl;

void Wine::GetBottles()
{
	int y, b;			// year, bottle

//	cout << "Wino: " << label << " dla  " << years << " rocznikow." << endl;
	cout << "Wino: " << Label() << " dla  " << years << " rocznikow." << endl;
	for (int i = 0; i < years; i++)
	{
		cout << "Wprowadz rocznik: ";
		cin >> y;
//		data.first()[i] = y;
		PairInt::first()[i] = y;
		cout << "Wprowadz liczbe butelek tego rocznika: ";
		cin >> b;
//		data.second()[i] = b;
		PairInt::second()[i] = b;		
	}
}

void Wine::Show() const
{

//	cout << "Wino: " << label << endl;
	cout << "Wino: " << Label() << endl;
	cout << "Rocznik " << " Butelki " << endl;
	for (int i = 0; i < years; ++i)
	{
//		cout << data.second()[i] << "	";
		cout << PairInt::second()[i] << "	";
//		cout << data.first()[i] << endl;
		cout << PairInt::first()[i] << endl;
	}
}
