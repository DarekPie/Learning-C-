#include <iostream>
#include "stock2.h"
const int STKS = 4;

int main()
{
	using std::cout;
	using std::ios_base;

	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("BurakPOL", 200, 2.0),
		Stock("GruzPOL", 130, 3.25),
		Stock("FutroPOL", 60, 6.5)
	};

	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);

	cout << "Posiadane walory:\n";
	int st;
	for (st = 0; st < STKS; st++)
	{
		stocks[st].show();
	}

	Stock top = stocks[0];
	for (st = 0; st < STKS; st++)
	{
		top = top.topval(stocks[st]);
	}

	cout << "\nNajbardziej wartosciowe udzialy:\n";
	top.show();

	return 0;
}
