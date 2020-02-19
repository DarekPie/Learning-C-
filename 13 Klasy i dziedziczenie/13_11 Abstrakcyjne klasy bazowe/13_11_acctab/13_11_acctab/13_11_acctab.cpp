#include <iostream>
#include "acctabc.h"
const int CLIENTS = 4;
const int LEN = 40;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	AcctABC * p_clients[CLIENTS];

	int i;
	for (i = 0; i < CLIENTS; i++)
	{
		char temp[LEN];
		long tempnum;
		double tempball;
		char kind;
		cout << "Podaj imie i nazwisko klienta: ";
		cin.getline(temp, LEN);
		cout << "Podaj numer rachunku klienta: ";
		cin >> tempnum;
		cout << "Podaj poczatkowy stan konta: ";
		cin >> tempball;
		cout << "Wpisz 1 dla rachunku Brass lub 2 dla rachunku BrassPlus: ";

		while (cin >> kind && (kind != 49 && kind != 50))
			cout << "Wpisz 1 lub 2: ";
		if (kind == 49)
			p_clients[i] = new Brass(temp, tempnum, tempball);
		else
		{
			double tmax, trate;
			cout << "Podaj limit debetu: ";
			cin >> tmax;
			cout << "Podaj stope oprocentowania jako ulamek dziesietny: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempball, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];		//Zwalniamy pamiec
	}
	cout << "Gotowe.\n";

	return 0;
}
