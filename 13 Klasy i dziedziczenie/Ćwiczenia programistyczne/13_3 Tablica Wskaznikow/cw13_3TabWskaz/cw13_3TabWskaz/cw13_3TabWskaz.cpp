#include <iostream>
#include "dma.h"
const int THINGS = 4;
const int LEN = 50;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	ABCdma *teamsTable[THINGS];
	//char nazwa[LEN];
	//		cout << "Podaj nazwe przedmiotu " << endl;
	//		cin.getline(nazwa, LEN);
	//		cout << nazwa; 

	int i;
	for (int i = 0; i < THINGS; i++)
	{
		// 1. co chesz podać ? Czy to ma kolor ? "1" czyli lacksDMA czy to ma styl ? "2" hasDMA w innym wypadku baseDMA
		int choice;
		int ocena;
		char nazwa[LEN];
		char kolor[LEN];
		char styl[LEN];
		
		cout << "\nPodaj nazwe przedmiotu " << endl;
		cin.getline(nazwa, LEN);
		cout << "Podaj jego oecene " << endl;
		cin >> ocena;
		
		cout << "Jesli ma kolor wcisnij 1, jeśli ma styl wcisnij 2, jesli zadne z powyzszych to wcisnij 0,\n "
			<< "jesli chesz wyjsc wcisnij Q/q" << endl;


		while (cin >> choice && (choice != 0 && choice != 1 && choice != 2))
		{
			cout << "Wpisz 1, 2, lub 0\n";
		}

			switch (choice)
			{
			case 1:
				cout << "Podaj kolor przedmiotu " << endl;
				cin >> kolor;
				teamsTable[i] = new lacksDMA(kolor, nazwa, ocena);
				break;

			case 2:
				cout << "Podaj styl przedmiotu " << endl;
				cin >> styl;
				teamsTable[i] = new hasDMA(styl, nazwa, ocena);
				break;

			case 0:
				cout << "Typ baseDMA ";
				teamsTable[i] = new baseDMA(nazwa, ocena);

				break;

			}

			while (cin.get() != '\n')
			{
				continue;
			}

	}

	for (int i = 0; i < THINGS; i++)
	{
		teamsTable[i]->View();
		cout << endl;
	}

	for (int i = 0; i < THINGS; i++)
	{
		delete teamsTable[i];
	}

	cout << "Gotowe\n";

	return 0;
}
