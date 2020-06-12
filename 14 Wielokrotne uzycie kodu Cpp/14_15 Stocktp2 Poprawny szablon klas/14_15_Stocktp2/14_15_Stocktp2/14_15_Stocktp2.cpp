#include <iostream>
#include <cstdlib>					// funkcje rand() i srand()
#include <ctime>					// funkcja time()
#include "stckpt2.h"

const int Num = 10;

int main()
{
	std::srand(std::time(0));		// inicjalizacja funkcji rand()
	std::cout << "Podaj rozmiar stosu: ";
	int stacksize;
	std::cin >> stacksize;

	//tworzy pusty stos o pojemnosci stackzie
	Stack<const char* > st(stacksize);

	//Pojemnik na teczki przychodzace
	const char * in[Num] = {
		" 1: Hendryk Gilgamesz" , " 2: Kinga Isztar",
		" 3: Beata Roker", " 4: Jan Flagranti",
		" 5: Wolfang Mocny", " 7: Patrycja Kup",
		" 6: Jacek Almond", " 8: Ksawery Papryka",
		" 9: Julian Mor", " 10: Marian Macher"
	};

	//Pojemnik na teczki wychodzace
	const char * out[Num];

	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextin < Num) // Szanse pol na pol
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);				// Wg zasady ¿e szansa pó³ na pó³ ¿e teczka idzie na sterte wychodzace i pó³ na pó³ na wraca spowrotem
	}

	for (int i = 0; i < Num; i++)
		std::cout << out[i] << std::endl;

	std::cout << "Koniec!\n";
	return 0;
}
