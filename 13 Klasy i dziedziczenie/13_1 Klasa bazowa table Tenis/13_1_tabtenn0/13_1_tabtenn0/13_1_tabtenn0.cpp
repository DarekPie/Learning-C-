#include <iostream>
#include "tabtenn0.h"

int main()
{
	using std::cout;
	TableTennisPlayer player1("Jacek", "Pogodny", true);
	TableTennisPlayer player2("Teresa", "Bogatko", false);
	player1.Name();
	if (player1.HasTable())
		cout << ": posiada stol .\n";
	else
		cout << ": nie posiada stolu.\n";
	player2.Name();
		if (player2.HasTable())
			cout << ": posiada stol .\n";
		else
			cout << ": nie posiada stolu.\n";

	return 0;
}

