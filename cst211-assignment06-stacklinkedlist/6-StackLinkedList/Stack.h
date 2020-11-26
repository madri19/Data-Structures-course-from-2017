#ifndef STACK_H
#define STACK_H

#include "DoubleLinkedList.h"
#include "Exception.h"

template <class T>
class Stack
{
public:
	Stack();
	explicit Stack(int size);
	Stack(const Stack<T>& copy);
	~Stack();
	Stack &operator =(const Stack& copy);
	void Push(const T& item);
	T& Pop();
	const T& Peak();
	int Size() const;
	int getSize() const;
	bool isEmpty() const;
	void Print();
private:
	DoubleLinkedList<T> m_array;
	int m_size;
	int m_trackSize;
};

template <class T>
Stack<T>::Stack() : m_size(0), m_trackSize(0)
{
	if (!m_array.isEmpty())
	{
		throw Exception("Stack Array Default Constructor Error!");
	}
}

template <class T>
Stack<T>::Stack(int size) : m_size(size), m_trackSize(0)
{
	if (!m_array.isEmpty())
	{
		throw Exception("Stack Array Overloaded Constructor Error!");
	}
}

template <class T>
Stack<T>::Stack(const Stack<T>& copy) : m_size(copy.m_size), m_trackSize(copy.m_trackSize)
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
Stack<T>::~Stack() {}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& copy)
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
void Stack<T>::Push(const T& item)
{
	m_array.Append(item);
	m_trackSize++;
}

template <class T>
T& Stack<T>::Pop()
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
const T& Stack<T>::Peak()
{
	if (m_trackSize == 0)
	{
		throw Exception("Nothing to Peak Error!");
	}
	return m_array.Last();
}

template <class T>
int Stack<T>::Size() const
{
	return m_trackSize;
}

template <class T>
int Stack<T>::getSize() const
{
	return m_size;
}

template <class T>
bool Stack<T>::isEmpty() const
{
	if (m_trackSize == 0)
	{
		return true;
	}
	return false;
}

template <class T>
void Stack<T>::Print()
{
	m_array.PrintForwards();
}

#endif
