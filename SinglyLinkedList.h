#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <stdio.h>
#include "Node.h"

template<class T>
class SinglyLinkedList
{
public:
	SinglyLinkedList<T>()
	{
		pHead = pTail = 0;
	};

	~SinglyLinkedList<T>()
	{
		Node<T> * tmp;
		while (pTail != pHead)
		{
			tmp = pHead;
			pHead = pHead->next;
			delete tmp;
		}
		if (pHead)
		{
			delete pHead;
		}
	}

	void insertHead(T & t);
	void insertTail(T & t);
	T deleteFromHead();
	T deleteFromTail();
	bool deleteIndex(const T & t);
	bool isEmpty() const;
	bool isInList(const T & t) const;
private:
	Node<T> * pHead, * pTail;
};

template <class T>
inline void SinglyLinkedList<T>::insertHead(T & t)
{
	if (pHead)
	{
		Node<T> * tmp = new Node<T>;
		tmp->data = t;
		tmp->next = pHead;
		pHead = tmp;
	}
	else
	{
		pHead = pTail = new Node<T>;
		pHead->data = t;
	}
}

template <class T>
inline T SinglyLinkedList<T>::deleteFromHead()
{
	T d = pHead->data;
	if (pHead == pTail)
	{
		delete pHead;
		pHead = pTail = 0;
	}
	else
	{
		Node<T> * tmp = pHead->next;
		delete pHead;
		pHead = tmp;
	}
	return d;
}

template<class T>
inline void SinglyLinkedList<T>::insertTail(T & t)
{
	if (pHead)
	{
		pTail->next = new Node < T >;
		pTail = pTail->next;
		pTail->data = t;
	}
	else
	{
		pHead = pTail = new Node < T >;
		pHead->data = t;
	}
}

template<class T>
inline T SinglyLinkedList<T>::deleteFromTail()
{
	T d = pTail->data;
	if (pHead == pTail)
	{
		delete pHead;
		pHead = pTail = 0;
	}
	else
	{
		Node<T> * tmp;
		for (tmp = pHead; tmp->next != pTail; tmp = tmp->next);
		delete pTail;
		pTail = tmp;
		pTail->next = 0;
	}
	return d;
}

template < class T >
inline bool SinglyLinkedList<T>::deleteIndex(const T & t)
{
	if (pHead)
	{	
		Node<T> * tmp, * prev;
		if (pHead == pTail && pHead->data == t) // if only one node and node matches index
		{
			delete pHead;
			pHead = pTail = 0;
			return true;
		}
		else if (pHead->data == t) // if multiple nodes and pHead matches index
		{
			tmp = pHead->next;
			delete pHead;
			pHead = tmp;
			return true;
		}
		else // if multiple nodes and pHead does not match index
		{
			for (prev = pHead, tmp = pHead->next; tmp != 0 && tmp->data != t; prev = prev->next, tmp = tmp->next);
			if (tmp != 0)
			{
				if (tmp == pTail)
					pTail = prev;
				prev->next = tmp->next;
				delete tmp;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

template<class T>
inline bool SinglyLinkedList<T>::isEmpty() const
{
	return (pHead) ? false : true;
}

template<class T>
inline bool SinglyLinkedList<T>::isInList(const T & d) const
{
	if (pHead)
	{
		Node<T> * tmp;
		for (tmp = pHead; tmp != 0 && tmp->data != d; tmp = tmp->next);
		if (tmp != 0)
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}

#endif