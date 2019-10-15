#include "string2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
const int ArSize = 10;
const int MaxLen = 81;

int main()
{

	using namespace std;

	String test1("Pierwszy tekst ");
	String test2 = "Podaj Swoje Imie: \n";
	test2.stringlow();
	test1.stringup();
	cout << test1.has("e") << endl;

	String test3 = test1 + test2;


	String s1(" i ucze się C++.");
	String s2 = "Podaj swoje imie: ";
	String s3;
	cout << s2;									// przeciazenie operatora <<
	cin >> s3;									// przeciazenie operatora >>
	s2 = "Mam na imie " + s3;					// przeciazony operator = i +
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();
	cout << "Ciag\n" << s2 << "\nzawiera " << s2.has("A") << " 'A' .\n";
	s1 = "czerwona";							// String (const char *)
												// a potem String & operator =(const String&)

	String rgb[3] = { String(s1), String("zielona"), String("niebieska") };
	cout << "Podaj nazwe barwy podstawowej: ";
	String ans;
	bool success = false;
	
	while (cin >> ans)
	{
		ans.stringlow();						//zmiana litery w ciagu na male
		for(int i = 0; i < 3; i ++)
		{
			if (ans == rgb[i])
			{
				cout << "Prawidlowo!\n";
			success = true;
			break;
			}
		}
		if (success)
			break;
		else
			cout << "Sprobuj ponowanie!\n";
	}

	cout << "Zegnam\n";
	return 0;
}
