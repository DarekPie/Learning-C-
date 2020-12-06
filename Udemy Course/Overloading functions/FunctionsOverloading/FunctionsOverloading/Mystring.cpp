#include <iostream>
#include "Mystring.h"

MyString::MyString()
{
}

MyString::MyString(const char * s)
{
}

MyString::MyString( MyString & obj) : str(nullptr)
{
	int len = strlen(obj.str) + 1;
	str = new char[len];
	strncpy_s(str, len, obj.str);
	strncpy_s()
}

MyString::MyString(const MyString && obj)
{
}

MyString::~MyString()
{
}
