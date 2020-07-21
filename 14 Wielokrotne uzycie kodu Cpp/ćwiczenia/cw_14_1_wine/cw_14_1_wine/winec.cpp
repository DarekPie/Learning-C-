#include "winec.h"
#include <iostream>
#include <cstring>
#include <string>
#include <valarray>

using std::cout;
using std::endl;
using std::cin;




void Wine::Show()
{
	//cout << "liczbaRocznikow " << liczbaRocznikow << endl;
	//cout << "wineName " << wineName << endl;

	cout << "Wino: " << wineName << endl;
	cout << "\tRocznik\t\tButelki\n";
	for (int i = 0; i < liczbaRocznikow; i++)
		cout << "\t" << wina.first()[i] << "\t\t" << wina.second()[i] << endl;

}

void Wine::GetBottles()
{
	cout << "Podaj dane o winie " << wineName << " dla " << liczbaRocznikow << " rocznikow:\n";
	
	for (int i = 0; i < liczbaRocznikow; i++)
	{
		cout << "Podaj rocznik: ";
		cin >> wina.first()[i];
		cout << "Podaj liczbe butelek: ";
		cin >> wina.second()[i];
	}
}

int Wine::sum()
{
	int suma = 0;
	for (int i = 0; i < liczbaRocznikow; i++)
		suma += wina.second()[i];

	return suma;
}