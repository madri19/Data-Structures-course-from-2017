#ifndef STACK_H
#define STACK_H

#include "Array.h"
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
	T& Peak();
	int Size() const;
	int getSize() const;
	bool isEmpty() const;				
	bool isFull() const;
	void Print();
private:
	Array<T> m_array;
	int m_size;
	int m_trackSize;
};

template <class T>
Stack<T>::Stack(): m_size(0), m_trackSize(0)
{
	m_array.setLength(size);
	if (m_array.getLength() != m_size)
	{
		throw Exception("Stack Array Default Constructor Error!");
	}
}

template <class T>
Stack<T>::Stack(int size): m_size(size), m_trackSize(0)
{
	m_array.setLength(size);
	if (m_array.getLength() != m_size)
	{
		throw Exception("Stack Array Overloaded Constructor Error!");
	}
}

template <class T>
Stack<T>::Stack(const Stack<T>& copy): m_size(copy.m_size), m_trackSize(copy.m_trackSize)
{
	m_array.setLength(m_size);
	if (m_array.getLength() != m_size)
	{
		throw Exception("Stack Array Default Constructor Error!");
	}

	for(auto i = 0; i < copy.getSize(); i++)
	{
		m_array[i] = copy.m_array[i];
	}
}

template<class T>
Stack<T>::~Stack(){}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& copy)
{
	m_array.setLength(copy.getSize());
	m_size = copy.m_size;
	m_trackSize = copy.m_trackSize;

	for (auto i = 0; i < copy.getSize(); i++)
	{
		m_array[i] = copy.m_array[i];
	}

	return *this;
}

template <class T>
void Stack<T>::Push(const T& item)
{
	if (m_trackSize == m_size)
	{
		throw Exception("Stack is Full Overflow Error!");
	}
	m_array[m_trackSize] = item;
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
	return m_array[m_trackSize];
}

template <class T>
T& Stack<T>::Peak()
{
	if (m_trackSize == 0)
	{
		throw Exception("Nothing to Peak Error!");
	}
	return m_array[m_trackSize - 1];
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
bool Stack<T>::isFull() const
{
	if(m_trackSize == m_size)
	{
		return true;
	}
	return false;
}

template <class T>
void Stack<T>::Print()
{
	for(auto i = 0; i < Size(); i++)
	{
		cout << m_array[i] << endl;
	}
}

#endif
