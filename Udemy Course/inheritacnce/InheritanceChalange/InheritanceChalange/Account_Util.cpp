#include "Account_Util.h"
#include<iostream>

void display(const std::vector<Account>& accounts)
{
	std::cout << "\n=== Accounts=========" << std::endl;
	for (const auto &acc : accounts)
		std::cout << acc << std::endl;
}

void deposit(std::vector<Account>& accounts, double amount)
{
	std::cout << "\n=== Depositing to Accounts ========" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
	}
}

void withdraw(std::vector<Account>& accounts, double amount)
{
	std::cout << "\n=== Withdraw for Accounts =======" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed withdrawal of " << amount << " from " << acc << std::endl;
	}
}



//***************Saving_Account*************************	

void display(const std::vector<Saving_Account>& accounts)
{
	std::cout << "\n=== Saving_Account=========" << std::endl;
	for (const auto &acc : accounts)
		std::cout << acc << std::endl;
}

void deposit(std::vector<Saving_Account>& accounts, double amount)
{
	std::cout << "\n=== Depositing to Saving_Account ========" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
	}
}

void withdraw(std::vector<Saving_Account>& accounts, double amount)
{
	std::cout << "\n=== Withdraw for Saving_Account =======" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed withdrawal of " << amount << " from " << acc << std::endl;
	}
}

//*************Checking_Account**********************

void display(const std::vector<Checking_Account>& accounts)
{
	std::cout << "\n=== Checking_Account=========" << std::endl;
	for (const auto &acc : accounts)
		std::cout << acc << std::endl;
}

void deposit(std::vector<Checking_Account>& accounts, double amount)
{
	std::cout << "\n=== Depositing to Checking_Account ========" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
	}
}

void withdraw(std::vector<Checking_Account>& accounts, double amount)
{
	std::cout << "\n=== Withdraw for Checking_Account =======" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed withdrawal of " << amount << " from " << acc << std::endl;
	}
}



//**************Trust_Account****************************

void display(const std::vector<Trust_Account>& accounts)
{
	std::cout << "\n=== Trust_Account=========" << std::endl;
	for (const auto &acc : accounts)
		std::cout << acc << std::endl;
}

void deposit(std::vector<Trust_Account>& accounts, double amount)
{
	std::cout << "\n=== Depositing to Trust_Account ========" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
	}
}

void withdraw(std::vector<Trust_Account>& accounts, double amount)
{
	std::cout << "\n=== Withdraw for Trust_Account =======" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed withdrawal of " << amount << " from " << acc << std::endl;
	}
}
