#ifndef STACKARRAY_H
#define STACKARRAY_H

#include "Array.h"
#include "Exception.h"

template <class T>
class StackArray
{
public:
	StackArray();
	explicit StackArray(int size);
	StackArray(const StackArray<T>& copy);
	~StackArray();
	StackArray &operator =(const StackArray& copy);
	void Push(const T& item);
	T& Pop();
	T& Peak();
	int Size() const;
	int getSize() const;
	void setSize(int size);
	bool isEmpty() const;
	bool isFull() const;
	void Print();
private:
	Array<T> m_array;
	int m_size;
	int m_trackSize;
};

template <class T>
StackArray<T>::StackArray() : m_size(13), m_trackSize(0)
{
	m_array.setLength(m_size);
	if (m_array.getLength() != m_size)
	{
		throw Exception("Stack Array Default Constructor Error!");
	}
}

template <class T>
StackArray<T>::StackArray(int size) : m_size(size), m_trackSize(0)
{
	m_array.setLength(size);
	if (m_array.getLength() != m_size)
	{
		throw Exception("Stack Array Overloaded Constructor Error!");
	}
}

template <class T>
StackArray<T>::StackArray(const StackArray<T>& copy) : m_size(copy.m_size), m_trackSize(copy.m_trackSize)
{
	m_array.setLength(m_size);
	if (m_array.getLength() != m_size)
	{
		throw Exception("Stack Array Default Constructor Error!");
	}

	for (auto i = 0; i < copy.getSize(); i++)
	{
		m_array[i] = copy.m_array[i];
	}
}

template<class T>
StackArray<T>::~StackArray() {}

template <class T>
StackArray<T>& StackArray<T>::operator=(const StackArray& copy)
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
void StackArray<T>::Push(const T& item)
{
	if (m_trackSize == m_size)
	{
		throw Exception("Stack is Full Overflow Error!");
	}
	m_array[m_trackSize] = item;
	m_trackSize++;
}

template <class T>
T& StackArray<T>::Pop()
{
	if (m_trackSize == 0)
	{
		throw Exception("Nothing to Pop Underflow Error!");
	}
	m_trackSize -= 1;
	return m_array[m_trackSize];
}

template <class T>
T& StackArray<T>::Peak()
{
	if (m_trackSize == 0)
	{
		throw Exception("Nothing to Peak Error!");
	}
	return m_array[m_trackSize - 1];
}

template <class T>
int StackArray<T>::Size() const
{
	return m_trackSize;
}

template <class T>
int StackArray<T>::getSize() const
{
	return m_size;
}

template <class T>
void StackArray<T>::setSize(int size)
{
	m_array.setLength(size);
}

template <class T>
bool StackArray<T>::isEmpty() const
{
	if (m_trackSize == 0)
	{
		return true;
	}
	return false;
}

template <class T>
bool StackArray<T>::isFull() const
{
	if (m_trackSize == m_size)
	{
		return true;
	}
	return false;
}

template <class T>
void StackArray<T>::Print()
{
	for (auto i = 0; i < Size(); i++)
	{
		cout << m_array[i] << endl;
	}
}

#endif
