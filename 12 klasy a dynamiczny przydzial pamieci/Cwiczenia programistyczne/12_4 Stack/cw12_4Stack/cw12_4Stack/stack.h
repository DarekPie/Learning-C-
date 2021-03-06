#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
	private:
		enum {MAX = 10};
		Item * pitems;
		int size;									// liczba elementow 
		int top;									// indeks szczytu
	public:
		Stack(int n = 10);							// tworzy stos o pojemnosci n elementow
		Stack(const Stack & st);
		~Stack();
		bool isempty() const;
		bool isfull() const;
		bool push(const Item & item);
		bool pop(Item & item);
		Stack & operator=(const Stack & st);
};

// kontruktor kopiujacy
// operator przypisania
// pamiec przydziolona dynamicznie

#endif // !STACK_H_

