
#include "cow.h"
#include <iostream>

int main()
{
	Cow first;
	Cow second("Druga", "Trawka", 50);
	Cow third = second;

	first.ShowCow();
	second.ShowCow();
	third.ShowCow();



	return 0;
}
