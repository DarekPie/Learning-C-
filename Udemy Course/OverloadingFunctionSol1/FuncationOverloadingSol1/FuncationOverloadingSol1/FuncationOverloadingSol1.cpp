#include "Mystring.h"
#include <iostream>

using namespace std;
int main()
{
	cout << "Franks" << endl;
	MyString a{ "frank" };
	MyString b{ "frank" };
	cout << (a==b) << endl;
	cout << (a!=b) << endl << endl;

	cout << "Franks and Georrge" << endl;
	b = "george";	
	cout << (a == b) << endl;
	cout << (a != b) << endl;
	cout << (a < b) << endl;
	cout << (a > b) << endl << endl;

	MyString s1{ "FRANK" };
	cout << s1 << endl;
	s1 = -s1;
	cout << s1 << endl << endl;

	s1 = s1 + "*********";
	cout << s1 << endl;
	s1 += "-------";
	cout << s1 << endl << endl;

	MyString s2{ "12345" };
	s1 = s2 * 3;
	cout << s1 << endl;

	MyString s3{ "abcdef" };
	s3 *= 5;
	cout << s3 << endl << endl;

	MyString repeat_string;
	int repeat_times;
	cout << "Enter a string to repeat: " << endl;
	cin >> repeat_string; 
	cout << "How Many times would you like it to repeated?" << endl;
	cin >> repeat_times;
	repeat_string *= repeat_times;
	cout << "The result string is: " << repeat_string << endl << endl;

	cout << "*****************" << endl;
	cout << (repeat_string * 12) << endl << endl;

	repeat_string = "RepeatMe";
	cout << (repeat_string + repeat_string + repeat_string) << endl << endl;

	repeat_string += (repeat_string * 3);
	cout << repeat_string << endl << endl;

	MyString s = "Frank";
	++s;
	cout << s << endl;
	s = -s;
	cout << s << endl << endl;
// error	
	MyString result;
	result = s++;
	//cout << s << endl;
	//cout << result << endl << endl;


	return 0;
}
