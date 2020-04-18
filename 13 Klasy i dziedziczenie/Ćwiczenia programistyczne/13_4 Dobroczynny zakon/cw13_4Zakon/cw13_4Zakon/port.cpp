#include <iostream>
#include "port.h"
#include <cstring>

// klasa Port
Port::Port(const char *br, const char *st, int b)
{
	int lenghBrand = std::strlen(br) + 1;
	brand = new char[lenghBrand];
	strcpy_s(brand, lenghBrand, br);

//	int lenghStyle = std::strlen(st) + 1;
	strcpy_s(style, 21, st);
	bottles = b;
}


Port::Port(const Port &p)
{
	int lenghBrand = std::strlen(p.brand) + 1;
	brand = new char[lenghBrand];
	strcpy_s(brand, lenghBrand, p.brand);

	strcpy_s(style, 21, p.style);
	bottles = p.bottles;

}

Port &Port::operator=(const Port &p)
{
	if (this == &p)
		return *this;

	delete[] brand;
	delete style;

	int lenghBrand = std::strlen(p.brand) + 1;
	brand = new char[lenghBrand];
	strcpy_s(brand, lenghBrand, p.brand);

	strcpy_s(style, 21, p.style);
	bottles = p.bottles;

	return *this;
}

Port &Port::operator+=(int b)
{
	this->bottles += b;
	return *this;
}

Port &Port::operator-=(int b)
{
	this->bottles -= b;
	return *this;
}

void Port::Show() const
{
	cout << "Marka: " << brand << endl;
	cout << "Rodzaj: " << style  << endl;
	cout << "Butelek: " << bottles  << endl;
}

ostream &operator<<(ostream &os, const Port &p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles << endl;
	return os;
}


VitagePort::VitagePort(const char * br, int b, const char *nn, int y) : Port(br, "", b)
{
	int lenghNickName = std::strlen(nn) + 1;
	nickname = new char[lenghNickName];
	strcpy_s(nickname, lenghNickName, nn);

	year = y;
}

VitagePort::VitagePort(const VitagePort &vp) : Port(vp)
{
	int lenghNickName = std::strlen(vp.nickname) + 1;
	nickname = new char[lenghNickName];
	strcpy_s(nickname, lenghNickName, vp.nickname);

	year = vp.year;
}

VitagePort &VitagePort::operator=(const VitagePort &vp)
{
	if (this == &vp)
		return *this;

	Port::operator=(vp);

	int lenghNickName = std::strlen(vp.nickname) + 1;
	nickname = new char[lenghNickName];
	strcpy_s(nickname, lenghNickName, vp.nickname);

	year = vp.year;

}

void VitagePort::Show() const
{
	Port::Show();

	cout << "Nazwa: " << nickname << endl;
	cout << "Rocznik: " << year << endl;
}

ostream &operator<<(ostream &os, const VitagePort &vp)
{
	os << (const Port &)vp;
	os << ", " << vp.nickname << ", " << vp.year << endl;

	return os;
}