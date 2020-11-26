#ifndef STACKLL_H
#define STACKLL_H

#include "DoubleLinkedList.h"
#include "Exception.h"

template <class T>
class StackLinkedList
{
public:
	StackLinkedList();
	explicit StackLinkedList(int size);
	StackLinkedList(const StackLinkedList<T>& copy);
	~StackLinkedList();
	StackLinkedList &operator =(const StackLinkedList& copy);
	void Push(const T& item);
	T& Pop();
	const T& Peak();
	int Size() const;
	int getSize() const;
	bool isEmpty() const;
	void Print();
	void PrintIndex(int index);
private:
	DoubleLinkedList<T> m_array;
	int m_size;
	int m_trackSize;
};

template <class T>
StackLinkedList<T>::StackLinkedList() : m_size(0), m_trackSize(0)
{
	if (!m_array.isEmpty())
	{
		throw Exception("Stack Array Default Constructor Error!");
	}
}

template <class T>
StackLinkedList<T>::StackLinkedList(int size) : m_size(size), m_trackSize(0)
{
	if (!m_array.isEmpty())
	{
		throw Exception("Stack Array Overloaded Constructor Error!");
	}
}

template <class T>
StackLinkedList<T>::StackLinkedList(const StackLinkedList<T>& copy) : m_size(copy.m_size), m_trackSize(copy.m_trackSize)
{
	Node<T> *CurrPtr = copy.m_array.getHead();

	for (auto i = 0; i < copy.getSize(); i++)
	{
		m_array.Append(CurrPtr->getData());
		CurrPtr = CurrPtr->getNext();
	}

	if (m_array.First() != copy.m_array.First())
	{
		throw Exception("Stack Array Default Constructor Error!");
	}

}

template<class T>
StackLinkedList<T>::~StackLinkedList() {}

template <class T>
StackLinkedList<T>& StackLinkedList<T>::operator=(const StackLinkedList& copy)
{
	m_size = copy.m_size;
	m_trackSize = copy.m_trackSize;

	Node<T> *CurrPtr = copy.m_array.getHead();

	for (auto i = 0; i < copy.getSize(); i++)
	{
		m_array.Append(CurrPtr->getData());
		CurrPtr = CurrPtr->getNext();
	}

	if (m_array.First() != copy.m_array.First())
	{
		throw Exception("Stack Array Default Constructor Error!");
	}

	return *this;
}

template <class T>
void StackLinkedList<T>::Push(const T& item)
{
	m_array.Append(item);
	m_trackSize++;
}

template <class T>
T& StackLinkedList<T>::Pop()
{
	if (m_trackSize == 0)
	{
		throw Exception("Nothing to Pop Underflow Error!");
	}
	m_trackSize -= 1;
	static T last = m_array.Last();
	m_array.RemoveLast();

	return last;
}

template <class T>
const T& StackLinkedList<T>::Peak()
{
	if (m_trackSize == 0)
	{
		throw Exception("Nothing to Peak Error!");
	}
	return m_array.Last();
}

template <class T>
int StackLinkedList<T>::Size() const
{
	return m_trackSize;
}

template <class T>
int StackLinkedList<T>::getSize() const
{
	return m_size;
}

template <class T>
bool StackLinkedList<T>::isEmpty() const
{
	if (m_trackSize == 0)
	{
		return true;
	}
	return false;
}

template <class T>
void StackLinkedList<T>::Print()
{
	m_array.PrintForwards();
}

template <class T>
void StackLinkedList<T>::PrintIndex(int index)
{
	Node<T> *CurrPtr = m_array.getHead();

	for (auto i = 0; i < index; i++)
	{
		CurrPtr = CurrPtr->getNext();
	}


	cout << CurrPtr->getData();

}

#endif
