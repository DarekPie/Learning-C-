#ifndef CHECKING_ACCOUNT_H_
#define  CHECKING_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"

class Checking_Account : public Account
{
	private:
		static constexpr const char *def_name = "Unnamed Chacking account";
		static constexpr double def_balance = 0.0;
		static constexpr double per_check_fee = 1.5;
	public:
		Checking_Account(std::string name = def_name, double balance = def_balance);
		bool withdraw(double amount);

		friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
};

#endif // !CHECKING_ACCOUNT_H_

