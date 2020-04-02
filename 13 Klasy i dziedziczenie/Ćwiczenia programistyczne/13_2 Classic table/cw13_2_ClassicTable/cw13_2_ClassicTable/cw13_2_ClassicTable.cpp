#include <iostream>
#include "cd.h"
using namespace std;



void Bravo(const Cd & disk)
{
	disk.Report();
}


int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Sonata fortepianowa B-dur, Fantazja C-moll", "Alfred Brendel", "Philips", 2, 57.17);

	Cd *pcd = &c1;

	cout << "Bezposrednie uzycie obiektu:\n";
	c1.Report();
	c2.Report();
	pcd = &c2;
	pcd->Report();


	cout << "\n\nWyolwanie funkcji z argumentem w postaci referncji do typu Cd:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "\n\nTest Przypisania: ";
	Classic copy;
	copy = c2;
	copy.Report();

	return 0;
}


