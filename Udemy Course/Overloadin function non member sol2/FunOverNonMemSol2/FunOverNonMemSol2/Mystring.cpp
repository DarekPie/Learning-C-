#include "Mystring.h"
#include <iostream>
#include <cstring>

MyString::MyString() : str{nullptr}
{
	str = new char[1];
	*str = '\0';
}

// Przeci¹¿ony konstruktor
MyString::MyString(const char * s) : str{nullptr}
{
	if (s == nullptr)
	{
		str = new char[1];
		*str = '\0';
	}
	else
	{
		int len = strlen(s);
		str = new char[len + 1];
		strcpy_s(str, len + 1, s);
	}
}

//Konstruktor kopiuj¹cy
MyString::MyString(const MyString & source) : str{nullptr}
{
	int len = strlen(source.str);
	str = new char[len + 1];
	strcpy_s(str, len + 1, source.str);
}

//Konstruktor przenosz¹cy
MyString::MyString(MyString && source) : str{source.str}
{
	source.str = nullptr;
}

MyString::~MyString()
{
	delete[] str;
}

// operator przypisania
MyString & MyString::operator=(const MyString & obj)
{
	if (this == &obj)
		return *this;
	delete[] str;
	int len = strlen(obj.str);
	str = new char[len + 1];
	strcpy_s(str, len + 1, obj.str);
	return *this;
}

MyString & MyString::operator=(MyString && obj)
{
	if (this == &obj)
		return *this;
	delete[]str;
	str = obj.str;
	obj.str = nullptr;
	return *this;
}

void MyString::display() const
{
	std::cout << str << " : " << get_length() << std::endl;
}

//getters
int MyString::get_length() const {	return strlen(str);  }
const char * MyString::get_str() const {	return str;	}


//Wszystkie litery male
MyString operator-(const MyString & obj)
{
	int len = strlen(obj.str);
	char *buff = new char[len + 1];
	strcpy_s(buff, len + 1, obj.str);

	for (size_t i = 0; i < (len + 1); i++)
		buff[i] = tolower(buff[i]);

	MyString temp{ buff };
	delete[] buff;
	return temp; 
}

//Konkatynacja 
MyString operator+(const MyString & lhs, const MyString & rhs)
{
	int len = strlen(lhs.str) + strlen(rhs.str);
	char *buff = new char[len + 1];
	strcpy_s(buff, len + 1, lhs.str);
	strcat_s(buff, len + 1, rhs.str);
	MyString temp{ buff };
	delete[] buff;
	return temp;
}

bool operator==(const MyString & lhs, const MyString & rhs){	return strcmp(lhs.str, rhs.str) == 0;	}
bool operator!=(const MyString & lhs, const MyString & rhs){	return strcmp(lhs.str, rhs.str) != 0;	}
bool operator<(const MyString & lhs, const MyString & rhs){		return strcmp(lhs.str, rhs.str) < 0;	}
bool operator>(const MyString & lhs, const MyString & rhs){		return strcmp(lhs.str, rhs.str) > 0;	}

// konkatynacja i przypisanie
MyString & operator+=(MyString & lhs, const MyString & rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

// powtarzanie
MyString operator*(const MyString & lhs, int n)
{
	MyString temp;
	for (int i = 1; i <= n; i++)
		temp = temp + lhs;
	return temp;

}

//Powtarzanie i przypisanie
MyString & operator*=(MyString & lhs, int n)
{
	lhs = lhs * n;			// odwoluje sie do  MyString operator*(const MyString & lhs, int n)
	return lhs;
}

//Uppercase - preincrement
MyString & operator++(MyString & obj)
{
	for (size_t i = 0; i < strlen(obj.str); i++)
		obj.str[i] = toupper(obj.str[i]);
	return obj;
}
// Uppercase - postincrementacja
MyString operator++(MyString & obj, int)
{
	MyString temp{ obj };
	++obj;						// odwlouje sie do MyString & operator++(MyString & obj)
	return temp;
}

std::ostream & operator<<(std::ostream & os, const MyString & rhs)
{
	os << rhs.str;
	return os;
}

std::istream & operator>>(std::istream & in, MyString & rhs)
{
	char *buff = new char[1000];
	in >> buff;
	rhs = MyString{ buff };
	delete[] buff;
	return in;
}

