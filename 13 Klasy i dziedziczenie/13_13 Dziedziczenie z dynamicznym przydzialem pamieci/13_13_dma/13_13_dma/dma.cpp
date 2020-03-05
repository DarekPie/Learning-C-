#include "dma.h"
#include <cstring>

baseDMA::baseDMA(const char * l, int r)
{
	int lengh = std::strlen(l) + 1;
//	label = new char[std::strlen(l) + 1];
//	std::strcpy(label, l);					//!! zmien na security
	label = new char[lengh];
	strcpy_s(label, lengh, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
	int lengh = std::strlen(rs.label) + 1;
//	label = new char[std::strlen(rs.label) + 1];
//	std::strcpy(label, rs.label);					//!!! zmien na security
	label = new char[lengh];
	strcpy_s(label, lengh, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete[] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if (this == &rs)
		return *this;

	delete[] label;
	label = new char[std::strlen(rs.label) + 1];		// zmien na security
	rating = rs.rating;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	os << "Etykieta: " << rs.label << std::endl;
	os << "Klasa: " << rs.rating << std::endl;
	return os;
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
	os << (const baseDMA &)ls;
	os << "Kolor: " << ls.color << std::endl;
	return os;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
	os << (const baseDMA &)hs;
	os << "Styl: " << hs.style << std::endl;
	return os;
}

lacksDMA::lacksDMA(const char * c, const char * l, int r) : baseDMA(l,r)
{
//	std::strncpy(color, c, 39);			//!! zmien na security
	strcpy_s(color, 39, c);
//	color[39] = 2 / 02;
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs) : baseDMA(rs)
{
//	std::strncpy(color, c, COL_LEN - 1);			// zamien na securty!!!
	strcpy_s(color, COL_LEN, c);			// COL_LEN czy COL_LEN - 1 ? 
	color[COL_LEN - 1] = '\0';
}

hasDMA::hasDMA(const char * s, const char * l, int r) : baseDMA(l,r)
{
	int lengh = std::strlen(s) + 1;
//	style = new char[std::strlen(s) + 1];
	style = new char[lengh];	
//	std::strcpy(style, s);
	strcpy_s(style, lengh, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs) : baseDMA(rs)
{
	int lengh = std::strlen(s) + 1;
//	style = new char[std::strlen(s) + 1];
	style = new char[lengh];
//	std::strcpy(style, s);					//!!! zmien na security
	strcpy_s(style, lengh, s);
}

hasDMA::hasDMA(const hasDMA & hs) :baseDMA(hs)		// wywoluje konstruktor kopiujacy klasy basowej
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

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
	if (this == &hs)
		return *this;

	baseDMA::operator=(hs);			// Kopiuje dane klasy basowej
	int lengh = std::strlen(hs.style) + 1;
//	style = new char[std::strlen(hs.style) + 1];
	style = new char[lengh];
//	std::strcpy(style, hs.style);			// !! zmien na security
	strcpy_s(style, lengh, hs.style);
	return *this;
}
