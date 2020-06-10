#include "stock.h"

Stack::Stack()
{
	top = 0;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

// Komenda PUSH - dodaj kolejny element na szczyt stosu
bool Stack::push(const Item & item)		
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}
// Komenda POP  - zdejmij jeden element ze szczytu stosu
bool Stack::pop(Item & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}
