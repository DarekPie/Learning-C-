#ifndef PORT_H_
#define PORT_H_
#include <iostream>
using namespace std;

class Port
{
	private:
		char *brand;				// Marka
		char style[20];				// Na przyklad lekko brazowe, rubinowe, z najlepszego rocznika 
		int bottles;

	public:
		Port(const char *br = "Brak", const char *st = "Brak", int b = 0);
		Port(const Port &p);					// konstruktor kopiujacy
		virtual ~Port() { delete[] brand; }
		Port &operator=(const Port &p);												// Moze by wirtualny
		Port &operator+=(int b);				// Dodaje b do bottles
		Port &operator-=(int b);				// Odejmuje b od bottales, jesli operacja ta jest mozliwa
		int BottleCount() const { return bottles; }
		virtual void Show() const;
		friend ostream &operator<<(ostream &os, const Port &p);						// Nie moze byc wirtualny!
};

class VitagePort : public Port
{
	private:
		char *nickname;
		int year;

	public:
		VitagePort() : Port() {}
		VitagePort(const char * br, int b, const char *nn, int y);
		VitagePort(const VitagePort &vp);
		~VitagePort() { delete[] nickname; }
		VitagePort &operator=(const VitagePort &vp);							// // Moze by wirtualny
		void Show() const;
		friend ostream &operator<<(ostream &os, const VitagePort &vp);
};

#endif

