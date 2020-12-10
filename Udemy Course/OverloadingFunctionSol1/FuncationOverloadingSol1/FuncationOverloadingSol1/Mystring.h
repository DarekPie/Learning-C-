#pragma once

#include <iostream>

class MyString {

private:
	char *str;

public:
	MyString();
	MyString(const char *s);
	MyString(const MyString &source);		//Copy constructor
	MyString(MyString &&source);			//Move constructor
	~MyString();

	MyString &operator=(const MyString &rhs);		// copy assignment
	MyString &operator=(MyString &&rhs);			// move assignment 

	void display() const;

	int get_lengh() const;
	const char *get_str() const;

	MyString operator-() const;							// robi male litery
	MyString operator+(const MyString &rhs) const;		// konkatynacja
	bool operator==(const MyString &rhs) const;			// porownanie
	bool operator!=(const MyString &rhs) const;			// nie jest rowne
	bool operator<(const MyString &rhs) const;			// mniejsze niz
	bool operator>(const MyString &rhs) const;			// wieksze niz
	MyString &operator+=(const MyString &rhs);			// s1 += s2; przypisanie i konkatynacja
	MyString operator*(int n) const;					// s1 = s2 * 3; powtorz s2 n razy
	MyString &operator*=(int n);						// s1 *= 3; s1 = s1 * 3;
	MyString &operator++();								//pre-inkrementcja ++s1;
	MyString operator++(int);							// post-inkrementacja s1++;


/*
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
*/
};
