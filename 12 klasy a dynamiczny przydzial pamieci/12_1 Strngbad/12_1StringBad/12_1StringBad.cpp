
#include "strngbad.h"
#include <iostream>
using std::cout;

void callme1(StringBad &);		// obiekt przekazywany przez referencje
void callme2(StringBad);		// obiekt przekazywany przez wartość

int main()
{
	using std::endl;

	StringBad headline1("Spiew skowronka - nowe zwrotki usypiaja?");
	StringBad headline2("Kogutom smierc");
	StringBad sports("Brzask wypada z ligi, skandal sedziowski");

	cout << "Z ostatniej chwili: " << headline1 << endl;
	cout << "Temat dnia: " << headline2 << endl;
	cout << "Wiadomosci sporowe: " << sports << endl;

	callme1(headline1);
	cout << "Z ostatniej chwili: " << headline1 << endl;

	callme2(headline2);
	cout << "Temat dnia: " << headline2 << endl;

	cout << "Inicjalizacja obiektu ciagu innym obiektowm:\n";
	StringBad sailor = sports;
	cout << "Z kraju: " << sailor << endl;

	cout << "Przypisanie obiektu do innego boeiktu:\n";
	StringBad knot;
	knot = headline1;
	cout << "Ze swiata: " << knot << endl;
	cout << "Koniec main()\n";

}


void callme1(StringBad & rsb)
{
	cout << "Obiekt ciagu przekazywany przez referencje:\n";
	cout << "	\"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	cout << "Obiekt ciagu przekazywany przez wartosc:\n";
	cout << "	\"" << sb << "\"\n";
}