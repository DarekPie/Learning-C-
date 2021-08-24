#include <iostream>
#include <string>
#include "queuetp.h"

int main()
{
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;

	QueueTP<string> cs(5);
	string temp;

	while (!cs.isfull())
	{
		cout << "Wpisz swoje imie i nazwisko. Zostaniesz obsluzony\y "
			"wedlug kolejnosci prybycia.\n"
			"Imie i nazwisko: ";
		getline(cin, temp);
		cs.enqueue(temp);
	}
	cout << "Kolejka jest pelna. Rozpoczynamy przetwarzanie!\n";

	while (!cs.isempty())
	{
		cs.dequeue(temp);
		cout << "Teraz obsluzymy " << temp << "...\n";
	}

	return 0;
}

