#include <iostream>
#include "port.h"

int main()
{
	Port gallo("Gallo", "lekko brazowy", 20);
	gallo.Show();
	cout << gallo;

	VitagePort szlachetny("Inaliano", 20, "Szlachetny", 1920);
	szlachetny.Show();
	cout << szlachetny;
	return 0;
}
