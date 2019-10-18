#ifndef STOCK2_H_
#define STOCK2_H_
#include <iostream>
using std::ostream;
using std::istream;
class Stock
{
	private:
//		char company[30];
		char * company;
		int len;
		static const int CINLIM = 80;
		static int num_companies;
		int shares;
		double share_val;
		double total_val;
		void set_tot() { total_val = shares * share_val;  }
	public:
		static int HowMany();
		Stock();
		Stock(const char * co, int n = 0, double pr = 0.0);
		~Stock();
		void buy(int num, double price);
		void sell(int num, double price);
		void update(double price);
		void show();
		const Stock & topval(const Stock & s) const;
		friend ostream & operator<<(ostream &os, const Stock &st);
};



#endif // !STOCK2_H_
