#ifndef  STACKTP_H_
#define STACKTP_H_

template <class Type>				// moze byc nowszy sposob template <typename Type> 
class Stack
{
	private:
		enum { MAX = 10 };
		Type item[MAX];
		int top;

	public:
		Stack();
		bool isempty();
		bool isfull();
		bool push(const Type & item);
		bool pop(Type & item);
};



#endif // ! STACKTP_H_

