#ifndef QUEUE_H
#define QUEUE_H

#include "Exception.h"
#include "DoubleLinkedList.h"

template<class T>
class Queue
{
public:
	Queue();
	Queue(const Queue& copy);
	~Queue();
	Queue &operator =(const Queue& copy);
	void Enqueue(const T& data);
	T Dequeue();
	T& Front();
	int Size() const;
	bool isEmpty() const;
	void Print();
private:
	DoubleLinkedList<T> m_array;
	int m_track;
};

template <class T>
Queue<T>::Queue() : m_track(0) {}

template <class T>
Queue<T>::Queue(const Queue& copy) : m_track(copy.m_track)
{
	Node<T> *CurrPtr = copy.m_array.getHead();

	for (auto i = 0; i < copy.Size(); i++)
	{
		m_array.Append(CurrPtr->getData());
		CurrPtr = CurrPtr->getNext();
	}

	if (m_array.First() != copy.m_array.First())
	{
		throw Exception("Stack Array Default Constructor Error!");
	}
}

template <class T>
Queue<T>::~Queue() {}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& copy)
{
	m_track = copy.m_track;
	Node<T> *CurrPtr = copy.m_array.getHead();

	for (auto i = 0; i < copy.Size(); i++)
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
void Queue<T>::Enqueue(const T& data)
{
	m_array.Append(data);
	m_track++;
}

template <class T>
T Queue<T>::Dequeue()
{
	if (isEmpty())
	{
		throw Exception("Nothing to Dequeue Underflow Error!");
	}
	T temp = m_array.First();
	m_array.Extract(temp);

	m_track--;
	return temp;
}

template <class T>
T& Queue<T>::Front()
{
	if (isEmpty())
	{
		throw Exception("Nothing in the Front Error!");
	}
	T& temp = m_array.First();
	return temp;
}

template <class T>
int Queue<T>::Size() const
{
	return m_track;
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return m_track == 0;
}

template <class T>
void Queue<T>::Print()
{
	m_array.PrintForwards();
}


#endif
