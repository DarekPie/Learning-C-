#include "string2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
const int ArSize = 10;
const int MaxLen = 81;

int main()
{

	using namespace std;
	//String name;

	//cout << "Czesc, jak masz na imie?\n"; 
	//cin >> name;

	//cout << name << ", wpisz do " << ArSize << " ktorkich powiedzonek <pusty wiersz konczy wprowadzanie>:\n";
	//String sayings[ArSize];
	//char temp[MaxLen];
	//int i;
	//for (i = 0; i < ArSize; i++)
	//{
	//	cout << i + 1 << ": ";
	//	cin.get(temp, MaxLen);
	//	while (cin && cin.get() != '\n')
	//		continue;
	//	if (!cin || temp[0] == '\0')
	//		break;
	//	else
	//		sayings[i] = temp;
	//}
	//int total = i;
	//if (total > 0)
	//{
	//	cout << "Oto Twoje powiedzonka:\n";
	//	for (i = 0; i < total; i++)
	//		cout << sayings[i] << "\n";
	//	//i tu zaczyna sie roznica!
	//			// Wskaznik wskazujace szukane ciagu
	//	String * shortest = &sayings[0];
	//	String * first = &sayings[0];
	//	for (i = 0; i < total; i++)
	//	{
	//		if (sayings[i].length() < shortest->length())
	//			shortest = &sayings[i];
	//		if (sayings[i] < *first)		// porownanie wartosci
	//			first = &sayings[i];		// przypisanie adresu   
	//	}

	//	cout << "Najkrotsze powiedzonko:\n" << *shortest << endl;
	//	cout << "Powiedzonko alfabetycznie pierwsze:\n" << *first << endl;

	//	srand(time(0));
	//	int choice = rand() % total;		// wybierz liczbe loswa
	//	// wywoaleni operatora new do przyialu nowego obiektu
	//	String * favorite = new String(sayings[choice]);		// dziala tak samo jak:  String(sayings[choice]); )  Class(type-name);
	//	cout << "Moje ulubione powiedzonko:\n" << *favorite << endl;
	//	delete favorite;
	//}
	//else
	//	cout << "Nie ma o czym gadac, co?\n";

	//cout << "Zegnam.\n";

	String test1("Pierwszy tekst ");
	String test2 = "Podaj Swoje Imie: \n";
	test2.stringlow();

		String test3 = test1 + test2;

	


	return 0;
}
