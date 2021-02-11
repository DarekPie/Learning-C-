#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
#include <deque>
#include<cctype>


bool is_palidrome(const std::string &s)
{
	std::deque<char> d;
// dodanie wszystkich stringow ktore sa literami i wrzucane na koniec
// i zmieniane na duze litery
	for (char c : s)
	{
		if (std::isalpha(c))
			d.push_back(std::toupper(c));
	}

	char c1{};		// tymczasowy front stringu
	char c2{};		// tymczasowy koniec stringu

	//Gdy  jest wiecej niz jeden znak i deque 
	// usun i porownaj znaki na froncie z tymi na koncu deque
	// jesli nie sa takie same - return false, od tego momentu wiemy ze nie moze to byc palidrom
	// jesli zakonczysz petle while string musi byc palidromem wiec return true
	while (d.size() > 1)
	{
		c1 = d.front();
		c2 = d.back();
		d.pop_front();
		d.pop_back();
		if (c1 != c2)
			return false;
	}

	return true;	
}


int main()
{

	std::vector<std::string> test_string{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
		"avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
		"A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

	std::cout << std::boolalpha;
	std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;

	for (const auto& s : test_string)
		std::cout << std::setw(8) << std::left << is_palidrome(s) << s << std::endl;
	
	std::cout << std::endl;
	return 0;
}

