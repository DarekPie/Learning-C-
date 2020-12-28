#ifndef  TRUST_ACCOUNT_H_
#define TRUST_ACCOUNT_H_
#include "Saving_Account.h"

class Trust_Account : public Saving_Account
{
	private:
		static constexpr const char *def_name = "Unnamed Trust Account";
		static constexpr double def_balance = 0.0;
		static constexpr double def_int_rate = 0.0;
		static constexpr double bonus_amount = 50.0;
		static constexpr double bonus_treshold = 5000.0;
		static constexpr int max_withdrawls = 3;
		static constexpr double max_withdraw_percent = 0.2;

	protected:
		int num_withdrawals;

	public:
		Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
		bool deposit(double amount);	// Deposyt powyzej $5000 albo wiecej mamy bonus $50
		bool withdraw(double amount);	// Maksymalnie mozliwe 3 wyplaty i max 20% zdeponowanych srodkow
		
		friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

};

#endif // ! TRUST_ACCOUNT_H_

