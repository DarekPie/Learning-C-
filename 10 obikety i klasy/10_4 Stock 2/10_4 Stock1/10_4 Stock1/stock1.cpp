#include "stock1.h"
#include <iostream>
#include <cstring>

Stock::Stock()
{
	std::cout << "Wywolano konstruktor domyslny\n";
//	std::strcpy(company, "brak nazwy");
	strcpy_s(company, 30, "brak nazwy");
	shares = 0;
	share_val = 0;
	total_val = 0;
}

Stock::Stock(const char * co, int n, double pr)
{
	std::cout << "Wywolano konstruktor z argumentem " << co << "\n";
//	std::strcpy(company, co, 29);
	strcpy_s(company, 30, co);
	company[29] = '\0';

	if (n < 0)
	{
		std::cerr << "Liczba udzialow udzialow nie moze byc ujemna; ustalam liczbe udzialow w " << company << " na 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot(); 
}

Stock::~Stock()
{
	std::cout << "Do widzenia, " << company << "!\n";
}

void Stock::buy(int num, double price)
{
	if (num < 0)
		std::cerr << "Liczba nabywanych udzalow nie moze byc ujemna. Tranzakcja przerwana.\n";
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(int num, double price)
{
	using std::cerr;
	if (num > 0)
		cerr << "Liczba sprzedawanych udzialow nie moze byc ujemna. Tranzakcja przerwana.\n";
	else if (num > shares)
		cerr << "Nie mozna sprzedac wiecej udzialow niz posiadasz! Tranzakcja przerwana.\n";
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
	cout << "Spolka " << company << " Liczba udzialow: " << shares << endl
		<< "Cena udzialu: " << share_val << " zl, Laczna wartosc udzalow: " << total_val << ' zl ' << endl;
}