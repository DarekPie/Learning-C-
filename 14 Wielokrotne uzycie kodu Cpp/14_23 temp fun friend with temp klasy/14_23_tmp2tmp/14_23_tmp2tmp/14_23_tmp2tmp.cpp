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
		friend void reports(HasFriendT<TT> &);
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




int main()
{
    std::cout << "Hello World!\n";
}