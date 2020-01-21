#include <iostream>
#include "queue.h"
#include <cstdlib>						// rand() i srand()
#include <ctime>						// time()
const int MIN_PER_HR = 60;
bool newcustomer(double x);				// czy toral juz nastepny klient?


int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;



///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// przygotowanie symulacji
	std::srand(std::time(0));						// inicjalizacja generatora liczba losowych

	cout << "Studium przypadku: bankomat Bank Stu Kas\n";
	cout << "Podaj maksymalna dlugosc kolejki: "; 
	
//	cin >> qs;								// do iteracji! DO PÊTLI!!!
								// w kolejce moze stanac do qs klientow		DO PÊTLI!!! 

	cout << "Podaj symulowany czas (w godiznach) :";
	int hours = 100;
	//cin >> hours;							// < 100 h! ale zostawmy stale

	// symulacja z jednominutowa rozdzielczoscia
	long cyclelimit = MIN_PER_HR * hours;			// liczba cykli
	double min_per_cust = 1;						// sredni odstep czasow ma wynosic minute! 
	double perhour = MIN_PER_HR / min_per_cust;		// Liczba klientow na godzine - wychodzi ze jest ich 
	
						// wg zalozenia - sr czas oczekiwania ma byc 1 minuta


	Item temp;									// Dane nowego klienta
	long turnways = 0;							// liczba klientow odsylanych z kolejki
	long customers = 0;							// liczba klientow przyjetych do kolejki
	long served = 0;							// liczba klientow obsluzonych w symulacji
	long sum_line = 0;							// ³¹czna liczba oczekujacych 
	int wait_time = 0;							// czas do zwolnienia bankomatu
	long line_wait = 0;							// ³¹czny czas oczekiwania
	double t_sr = 0;							// sredni czas oczekiwania ma wyniesc minute! 
	int qs = 1;									// maksymalna ilosc klientow w kolejce 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////













	// petla qs ew. while 
	while (t_sr <= 1)
	{
		Queue line(qs);
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))			// mamy nowego chêtnego
			{
				if (line.isfull())
					turnways++;
				else
				{
					customers++;
					temp.set(cycle);				// czas przybycia = nr cyklu
					line.enqueue(temp);				// do³¹czenie klienta do kolejki
				}
			}

			if (wait_time <= 0 && !line.isempty())
			{
				line.dequeue(temp);					// nastepny do obs³uzenia
				wait_time = temp.ptime();			// czas obs³ugi = wait_time
				line_wait += cycle - temp.when();
				served++;
			}

			if (wait_time > 0)
				wait_time--;

			sum_line += line.quecount();
		}

		t_sr = (double)line_wait / served;
	}

//  rozpoczêcie  symulacji


	// zestawienie wynikow
	if (customers > 0)
	{
		cout << " liczba klientow przyjetych: " << customers << endl;
		cout << "liczba klientow obsluzonych: " << served << endl;
		cout << " liczba klientow odeslanych : " << turnways << endl;
		cout << "	srednia dlugosc kolejki: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " sredni czas oczekiwania: " << (double)line_wait / served << " minut\n";
	}
	else
		cout << "Brak klientow!\n";

	cout << "Gotowe!\n";

	return 0;
}

bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
