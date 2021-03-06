#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;

class JustTesting
{
	private:
		string words;
		int number;
	public:
		JustTesting(const string & s = "Obiekt testowy,", int n = 0)
			{words = s; number = n; cout << words << " skonstruowany\n";}
		~JustTesting() { cout << words << " usuniety\n"; }
		void show() const { cout << words << ", " << number << endl; }
};

int main()
{
	char * buffer = new char[BUF];				// przydzial bloku pamieci do testow
	
	JustTesting *pc1, *pc2;

	pc1 = new (buffer) JustTesting;			// Umieszcza nowy obiekt w buforze
	pc2 = new JustTesting("Sterta1", 20);	// Umieszcza nowy obietk na stercie

	cout << "Adresy blokow pamieci:\n" << "bufor : " << (void *)buffer << " sterta: " << pc2 << endl;
	cout << "Zawartosc pamieci:\n";
	cout << pc1 << ": "; 
	pc1->show();
	cout << pc2 << ": ";
	pc2->show();

	JustTesting *pc3, *pc4;
	//Poprawiony przydzial miejscowa wersja new
	pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Lepszy pomysl", 6);
	pc4 = new JustTesting("Sterta2", 10);

	cout << "Zawartosc pamieci:\n";
	cout << pc3 << ": ";
	pc3->show();
	cout << pc4 << ": ";
	pc4->show();

	delete pc2;
	delete pc4;
	// Jawne wywoalenie destruktorow obiektow przydzelanych miescowa wersja new
	pc3->~JustTesting();
	pc1->~JustTesting();
	delete[] buffer;
	cout << "Fajrant\n";
	return 0;
}

