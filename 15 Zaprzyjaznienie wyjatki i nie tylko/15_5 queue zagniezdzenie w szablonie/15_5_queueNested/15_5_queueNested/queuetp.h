#pragma once

template <class Item>
class QueueTP
{
private:
	enum{Q_SIZE = 10};

	//definicja klasy zagniezdzone Node
	class Node
	{
	public:
		Item item;
		Node *next;
		Node(const Item & i) : item(i), next(0) {}
	};

	Node * front;
	Node * rear;
	int items;
	const int qsize;
	QueueTP(const QueueTP & q) : qsize(0) {}
	QueueTP & operator=(const QueueTP & q) { return *this; }

public:
	QueueTP(int us = Q_SIZE);
	~QueueTP();
	bool isempty() const	{ return items == 0; }
	bool isfull() const		{ return items == qsize; }
	int queuecount() const	{ return items; }
	bool enqueue(const Item & item);
	bool dequeue(Item & item);
};


//Metody klasy QueueTP

template<class Item>
inline QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
	front = rear = 0;
	items = 0;
}

template<class Item>
inline QueueTP<Item>::~QueueTP()
{
	Node * temp;
	while (front != 0)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<class Item>
inline bool QueueTP<Item>::enqueue(const Item & item)
{
	if(isfull())
		return false;
	Node  *add = new Node(item);		// tworzy element
	if (add == NULL)
		return false;					// Jesli to niemozliwe, konczy dzialanie
	items++;
	if (front == 0)						// Jesli kolejka jest pusta
		front = add;					//Dodaje element na poczatek kolejki
	else 
		rear->next = add;				//W Przeciwnym razie dodaje na koniec
	rear = add;							// Koniec kolejki wskazuje na dodany element
	return true;

}

template<class Item>
inline bool QueueTP<Item>::dequeue(Item & item)
{
	if (front == 0)
		return false;
	item = front->item;					// Ustala item na pierwszy element
	items--;
	Node *temp = front;					//Zapisuje adres pierwszego elementu
	front = front->next;				//Ustawia poczatek na nastepny element
	delete temp;						//Usuwa poprzedni poczatek
	if (items == 0)
		rear = 0;
	return true;
}
