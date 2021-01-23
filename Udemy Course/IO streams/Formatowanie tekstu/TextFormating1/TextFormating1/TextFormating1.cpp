#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


struct City
{
	std::string name;
	long population;
	double cost;
};

struct Country
{
	std::string name;
	std::vector<City> cities;
};

struct Tours
{
	std::string title;
	std::vector<Country> countries;
};

void ruler()
{
	std::cout << "\n1234567890123456789012345678901234567890123456789012345678901234567890" << std::endl;
}


int main()
{
	
	Tours tours
	{"Tour Ticket prices from Miami",					// title
		{												// poczatek vectora countries
			{"Colombia",								// country -> name
				{										// poczatek vectora cities
					{ "Bogota", 8778000, 400.98},		// Miasto, populacja, koszt
					{ "Cali", 2401000, 424.12},			// Miasto, populacja, koszt
					{"Medellin", 2464000, 350.98},		// Miasto, populacja, koszt
					{"Cartagena", 972000, 345.34},		// Miasto, populacja, koszt
				},										// koniec vectora cities
			},
			{ "Brazil",												// country -> name
				{													// poczatek vectora cities
					{ "Rio De Janiero", 13500000, 567.45},			// Miasto, populacja, koszt
					{"Sao Paulo", 11310000, 975.45 },				// Miasto, populacja, koszt
					{"Salvador", 18234000, 855.99}					// Miasto, populacja, koszt
				},													// koniec vectora cities
			},
			{ "Chile",									// country -> name
				{										// poczatek vectora cities
					{"Valdivia", 260000, 569.12 },		// Miasto, populacja, koszt
					{"Santiago", 7040000, 520.00}		// Miasto, populacja, koszt
				},										// koniec vectora cities
			},
			{"Argentina",									// country -> name
				{											// poczatek vectora cities
					{"Buenos Aires", 3010000, 723.77}		// Miasto, populacja, koszt
				}											// koniec vectora cities
			}
		}												// koniec vectora countries
	};

	const int total_width{ 70 };
	const int country_field_width{ 20 };
	const int city_field_width{ 20 };
	const int popu_field_width{ 15 };
	const int cost_field_width{ 15 };

	ruler();
	int title_length = tours.title.length();
	std::cout << std::setw((total_width - title_length) / 2) << "" << tours.title << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(country_field_width) << std::left << "Country"
		<< std::setw(city_field_width) << std::left << "City"
		<< std::setw(popu_field_width) << std::right << "Population"
		<< std::setw(cost_field_width) << std::right << "Price"
		<< std::endl;

	std::cout << std::setw(total_width)
		<< std::setfill('-')
		<< ""
		<< std::endl;   // display total_width dashes

	std::cout << std::setfill(' '); // reset setfill to blank spaces
	std::cout << std::setprecision(2) << std::fixed;

	for (Country country : tours.countries) {
		for (size_t i = 0; i < country.cities.size(); ++i) {
			std::cout << std::setw(country_field_width) << std::left << ((i == 0) ? country.name : "") // conditional operator
				<< std::setw(city_field_width) << std::left << country.cities.at(i).name
				<< std::setw(popu_field_width) << std::right << country.cities.at(i).population
				<< std::setw(cost_field_width) << std::right << country.cities.at(i).cost
				<< std::endl;
		}
	}

}
