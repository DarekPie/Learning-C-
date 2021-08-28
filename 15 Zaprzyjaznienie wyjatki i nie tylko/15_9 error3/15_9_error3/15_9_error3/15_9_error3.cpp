#include <iostream>

double hmean(double a, double b);

int main()
{
	double x, y, z;
	
	std::cout << "Podaj dwie liczby: ";
	while (std::cin >> x >> y)
	{
		try {
			z = hmean(x, y);
		}
		catch (const char * s)
		{
			std::cout << s << std::endl;
			std::cout << "Podaj kolejna pare liczb: ";
			continue;
		}
		std::cout << "Srednia harmoniczna liczba " << x << " i " << y
			<< " wynosi " << z << std::endl;
		std::cout << "Podaj kolejna pare liczb <w aby wejsc>: ";
	}
	std::cout << "Koniec\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw "Niepoprawne argumenty funkcji hmean(): a = -b nie jest dozwolone";
	return 2.0 * a * b / (a + b);
}
