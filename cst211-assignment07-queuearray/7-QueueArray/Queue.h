#ifndef QUEUE_H
#define QUEUE_H

#include "Exception.h"
#include "Array.h"
#include "string"

template<class T>
class Queue
{
public:
	Queue();
	explicit Queue(int size);
	Queue(const Queue& copy);
	~Queue();
	Queue &operator =(const Queue& copy);
	void Enqueue(const T& data);
	T Dequeue();
	T& Front();
	int Size() const;
	int getSize() const;
	bool isEmpty() const;
	bool isFull() const;
	void Print();

private:
	Array<T> m_array;
	int m_size;
	int m_head;
	int m_tail;
	int m_track;
};

template <class T>
Queue<T>::Queue(): m_size(0), m_head(0), m_tail(0), m_track(0){}

template <class T>
Queue<T>::Queue(int size): m_size(size), m_head(0), m_tail(0), m_track(0)
{
	m_array.setLength(size);
	if (m_array.getLength() != m_size)
	{
		throw Exception("Queue Array Overloaded Constructor Error!");
	}
}

template <class T>
Queue<T>::Queue(const Queue& copy): m_size(copy.m_size), m_head(copy.m_head), m_tail(copy.m_tail), m_track(copy.m_track)
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

template <class T>
Queue<T>::~Queue(){}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& copy)
{
	m_array.setLength(copy.getSize());
	m_size = copy.m_size;
	m_head = copy.m_head;
	m_tail = copy.m_tail;
	m_track = copy.m_track;

	for (auto i = 0; i < copy.getSize(); i++)
	{
		m_array[i] = copy.m_array[i];
	}

	return *this;
}

template <class T>
void Queue<T>::Enqueue(const T& data)
{
	if (isFull())
	{
		throw Exception("Queue is Full Overflow Error!");
	}
	m_array[m_tail] = data;
	m_tail = (m_tail + 1) % m_size;
	m_track++;
}

template <class T>
T Queue<T>::Dequeue()
{
	if (isEmpty())
	{
		throw Exception("Nothing to Dequeue Underflow Error!");
	}
	T temp = m_array[m_head];
	m_array[m_head] = 0;
	m_head = (m_head + 1) % m_size;
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
	T& temp = m_array[m_head];
	return temp;
}

template <class T>
int Queue<T>::Size() const
{
	return m_track;
}

template <class T>
int Queue<T>::getSize() const
{
	return m_size;
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return m_track == 0;
}

template <class T>
bool Queue<T>::isFull() const
{
	return m_track == m_size;
}

template <class T>
void Queue<T>::Print()
{
	for (auto i = 0; i < getSize(); i++)
	{
			cout << "[" << i << "] =  " << m_array[i] << endl;
	}
}

#endif
