#include <iostream>
#include <cstring>
#include "stock2.h"


Stock::Stock()
{
	std::strcpy(company, "brak nazwy");
	shares = 0;
	share_val = 0;
	total_val = 0;
}

Stock::Stock(const char * co, int n, double pr)
{
	std::strncpy(company, co, 29);
	company[29] = '\0';
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