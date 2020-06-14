#include <iostream>
using std::cout;
using std::endl;


template <typename T>
class Beta
{
	private:
		template <typename V>				// Zagniezdzony szablon klasy jako skladowa
		class Hold
		{
			private:
				V val;

			public:
				Hold(V v = 0) : val(v) {}
				void show() const { cout << val << endl; }
				V Value() const { return val; }
		};
		Hold<T> q;						// obiekt szablonu
		Hold<int> n;					// obiekt szablonu
		// n jest obiektem typu Hold opartym na typie int
		// q jest obiektem typu Hold opartym na typie T czyli parametrze szablonuw Beta

	public:
		Beta(T t, int i) : q(t), n(i) {}

		template <typename U>				// Metoda szablonu
		U blab(U u, T t) { return(n.Value() + q.Value()) * u / t; }

		void Show() const { q.show(); n.show(); }
};

int main()
{
	Beta<double> guy(3.5, 3);								// Okresla typ T jako double,  w Hold<T> q, T staje sie Hold<double>
	guy.Show();
	cout << guy.blab(10, 2.3) << endl;
	cout << "Koniec\n";
	return 0;
}
