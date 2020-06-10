#ifndef  STOCK_h_
#define STOCK_H_

typedef unsigned long Item;

class Stack
{
	private:
		enum {MAX = 10}; // stala zasiegu klasy
		Item items[MAX];			// przechowuje elementy stosu
		int top;					// Indeks sczytowego elementu stosu

	public:
		Stack();
		bool isempty() const;
		bool isfull() const;
		//push() zwraca false, jesli stos jest juz pelen (true w pozostalych przypadkach)
		bool push(const Item & item);
		//pop() zwraca false, jesli stos jest juz pusty ( true w pozostalych przypadkach)
		bool pop(Item & item);
};

#endif // ! STOCK_h_
