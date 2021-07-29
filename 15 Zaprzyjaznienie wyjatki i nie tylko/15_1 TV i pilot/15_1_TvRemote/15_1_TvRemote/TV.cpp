#include "TV.h"
#include <iostream>

bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	if (channel < maxchanell)
		channel++;
	else
		channel = 1;

}

void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchanell;
}

void Tv::settings() const
{
	using std::cout;
	using std::endl;
	cout << "Telewizor jest " << (state == Off ? "Wylaczony" : "Wlaczony") << endl;
	if (state == On)
	{
		cout << "Glosnosc = " << volume << endl;
		cout << "Program = " << channel << endl;
		cout << "Tryb = " << (mode == Antenna ? "antena" : "kabel") << endl;
		cout << "Wejscie = " << (input == TV ? "TV" : "VCR") << endl;
	}
}
