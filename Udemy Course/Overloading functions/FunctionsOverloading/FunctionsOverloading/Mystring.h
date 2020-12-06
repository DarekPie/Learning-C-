#pragma once

#include <iostream>

class MyString {

	private:
		char *str;

	public:
		MyString();
		MyString(const char *s);
		MyString( MyString &obj);
		MyString(const MyString &&obj);			//Move constructor
		~MyString();

};
