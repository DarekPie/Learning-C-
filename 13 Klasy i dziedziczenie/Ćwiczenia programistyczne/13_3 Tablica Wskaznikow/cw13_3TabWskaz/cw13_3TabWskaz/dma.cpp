#include "dma.h"
#include <cstring>



ABCdma::ABCdma(const char * s, int r)
{
	int lengh = std::strlen(s) + 1;
	label = new char[lengh];
	strcpy_s(label, lengh, s);
	rating = r;
}

ABCdma::ABCdma(const ABCdma & rs)
{
	int lengh = std::strlen(rs.label) + 1;
	label = new char[lengh];
	strcpy_s(label, lengh, rs.label);
	rating = rs.rating;
}

ABCdma & ABCdma::operator=(const ABCdma & rs)
{
	if (this == &rs)
		return *this;

	delete[] label;
	label = new char[std::strlen(rs.label) + 1];		// zmien na security
	rating = rs.rating;
	return *this;
}



void baseDMA::View() const
{
	std::cout << "Label = " << getLabel() << std::endl;
	std::cout << "Rating = " << getRating() << std::endl;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if (this == &rs)
		return *this;
	ABCdma::operator=(rs);
	return *this;
}

std::ostream & operator<<(std::ostream & os, const ABCdma & rs)
{
	os << "Etykieta: " << rs.label << std::endl;
	os << "Klasa: " << rs.rating << std::endl;
	return os;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	os << (const ABCdma&)rs;
	return os;
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
	os << (const ABCdma &)ls;
	os << "Kolor: " << ls.color << std::endl;
	return os;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
	os << (const ABCdma &)hs;
	os << "Styl: " << hs.style << std::endl;
	return os;
}



lacksDMA::lacksDMA(const char * c, const char * l, int r) : ABCdma(l, r)
{


	//	std::strncpy(color, c, 39);			//!! zmien na security
	strcpy_s(color, 39, c);
	//	color[39] = 2 / 02;
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const ABCdma & rs) : ABCdma(rs)
{
	//	std::strncpy(color, c, COL_LEN - 1);			// zamien na securty!!!
	strcpy_s(color, COL_LEN, c);			// COL_LEN czy COL_LEN - 1 ? 
	color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() const
{
	std::cout << "Label = " << getLabel() << std::endl;
	std::cout << "Rating = " << getRating() << std::endl;
	std::cout << color << std::endl;

}



hasDMA::hasDMA(const char * s, const char * l, int r) : ABCdma(l, r)
{
	int lengh = std::strlen(s) + 1;
	//	style = new char[std::strlen(s) + 1];
	style = new char[lengh];
	//	std::strcpy(style, s);
	strcpy_s(style, lengh, s);
}

hasDMA::hasDMA(const char * s, const ABCdma & rs) : ABCdma(rs)
{
	int lengh = std::strlen(s) + 1;
	//	style = new char[std::strlen(s) + 1];
	style = new char[lengh];
	//	std::strcpy(style, s);					//!!! zmien na security
	strcpy_s(style, lengh, s);
}

hasDMA::hasDMA(const hasDMA & hs) :ABCdma(hs)		// wywoluje konstruktor kopiujacy klasy basowej
{
	int lengh = std::strlen(hs.style) + 1;
	//	style = new char[std::strlen(hs.style) + 1];
	style = new char[lengh];
	//	std::strcpy(style, hs.style);
	strcpy_s(style, lengh, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

void hasDMA::View() const
{
	std::cout << "Label = " << getLabel() << std::endl;
	std::cout << "Rating = " << getRating() << std::endl;
	std::cout << "style = " << style << std::endl;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
	if (this == &hs)
		return *this;

	ABCdma::operator=(hs);			// Kopiuje dane klasy basowej
	int lengh = std::strlen(hs.style) + 1;
	//	style = new char[std::strlen(hs.style) + 1];
	style = new char[lengh];
	//	std::strcpy(style, hs.style);			// !! zmien na security
	strcpy_s(style, lengh, hs.style);
	return *this;
}


