#include <iostream>
#include <cstring>
#include "brass.h"
using std::cout;
using std::ios_base;
using std::endl;

Brass::Brass(const char *s, long an, double bal)
{
	//std::strncpy(fullName, s, MAX - 1);
	strcpy_s(fullName, MAX - 1, s);
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Nie mozna wplacic ujemnej kwoty; Wplata annulowana.\n";
	else
		balance += amt;
}

void  Brass::Withdraw(double amt)
{
	if (amt < 0)
		cout << "Nie mozna wplacic ujemnej kwoty; Wplata annulowana.\n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "Zadana suma " << amt << " zl przekracza dostepne srodki.\nWyplata anulowana.\n";
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	//Ustawiamy format ###.##
	ios_base::fmtflags initialSate = cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	cout << "Klient: " << fullName << endl;
	cout << "Numer rachunku: " << acctNum << endl;
	cout << "Stan konta: " << balance << " zl" << endl;
	cout.setf(initialSate);		// Przywraca poczatkowy format
}

//Metody klasy BrassPlus
BrassPlus::BrassPlus(const char *s, long an, double bal, double ml, double r) : Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : Brass(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

// Nowa defnicja metody ViewAcct
void BrassPlus::ViewAcct() const
{
	ios_base::fmtflags initialSate = cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);

	Brass::ViewAcct();
	cout << "Limit debetu: " << maxLoan << " zl" << endl;
	cout << "Kwota zadluzenia: " << owesBank << " zl" << endl;
	cout << "Stopa oprocentowania: " << 100 * rate << "%\n";
	cout.setf(initialSate);		// Przywraca poczatkowy format
}

//Nowa definicja metody Withdraw()
void BrassPlus::Withdraw(double amt)
{
	ios_base::fmtflags initialSate = cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
		Brass:Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Zadluzenie faktyczne: " << advance << " zl" << endl;
		cout << "Odsetki: " << advance * rate << " zl" << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Przekroczony limit debetu. Operacja anulowana.\n";
	cout.setf(initialSate);		// Przywraca poczatkowy format
}
