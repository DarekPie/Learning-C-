#include <iostream>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include "stock2.h"
using std::ostream;
using std::istream;

int Stock::num_companies = 0;

int Stock::HowMany() { return num_companies; }


Stock::Stock()
{
	len = 4;
	company = new char[1];
	company[0] = '\0';
	num_companies++;
}

Stock::Stock(const char * co, int n, double pr)
{


	len = std::strlen(co);
	company = new char[len + 1];
	strcpy_s(company, len +1, co);
	num_companies++;

	if (n < 0)
	{
		std::cerr << "Liczba udzialow nie moze byc ujemna; ustalam liczbe udzalow w " << company << "na 0.\n";
		shares = 0;
	}
	else
		shares = n;
	
	share_val = pr;
	set_tot();

}

Stock::~Stock()
{
	--num_companies;
//	delete company;
}

void Stock::buy(int num, double price)
{
	if (num < 0)
		std::cerr << "Liczba nabywanych udzlow nie moze byc ujemna. Transakcja przerwana. \n";
	else
	{
		shares += num;
		shares = price;
		set_tot();
	}

}

void Stock::sell(int num, double price)
{
	using std::cerr;
	if (num < 0)
		cerr << "Liczba sprzedawanych udzelow nie moze byc ujemna. Transakcja przerwana. \n";
	else if (num > shares)
		cerr << "Nie mozesz sprzedac wiecej udzalow, niz posiadasz! Transakcjaz przerwana. \n";
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}

}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	using std::cout;
	using std::endl;
	cout << "Spolka: " << company
		<< " Liczba udzalow: " << shares << endl
		<< "Cena udzalu: " << share_val << " zl " << endl
		<< "Laczna wartosc udzalow: " << total_val << " zl " << endl;
} 

const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

ostream & operator<<(ostream & os, const Stock & st)
{
	
	os << "Spolka: " << st.company
		<< " Liczba udzalow: " << st.shares << "\n"
		<< "Cena udzalu: " << st.share_val << " zl " << "\n"
		<< "Laczna wartosc udzalow: " << st.total_val << " zl " << "\n";
	return os;
}
