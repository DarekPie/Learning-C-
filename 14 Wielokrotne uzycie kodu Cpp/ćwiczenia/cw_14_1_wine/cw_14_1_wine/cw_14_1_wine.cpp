#include <iostream>
#include "winec.h"
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Podaj nazwe wina: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Podaj liczbe rocznikow: ";
	int yrs;
	cin >> yrs;

	cout << " Podaj nazwe: " << lab << " liczba rocznikow: " << yrs << endl;


}

