#include <iostream>
#include "Mystring.h"
#include <cstring>

MyString::MyString() : str{ nullptr }
{
	str = new char[1];
	*str = '\0';
}

MyString::MyString(const char * s) : str{ nullptr }
{
	if (s == nullptr)
	{
		str = new char[1];
		*str = '\0';
	}
	else
	{
		int len = strlen(s) + 1;
		str = new char[len];
		strcpy_s(str, len, s);
	}
}

MyString::MyString(const MyString & obj) : str{ nullptr }
{
	int len = strlen(obj.str) + 1;
	str = new char[len];
	strcpy_s(str, len, obj.str);

}

MyString::MyString(MyString && obj) :str{obj.str}
{
	obj.str = nullptr;
//	std::cout << "Move constructor - moving resources: " << *str << std::endl;
}

MyString::~MyString()
{
	delete[] str;
}

MyString & MyString::operator=(const MyString & obj)
{
	if (this == &obj)
		return *this;
	delete[] str;
	int len = strlen(obj.str) + 1;
	str = new char[len];					// BRAK BY£, ISTOTNY JAK CHOLERA!
	strcpy_s(str, len + 1, obj.str);
	return *this;
}

MyString & MyString::operator=(MyString && obj)
{
//	std::cout << "Using move assignment" << std::endl;
	if (this == &obj)
		return *this;
	delete[] str;
	str = obj.str;
	obj.str = nullptr;
	return *this;

}

void MyString::display() const
{
	std::cout << str << " : " << get_lengh() << std::endl;
}

int MyString::get_lengh() const
{
	return strlen(str);
}

const char * MyString::get_str() const
{
	return nullptr;
}

MyString MyString::operator-() const
{
	int len = std::strlen(str);
	char *buff = new char[len + 1];
//	std::strcpy(buff, str);
	strcpy_s(buff, len + 1, str);
	for (size_t i = 0; i < len; i++)
		buff[i] = tolower(buff[i]);  

	MyString temp{ buff };
	delete[] buff;

	return temp;
}

MyString MyString::operator+(const MyString & rhs) const
{
	int len = std::strlen(str) + std::strlen(rhs.str);
	char  *buff = new char[len + 1];

	strcpy_s(buff, len + 1, str);
//	std::strcat(buff, rhs.str);
	strcat_s(buff, len + 1,  rhs.str);
	MyString temp{buff};
//	if(buff)
//		delete [] buff;
//	buff = nullptr;
	return temp;
}

bool MyString::operator==(const MyString & rhs) const
{
	return(std::strcmp(str, rhs.str) == 0);
}

bool MyString::operator!=(const MyString & rhs) const
{
	return (std::strcmp(str, rhs.str) != 0);
}

bool MyString::operator<(const MyString & rhs) const
{
	return(std::strcmp(str, rhs.str) < 0);
}

bool MyString::operator>(const MyString & rhs) const
{
	return(std::strcmp(str, rhs.str) > 0);
}

MyString & MyString::operator+=(const MyString & rhs)
{

	*this = *this + rhs;					//odwoluje sie do  MyString::operator+(const MyString & rhs) const;
	return *this;
}

// powtarzanie - repeating
MyString MyString::operator*(int n) const
{
	MyString temp;
	for (int i = 1; i <= n; i++)
		temp = temp + *this;
	return temp;


	// ewemtualnie!		
/*	size_t buff_size = std::strlen(str) * n + 1;
	char *buff = new char[buff_size];
	strcpy(buff, "");								// VS moze miec problem - wtedy stosowac strcpy_s("", "", "");
	for (int i = 1; i <= n; i++)
		strcat(buff, str);
	MyString temp2(buff);
	delete[] buff;
	return temp;
*/
}

MyString & MyString::operator*=(int n)
{
	*this = *this * n;						// odwoluje sie do MyString::operator*(int n) const;
	return *this;
}

MyString & MyString::operator++()					//preincrement			-> error!!!!!!!!!!
{
	for (size_t i = 0; i < std::strlen(str); i++)
		str[i] = toupper(str[i]);
	return *this;
}

MyString MyString::operator++(int)					// post increment
{
	MyString temp(*this);			//make a copy
	operator++();					
	return temp;
}

std::ostream & operator<<(std::ostream & os, const MyString & obj)
{
	os << obj.str;
	return os;
}

std::istream & operator>>(std::istream & in, MyString & obj)
{
	char *buff = new char[1000];			// ostroznie liczac ze moze sie tyle nada
	in >> buff;
	obj = MyString{ buff };					// nie za bardzo rozumiem 
	delete[] buff;
	return in;								// zwracamy przez referencje!

}
