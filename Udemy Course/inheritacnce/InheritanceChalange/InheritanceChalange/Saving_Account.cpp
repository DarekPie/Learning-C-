#include "Saving_Account.h"

Saving_Account::Saving_Account(std::string name, double balance, double int_rate) 
	: Account {name, balance}, int_rate{int_rate}
{
}

bool Saving_Account::deposit(double amount)
{
	amount += amount * (int_rate / 100);
	return Account::deposit(amount);
}

std::ostream & operator<<(std::ostream & os, const Saving_Account & account)
{
	os << "[Saving_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "]";
	return os;
}
