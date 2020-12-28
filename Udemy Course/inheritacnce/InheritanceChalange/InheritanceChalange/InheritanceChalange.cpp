#include <iostream>
#include "Account.h"
#include "Account_Util.h"
#include "Saving_Account.h"
#include "Checking_Account.h"
#include <vector>

using namespace std;
int main()
{
	cout.precision(2);
	cout << fixed;

	//Accounts
	vector<Account> accounts;
	accounts.push_back(Account{});
	accounts.push_back(Account{"Larry"});
	accounts.push_back(Account{ "Moe", 2000 });
	accounts.push_back(Account{"Curly", 5000});

	display(accounts);
	deposit(accounts, 1000);
	withdraw(accounts, 2000);


	//Savings

	vector<Saving_Account> sav_accounts;
	sav_accounts.push_back(Saving_Account{});
	sav_accounts.push_back(Saving_Account{ "Superman" });
	sav_accounts.push_back(Saving_Account{ "Batman", 2000 });
	sav_accounts.push_back(Saving_Account{"Wonderwoman", 5000, 5.0});
	sav_accounts.push_back(Saving_Account{ "Aquaman", 1000, 10.0 });

	display(sav_accounts);
	deposit(sav_accounts, 1000);
	withdraw(sav_accounts, 2000);

	//Checking

	vector<Checking_Account> check_accounts;
	check_accounts.push_back(Checking_Account{});
	check_accounts.push_back(Checking_Account{"Kurk"});
	check_accounts.push_back(Checking_Account{"Spock", 2000});
	check_accounts.push_back(Checking_Account{"Bones", 5000});

	display(check_accounts);
	deposit(check_accounts, 1000);
	withdraw(check_accounts, 2000);


	//Trust
	vector<Trust_Account> trust_accounts;
	trust_accounts.push_back(Trust_Account{});
	trust_accounts.push_back(Trust_Account{"Athos", 10000, 5.0});
	trust_accounts.push_back(Trust_Account{"Porthos", 20000, 4.0});
	trust_accounts.push_back(Trust_Account{"Armies", 30000});
	trust_accounts.push_back(Trust_Account{"Strange", 2000});

	display(trust_accounts);
	deposit(trust_accounts, 1000);
	withdraw(trust_accounts, 3000);

	for (int i = 1; i <= 5; i++)
		withdraw(trust_accounts, 1000);

}
