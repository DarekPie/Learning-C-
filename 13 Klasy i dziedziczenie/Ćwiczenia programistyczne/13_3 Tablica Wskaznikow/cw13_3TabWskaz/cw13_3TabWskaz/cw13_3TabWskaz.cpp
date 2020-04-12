#include <iostream>
#include "dma.h"

int main()
{
	using std::cout;
	using std::endl;

	baseDMA shirt("Prtabelly", 8);
	lacksDMA baloon("czerwony", "Blimpo", 4);
	hasDMA map("Merkantor", "Buffaloe Keys", 5);
	cout << shirt << endl;
	cout << baloon << endl;
	cout << map << endl;
	lacksDMA baloon2(baloon);
	hasDMA map2;
	map2 = map;
	cout << baloon2 << endl;
	cout << map2 << endl;

	return 0;
}
