#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <iostream>
#include <string>

class Account
{
	private:
		static constexpr const char *def_name = "Unnamed Account";
		static constexpr double def_balance = 0.0;

	protected:
		std::string name;
		double balance;

	public:
		Account(std::string = def_name, double balance = def_balance);
		bool deposit(double amount);
		bool withdraw(double amount);

		friend std::ostream &operator<<(std::ostream &os, const Account &accObj);
};


#endif // !ACCOUNT_H_
