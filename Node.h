#ifndef NODE_H
#define NODE_H

template<class T>
class Node 
{
public:
	// constructor/destructor
	Node<T>()
	{
		next = 0;
	};

	Node<T>(Node<T> & n) : data(n.data), next(n.next)
	{};

	~Node<T>()
	{
	};

	// overloaded operators
	Node<T> & operator = (T & t)
	{
		data = t;
		return *this;
	};

	// member functions
	const T & getData()
	{
		return data;
	};
	void putData(const T & t)
	{
		data = t;
	};

	Node<T> & getNext()
	{
		return next;
	};

	void nullifyNext()
	{
		next = 0;
	};

	bool hasNext()
	{
		return (next) ? true : false;
	};

	// data members
	T data;
	Node<T> * next;
};

#endif