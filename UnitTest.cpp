#include <iostream>
#include <fstream>
#include "SinglyLinkedList.h"
using namespace std;

int main()
{
	fstream output;
	SinglyLinkedList< int > * list;

	output.open("unit_test_output.txt", ios_base::out);
	int arr[10], arr2[10];
	for (int i = 0; i < 10; i++)
		arr[i] = i;
	for (int i = 0; i < 10; i++)
		arr2[i] = i + 10;

	// output seed array
	output << "Array = [";
	for (int i = 0; i < 10; i++)
	{
		if (i < 9)
		{
			output << arr[i] << ", ";
		}
		else
		{
			output << arr[i];
		}
	}
	output << "]" << endl;

	// test deleteFromHead() with insertHead()
	list = new SinglyLinkedList < int >;

	for (int & i : arr)
	{
		list->insertHead(i);
	}
	output << "SinglyLinkedList<T>::deleteFromHead() using SinglyLinkedList<T>::insertHead() to populate" << endl;
	while (!list->isEmpty())
	{
		output << list->deleteFromHead() << endl;
	}

	delete list;

	// test deleteFromHead() with insertTail()
	list = new SinglyLinkedList < int >;

	for (int & i : arr)
	{
		list->insertTail(i);
	}
	output << "SinglyLinkedList<T>::deleteFromHead() using SinglyLinkedList<T>::insertTail() to populate" << endl;
	while (!list->isEmpty())
	{
		output << list->deleteFromHead() << endl;
	}

	delete list;
	
	// test deleteFromTail() with insertTail()
	list = new SinglyLinkedList < int >;
	
	for (int & i : arr)
	{
		list->insertTail(i);
	}
	output << "SinglyLinkedList<T>::deleteFromTail() using SinglyLinkedList<T>::insertTail() to populate" << endl;
	while (!list->isEmpty())
	{
		output << list->deleteFromTail() << endl;
	}
	
	delete list;

	// test deleteFromTail() with insertTail()
	list = new SinglyLinkedList < int >;

	for (int & i : arr)
	{
		list->insertHead(i);
	}
	output << "SinglyLinkedList<T>::deleteFromTail() using SinglyLinkedList<T>::insertHead() to populate" << endl;
	while (!list->isEmpty())
	{
		output << list->deleteFromTail() << endl;
	}

	delete list;

	// test deleteIndex() forward iteration
	list = new SinglyLinkedList < int >;

	for (int & i : arr)
	{
		list->insertHead(i);
	}

	output << "SinglyLinkedList<T>::deleteIndex() forward iteration" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (list->deleteIndex(arr[i]))
			output << i << " : True" << endl;
		else
			output << i << " : False" << endl;
	}

	delete list;

	// test deleteIndex() reverse iteration
	list = new SinglyLinkedList < int >;

	for (int & i : arr)
	{
		list->insertTail(i);
	}

	output << "SinglyLinkedList<T>::deleteIndex() reverse iteration" << endl;
	for (int i = 10; i > 0; i--)
	{
		if (list->deleteIndex(arr[i - 1]))
			output << arr[i - 1] << " : True" << endl;
		else
			output << arr[i - 1] << " : False" << endl;
	}

	delete list;

	// test deleteIndex() for non-existing elements
	list = new SinglyLinkedList < int >;

	for (int & i : arr)
	{
		list->insertTail(i);
	}

	output << "SinglyLinkedList<T>::deleteIndex() for non-existing elements" << endl;
	for (int & i : arr2)
	{
		if (list->deleteIndex(i))
			output << i << " : True" << endl;
		else
			output << i << " : False" << endl;
	}

	delete list;

	// test isInList()
	list = new SinglyLinkedList < int >;

	for (int & i : arr)
	{
		list->insertHead(i);
	}

	output << "SinglyLinkedList<T>::isInList() for existing elements" << endl;

	for (int & i : arr)
	{
		if (list->isInList(i))
			output << i << " : True" << endl;
		else
			output << i << " : False" << endl;
	}

	output << "SinglyLinkedList<T>::isInList() for non-existing elements" << endl;
	for (int & i : arr2)
	{
		if (list->isInList(i))
			output << i << " : True" << endl;
		else
			output << i << " : False" << endl;
	}

	delete list;

	// test isEmpty()
	list = new SinglyLinkedList < int >;
	output << "SinglyLinkedList<T>::isEmpty() for empty list" << endl;
	if (list->isEmpty())
		output << "True" << endl;
	else
		output << "False" << endl;

	output << "SinglyLinkedList<T>::isEmpty() for non-empty list" << endl;
	for (int i = 0; i < 10; i++)
	{
		list->insertHead(arr[i]);
	}

	if (list->isEmpty())
		output << "True" << endl;
	else
		output << "False" << endl;
	output.close();

	return 0;
}