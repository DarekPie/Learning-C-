#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
	private:
		T item;
		static int ct;

	public:
		HasFriend(const T & i) : item(i) { ct++; }
		~HasFriend() { ct--; }
		friend void counts();
		friend void reports(HasFriend<T> &);			//Parametr w postaci szablonu

};

//Kazda specjalizacja posiada wlasna statyczna dana skladowa
template <typename T> 
int HasFriend<T>::ct = 0;

//Funkcja (nie szablon) zaprzyjazniona z wszystkimi klasami HasFriend<T>
void counts()
{
	cout << "Konkretyzacje int: " << HasFriend<int>::ct << "; ";
	cout << "Konkretyzacje double: " << HasFriend<double>::ct << endl;
}

//Funkcja (nie szablon) zaprzyjazniona z klasa HasFriend<int>
void reports(HasFriend<int> & hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}

//Funkcja (nie szablon) zaprzyjazniona z klasa HasFirend<double>
void reports(HasFriend<double> & hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}

int main()
{
	cout << "Brak zadeklarowanych obiektow: ";
	counts();

	HasFriend<int> hfi1(10);
	cout << "Po deklaracji hfi1: ";
	counts();

	HasFriend<int> hfi2(20);
	cout << "Po deklaracji hfi2: ";
	counts();

	HasFriend<double> hfdb(10.5);
	cout << "Po deklaracji hfdb: ";
	counts();

	reports(hfi1);
	reports(hfi2);
	reports(hfdb);

	return 0;

}
