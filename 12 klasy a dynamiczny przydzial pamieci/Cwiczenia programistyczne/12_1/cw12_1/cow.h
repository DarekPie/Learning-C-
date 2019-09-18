#ifndef COW1_H_
#define COW1_H_

#include <iostream>
using std::ostream;
using std::istream;

class Cow {
	private:
		char name[20];
		char * hobby;
		double weight;
	public:
		Cow();
		Cow(const char* nm, const char* ho, double wt);
		Cow(const Cow& c);
		~Cow();
		Cow & operator=(const Cow& c);
		void ShowCow() const;

};

#endif

