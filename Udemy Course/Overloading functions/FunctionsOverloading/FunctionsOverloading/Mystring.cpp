#include <iostream>
#include "Mystring.h"
#include <cstring>
MyString::MyString() : str{nullptr}
{
	str = new char[1];
	*str = '\0';
}

MyString::MyString(const char * s) : str { nullptr }
{

}

MyString::MyString( MyString & obj) : str(nullptr)
{
	int len = strlen(obj.str) + 1;
	str = new char[len];
	strcpy_s(str, len, obj.str);
	
}

MyString::MyString(const MyString && obj)
{
}

MyString::~MyString()
{
	delete[] str;
}

MyString & MyString::operator=(const MyString & obj)
{
	// TODO: tu wstawiæ instrukcjê return
}

MyString & MyString::operator=(MyString && obj)
{
	// TODO: tu wstawiæ instrukcjê return
}

void MyString::display() const
{
}

int MyString::get_lengh() const
{
	return 0;
}

const char * MyString::get_str() const
{
	return nullptr;
}

bool operator<(const MyString & lobj, const MyString & robj)
{
	return false;
}

bool operator>(const MyString & lobj, const MyString & robj)
{
	return false;
}

MyString operator-(const MyString & obj)
{
	return MyString();
}

MyString operator+(const MyString & lobj, const MyString & robj)
{
	return MyString();
}

MyString operator+=(const MyString & lobj, const MyString & robj)
{
	return MyString();
}

MyString operator*(const MyString & lobj, const MyString & robj)
{
	return MyString();
}

MyString operator*=(const MyString & lobj, const MyString & robj)
{
	return MyString();
}

std::ostream & operator<<(std::ostream & os, const MyString & obj)
{
	// TODO: insert return statement here
}

std::istream & operator>>(std::istream & in, const MyString & obj)
{
	// TODO: insert return statement here
}
