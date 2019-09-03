#pragma once
#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad
{
	private:
		char * str;		//wskaznik ciagu
		int len;		// dlugosc ciagu
		static int num_strings;	// licznik utworzonych obiektow 
	public:
		StringBad(const char * s);	
		StringBad();
		~StringBad();
		friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};


#endif


