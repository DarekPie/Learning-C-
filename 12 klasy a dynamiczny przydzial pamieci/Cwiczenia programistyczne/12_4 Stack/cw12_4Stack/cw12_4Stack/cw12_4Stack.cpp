#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
	using namespace std;
	Stack st; 
	Stack s2; 
	char ch;
	unsigned long po;
	cout << "Nacisnij D, aby wprwoadzic deklaracje, \n" << "P, aby przetworzyc deklaracje lub K, aby zakonczyc.\n";
	while (cin >> ch && toupper(ch) != 'K')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'D':
		case 'd':	cout << "Podaj numer nowej deklaracji: ";
					cin >> po;
					if (st.isfull())
						cout << "Stos pelen!\n";
					else
						st.push(po);
					s2 = st;
					break;
		case 'P':
		case 'p':	if (st.isempty())
						cout << "Stos jest pusty!\n";
					else
					{
						st.pop(po);
						cout << "Deklaracje nr " << po << " zdjeta\n";
					}
					break;
		}
		cout << "Nacinij D, aby wpowadzic dekalracje, \n" << "P, aby przetworzyc deklaracje, lub K, aby zakonczyc.\n";
	}
	cout << "Fajrant!\n";

	cout << "Deklaracje nr " << po << " zdjeta\n";


	return 0;

}

