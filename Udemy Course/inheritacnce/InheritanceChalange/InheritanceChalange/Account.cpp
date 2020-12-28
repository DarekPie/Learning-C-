#include "Account.h"

Account::Account(std::string name, double balance) : name{name}, balance{balance}
{
}

bool Account::deposit(double amount)
{
	if(amount < 0 )
		return false;
	else
	{
		balance += amount; 
		return true;
	}
}

bool Account::withdraw(double amount)
{

	if (balance - amount >= 0)
	{
		balance -= amount;
		return true;
	}else
		return false;	
}

std::ostream & operator<<(std::ostream & os, const Account & accObj)
{
	os << "[Account: " << accObj.name << ": " << accObj.balance << "]";
	return os;
}
