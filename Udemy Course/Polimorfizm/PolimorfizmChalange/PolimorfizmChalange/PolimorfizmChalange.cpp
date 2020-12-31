#include <iostream>
#include "Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Saving_Account.h"
#include "Trust_Account.h"


using namespace std;

int main()
{
	Checking_Account frank{ "Frank", 5000 };
	cout << frank << endl;

	Account *trust = new Trust_Account("James");
	cout << *trust << endl;

	Account *p1 = new Checking_Account("Larry", 10000);
	Account *p2 = new Saving_Account("Moe", 1000);
	Account *p3 = new Trust_Account("Curly");

	vector<Account *> accounts{ p1, p2, p3 };

	display(accounts);
	deposit(accounts, 1000);
	withdraw(accounts, 2000);

	display(accounts);
	delete p1;
	delete p2;
	delete p3;
	return 0;

}

