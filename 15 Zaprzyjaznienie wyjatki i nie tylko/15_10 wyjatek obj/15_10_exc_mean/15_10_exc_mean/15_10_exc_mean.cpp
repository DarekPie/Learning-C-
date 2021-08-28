#include <iostream>
#include <cmath>
#include "exec_mean.h"

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw (bad_gmean);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "Podaj dwie liczby: "; 
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << "Srednia harmoniczna liczb " << x << " i " << y
				<< " wynosi " << z << endl;
			cout << "Srednia geometryczna liczb " << x << " i " << y
				<< " wynosi " << gmean(x, y) << endl;
			cout << "Podaj kolejna pare liczb <w aby wyjsc>: ";
		}
		catch (bad_hmean & bg)
		{
			bg.mesg();
			cout << "Sprobuj ponowanie.\n";
			continue;
		}
		catch (bad_gmean & hg)
		{
			hg.mesg();
			cout << "Uzyte wartosci: " << hg.v1 << ", "
				<< hg.v2 << endl;
			cout << "Niestety to koniec zabawy.\n";
			break;
		}
	}
	cout << "Koniec\n";
	return 0;
}

double hmean(double a, double b) throw (bad_hmean)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw (bad_hmean)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a*b);
}