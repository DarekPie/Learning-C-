#ifndef  STKCTP2_H_
#define STKCTP2_H_

template <class Type>
class Stack
{
	private:
		enum {SIZE = 10};			//rozmiar domyslny
		int stacksize;
		Type * items;				// przechowuje elementy stosu
		int top;					// Indeks elementu na gorze stosu

	public:
		explicit Stack(int ss = SIZE);
		Stack(const Stack & st);
		~Stack() { delete[] items; }
		bool isempty() { return top == 0; }
		bool isfull() { return top == stacksize; }
		bool push(const Type & item);					// Umieszcza element na stosie
		bool pop(Type & item);							// Zdejmuje element ze stosu i umieszcza w obiekcie item
		Stack & operator=(const Stack & st);
};

template <class Type>
Stack<Type>::Stack(int ss) : stacksize(ss), top(0)
{
	items = new Type[stacksize];
}

template <class Type>
Stack<Type>::Stack(const Stack & st)
{
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}

template <class Type>
bool Stack<Type>::push(const Type & item)
{
	if (top < stacksize)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <class Type>
bool Stack<Type>::pop(Type & item)
{
	if (top > 0) 
	{
		item = items[--top];
		return true;
	}
	else
		return false;
	
}


template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
{
	if (this == &st)
		return *this;

	delete[] items;
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
	return *this;
}

#endif // ! STKCTP2_H_


