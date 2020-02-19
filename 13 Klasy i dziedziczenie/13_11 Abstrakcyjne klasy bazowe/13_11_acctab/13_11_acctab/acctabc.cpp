#include<iostream>
#include<cstring>
#include "acctabc.h"
using std::cout;
using std::ios_base;
using std::endl;

AcctABC::AcctABC(const char *s, long an, double bal)
{
//	std::strncpy(fullName, s, MAX - 1);
	strcpy_s(fullName, MAX - 1, s);
	fullName[MAX - 1] = '\n';
	acctNum = an;
	balance = bal;
}

void AcctABC::Deposit(double amt)
{
	if (amt < 0)
		cout << "Nie mozesz wyplacic ujemnej kwoty; Wplata anulowana.\n";
	else
		balance += amt;
}

void AcctABC::Withdraw(double amt)
{
	balance -= amt;
}

ios_base::fmtflags AcctABC::SetFormat() const
{
	//ustawia format ###.##
	ios_base::fmtflags initialState = cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	return initialState;
}

void Brass::Withdraw(double amt)
{
	if (amt < 0)
		cout << "Nie mozna wyplacic ujemnej kwoty; Wyplata anulowana.\n";
	else if (amt <= Balance())
		AcctABC::Withdraw(amt);
	else
		cout << "Zadana wartosc " << amt << " zl przekracza dostepne srodki .\n" << "Wyplata anuloana.\n";
}

void Brass::ViewAcct() const
{
	ios_base::fmtflags initialState = SetFormat();
	cout << "Wlasciciel archunku Brass: " << FullName() << endl;
	cout << "Numer rachunku: " << AcctNum() << endl;
	cout << "Stan konta: " << Balance() << " zl" << endl;
	cout.setf(initialState);
}

//Metody klasy BrassPlus
BrassPlus::BrassPlus(const char *s, long an, double bal, double ml, double r) : AcctABC(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : AcctABC(ba) // Uzywa niejawnego konstruktora kopiujacego
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct() const
{
	ios_base::fmtflags initialState = SetFormat();
	cout << "Wlasciciel archunku Brass: " << FullName() << endl;
	cout << "Numer rachunku: " << AcctNum() << endl;
	cout << "Stan konta: " << Balance() << " zl" << endl;
	cout << "Limit debetu: " << maxLoan << " zl " << endl;
	cout << "Stopa oprocentowania: " << 100 * rate << "%\n";
	cout.setf(initialState);
}

void BrassPlus::Withdraw(double amt)
{
	ios_base::fmtflags initialStete = SetFormat();
	double bal = Balance();

	if (amt <= bal)
		AcctABC::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Zadluzenie faktyczne " << advance << " zl " << endl;
		cout << "Odsetki: " << advance * rate << " zl " << endl;
		AcctABC::Withdraw(amt);
	}
	else
		cout << "Przekroczony limit debetu. Operacja anulowana.\n";
	cout.setf(initialStete);
}
 