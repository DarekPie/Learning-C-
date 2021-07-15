#include <iostream>
#include <cstring>
#include "queue.h"
#include "worker.h"



int main()
{

	using std::cout;
	using std::cin;
	using std::endl;
	using std::strchr;
    
	QueueTp<Worker> q(3);

	if (q.isempty())
		cout << "Queue is empty" << endl;

	cout << "add worker1 to quque... " << endl;
	Worker w1("Shao", 1);
	q.enqueue(w1);

	cout << "add worker2 to queue..." << endl;
	Worker w2("Zgeng", 2);
	q.enqueue(w2);

	cout << "add worker3 to queue..." << endl;
	Worker w3("Jiang", 3); 
	q.enqueue(w3); 

	if (q.isfull())
		cout << "queue is full" << endl;

	Worker w;
	cout << "delete worker1..." << endl;
	q.dequeue(w);
	w.Show();

}

