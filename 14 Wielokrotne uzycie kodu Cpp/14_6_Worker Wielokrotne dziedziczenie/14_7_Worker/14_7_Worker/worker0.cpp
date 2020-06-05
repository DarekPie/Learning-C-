#include "worker.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

//Metody kalsy worker

//Potrzebna implementacja destruktora wirtualnego, nawet jesli jest czysto wirtualny 
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
	cout << "Imie i nazwisko: " << fullname << "\n";
	cout << "Numer identyfiacyjny: " << id << "\n";
}

//Metody klasy waiter
void Waiter::Set()
{
	Worker::Set();
	cout << "Podaj poziom elegancji kelnera: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

void Waiter::Show() const
{
	cout << "Kategoria: kelner\n"; 
	Worker::Show();
	cout << "Elegancja: " << panache << "\n";
}

//Metody klasy singer
const char * Singer::pv[] = { "inny", "alt", "kontralt", "sopran", "bas", "baryton", "tenor" };   // dodanie const ze wzgledu na char ktory jest static

void Singer::Set()
{
	Worker::Set();
	cout << "Podaj numer skali glosu piosenkarza:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 3)
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
	cout << "Kategoria piosenkarz\n";
	Worker::Show();
	cout << "Skala glosu: " << pv[voice] << endl;
}
