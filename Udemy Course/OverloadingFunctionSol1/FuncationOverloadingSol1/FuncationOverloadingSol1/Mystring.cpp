#include <iostream>
#include "Mystring.h"
#include <cstring>
#include <stdio.h>
#include <ctype.h>
MyString::MyString() : str{ nullptr }
{
	str = new char[1];
	*str = '\0';
}

MyString::MyString(const char * s) : str{ nullptr }
{

}

MyString::MyString(const MyString & obj) : str{ nullptr }
{
	int len = strlen(obj.str) + 1;
	str = new char[len];
	strcpy_s(str, len, obj.str);

}

MyString::MyString(MyString && obj)
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

MyString MyString::operator-() const
{
	int len = std::strlen(str);
	char *buff = new char[len + 1];
	std::strcpy(buff, str);
	for (size_t i = 0; i < len; i++)
		buff[i] = tolower(buff[i]);  

	MyString temp{ buff };
	delete[] buff;

	return temp;
}

MyString MyString::operator+(const MyString & rhs) const
{
	return MyString();
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
