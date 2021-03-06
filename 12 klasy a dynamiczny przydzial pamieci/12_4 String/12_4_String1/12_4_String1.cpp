#include "string1.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	//using std::cout;
	//using std::cin;
	//using std::endl;
	//String name;
	//cout << "Czesc, jak masz na imie?\n";
	//cin >> name;

	//cout << name << ", wpisz do " << ArSize << " krotkich powiedzonek <pusty wiersz konczy wprowadzenie>:\n";
	//String sayings[ArSize];				// tabkuca obiektow
	//char temp[MaxLen];					// tymczasowy bufor ciagow
	//int i;
	//for (i = 0; i < ArSize; i++)
	//{
	//	cout << i + 1 << ": ";
	//	cin.get(temp, MaxLen);
	//	while (cin && cin.get() != '\n')
	//		continue;
	//	if (!cin || temp[0] == '\0')		// czyzby pusty wiersz?
	//		break;
	//	else
	//		sayings[i] = temp;				// przeciazony operator przypisania
	//}
	//int total = i;							// laczna liczba wczytanych wierszy
	//cout << "Oto Twoje powiedzonka:\n";
	//for (i = 0; i < total; i++)
	//	cout << sayings[i][0] << ": " << sayings[i] << endl;
	//int shortest = 0;
	//int first = 0;
	//for (i = 1; i < total; i++)
	//{
	//	if (sayings[i].length() < sayings[shortest].length())
	//		shortest = i;
	//	if (sayings[i] < sayings[first])
	//		first = i;
	//}
	//cout << "Najkrotsze powiedzonko: \n" << sayings[shortest] << endl;
	//cout << "Powiedzonko alfabetycznie pierwsze:\n" << sayings[first] << endl;
	//cout << "Program wykorzystal " << String::HowMany() << " obiektow klasy String. Hej!\n";


	using namespace std;
	String name;

	cout << "Czesc, jak masz na imie?\n";
	cin >> name;

	cout << name << ", wpisz do " << ArSize << " ktorkich powiedzonek <pusty wiersz konczy wprowadzanie>:\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if (total > 0)
	{
		cout << "Oto Twoje powiedzonka:\n";
		for (i = 0; i < total; i++)
			cout << sayings[i] << "\n";
		//i tu zaczyna sie roznica!
				// Wskaznik wskazujace szukane ciagu
		String * shortest = &sayings[0];
		String * first = &sayings[0];
		for (i = 0; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first)		// porownanie wartosci
				first = &sayings[i];		// przypisanie adresu   
		}

		cout << "Najkrotsze powiedzonko:\n" << *shortest << endl;
		cout << "Powiedzonko alfabetycznie pierwsze:\n" << *first << endl;

		srand(time(0));
		int choice = rand() % total;		// wybierz liczbe loswa
		// wywoaleni operatora new do przyialu nowego obiektu
		String * favorite = new String(sayings[choice]);		// dziala tak samo jak:  String(sayings[choice]); )  Class(type-name);
		cout << "Moje ulubione powiedzonko:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "Nie ma o czym gadac, co?\n";

	cout << "Zegnam.\n";
	return 0;
}
