#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
#include <cstring>

class MyString
{
	private:
		char * str;

	public:
		MyString();
		MyString(const char *s);
		MyString(const MyString &source);
		MyString(MyString &&source);			// konstruktor przemieszczenia
		~MyString();

		MyString &operator=(const MyString &obj);	// operator kopiowania
		MyString &operator=(MyString &&obj);		//operator przemieszczenia

		void display() const;
		int get_length() const;
		const char *get_str() const;

		friend MyString operator-(const MyString &obj);
		friend MyString operator+(const MyString &lhs, const MyString &rhs);
		friend bool operator==(const MyString &lhs, const MyString &rhs);
		friend bool operator!=(const MyString &lhs, const MyString &rhs);
		friend bool operator<(const MyString &lhs, const MyString &rhs);
		friend bool operator>(const MyString &lhs, const MyString &rhs);
		friend MyString &operator+=(MyString &lhs, const MyString &rhs); // s1+= s2 - konkatynacja i przypisani
		friend MyString operator*(const MyString &lhs, int n);			//s1 = s2 * 3 - powtarzanie 3 razy s2
		friend MyString &operator*=(MyString &lhs, int n);				// s1 = s1 * 3
		friend MyString &operator++(MyString &obj);						//++s1 - preinkrementacja uppercase
		friend MyString operator++(MyString &obj, int);					//s1++ - post-inkremetacja uppercase
		friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
		friend std::istream &operator>>(std::istream &in, MyString &rhs);
};

#endif // _MYSTRING_H_
