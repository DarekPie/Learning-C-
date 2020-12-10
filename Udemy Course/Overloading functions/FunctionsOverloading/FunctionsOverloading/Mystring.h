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

		MyString &operator=(const MyString &obj);		// copy assignment
		MyString &operator=(MyString &&obj);			// move assignment 

		void display() const;
		int get_lengh() const;
		const char *get_str() const;

	

		friend bool operator==(const MyString &lobj, const MyString &robj);
		friend bool operator!=(const MyString &lobj, const MyString &robj);
//		friend MyString operator=(const MyString &lbj, const char characters);


		friend bool operator<(const MyString &lobj, const MyString &robj);
		friend bool operator>(const MyString &lobj, const MyString &robj);
		friend MyString operator-(const MyString &obj);
		friend MyString operator+(const MyString &lobj, const MyString &robj);
		friend MyString operator+=(const MyString &lobj, const MyString &robj);
		friend MyString operator*(const MyString &lobj, const MyString &robj);
		friend MyString operator*=(const MyString &lobj, const MyString &robj);

		friend std::ostream &operator<<(std::ostream &os, const MyString &obj);
		friend std::istream &operator>>(std::istream &in, const MyString &obj);
};
