#include "worker0.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//Metody klasy worker

//Potrzebna implementacja destruktora wirtualnego, nawet jesli jest on czysto wirtualny
Worker::~Worker() {}

void Worker::Set()
{
	cout << "Podaj imie i nazwisko pracownika: "; 
	getline(cin, fullname);
	cout << "Podaj numer identyfikacyjny pracownika: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void Worker::Show() const
{
	cout << "Imie i nazwisko: " << fullname << '\n';
	cout << "Numer identyfikacyjny: " << id << '\n';
}


//Metody klasy Wiater
void Waiter::Set()
{
	Worker::Set();
	cout << "Podaj poziom elegancji kelnera: ";
	cin >> panache;
	while (cin.getline() != '\n')
		continue;
}

void Waiter::Show() const
{
	cout << "Kategoria : kelner\n";
	Worker::Show();
	cout << "Elegancja: " << panache << "\n";
}

//Metody klasy Singer
char * Singer::pv[] = { "inny", "alt", "kontralt", "sopran", "bas", "baryton", "tenor" };

void Singer::Set()
{
	Worker::Set();
	cout << "Podaj numer skali glosu piosenkarza:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}

void Singer::Show() const
{

}