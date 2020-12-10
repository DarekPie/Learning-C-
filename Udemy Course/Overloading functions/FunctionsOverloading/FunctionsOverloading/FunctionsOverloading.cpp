
#include <iostream>
#include "Mystring.h"
using namespace std;

int main()
{
    cout << "Hello World!\n";

	MyString a{ "frank" };
	MyString b{ "frank" };

	cout << (a==b) << endl;		//true

}

