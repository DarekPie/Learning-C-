#include "Saving_Account.h"

Saving_Account::Saving_Account(std::string name, double balance, double int_rate)
	: Account{name, balance}, int_rate{int_rate}
{
}

bool Saving_Account::deposit(double amount)
{
	amount += amount * (int_rate / 100);
	return Account::deposit(amount);
}

bool Saving_Account::withdraw(double amount)
{
	return Account::withdraw(amount);
}

void Saving_Account::print(std::ostream & os) const
{
	os.precision(2);
	os << std::fixed;
	os << "[Saving_Account: " << name << ": " << balance << ", " << int_rate << "]";
}
