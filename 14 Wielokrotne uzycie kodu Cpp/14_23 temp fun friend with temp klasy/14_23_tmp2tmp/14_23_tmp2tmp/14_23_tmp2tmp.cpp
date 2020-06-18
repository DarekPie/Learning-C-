#include <iostream>
using std::cout;
using std::endl;

//Prototypy szablonow
template <typename T> void counts();
template <typename T> void reports(T &);

//Szablony klasy
template <typename TT>
class HasFriendT
{
	private:
		TT item;
		static int ct;

	public:
		HasFriendT(const TT & i) : item(i) { ct++; }
		HasFriendT() { ct--; }
		friend void counts<TT>();
		friend void reports<>(HasFriendT<TT> &);
};

template <typename T>
int HasFriendT<T>::ct = 0;

//definicje szablonow funkcji zaprzyjaznionych
template <typename T>
void  counts()
{
	cout << "Szablona size: " << sizeof(HasFriendT<T>) << "; ";
	cout << "Szablon counts(): " << HasFriendT<T>::ct << endl;
}

template <typename T>
void reports(T & hf)
{
	cout << hf.item << endl;
}


int main()
{
	counts<int>(); 
	HasFriendT<int> hif1(10);
	HasFriendT<int> hif2(20);
	HasFriendT<double> hfdb(10.5);
	reports(hif1);
	reports(hif2);
	reports(hfdb);

	cout << "Wynik dzialania countr<int>(): \n";
	counts<int>();
	cout << "Wynik dzialania countr<double>(): \n";
	counts<double>();

	return 0;
}