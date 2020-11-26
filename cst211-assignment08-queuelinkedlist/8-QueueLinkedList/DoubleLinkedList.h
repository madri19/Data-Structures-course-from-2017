#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "Exception.h"
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

template<class T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	DoubleLinkedList(Node<T>* head, Node<T>* tail);
	DoubleLinkedList(const DoubleLinkedList& copy);
	~DoubleLinkedList();
	DoubleLinkedList &operator =(const DoubleLinkedList& copy);
	Node<T>* getHead() const;
	Node<T>* getTail() const;
	void setHead(Node<T>* head);
	void setTail(Node<T>* tail);
	bool isEmpty() const;
	T& First() const;
	const T& Last();
	const T& Last() const;
	void Prepend(const T& data);
	void Append(const T& data);
	void Purge() const;
	void Extract(const T& data);
	void InsertAfter(const T& data, const T& afterThis);
	void InsertBefore(const T& data, const T& beforeThis);
	void PrintForwards() const;
	void PrintBackwards() const;
	void RemoveLast();
private:
	Node<T>* m_head;
	Node<T>* m_tail;
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList() : m_head(nullptr), m_tail(nullptr)
{
	if (m_head != nullptr || m_head != nullptr)
	{
		throw Exception("Default Constructor Error!");
	}
}

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(Node<T>* head, Node<T>* tail)
{
	m_head = head;
	m_tail = tail;

	if (this->getHead() != head || this->getTail() != tail)
	{
		throw Exception("Overloaded Constructor Error!");
	}
}

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList& copy)
{
	m_head = nullptr;
	m_tail = nullptr;
	*this = copy;

	if (m_head->getData() != copy.m_head->getData())
	{
		throw Exception("Copy Constructor Error!");
	}
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Node<T> *temp = m_tail;
	while (temp != nullptr)
	{
		Node<T> *temp2 = temp;
		temp = temp->getPrev();
		delete temp2;
	}
}

template <class T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList& copy)
{
	if (this != &copy)
	{
		if (m_head != nullptr)
		{
			Purge();
		}
		Node<T> *origPtr = copy.m_head;

		while (origPtr != nullptr)
		{
			if (m_head == nullptr)
			{
				m_head = m_tail = new Node<T>(origPtr->getData());
			}
			else
			{
				this->Append(origPtr->getData());
			}
			origPtr = origPtr->getNext();
		}
		if (origPtr != nullptr)
		{
			throw Exception("Assignment Operator Error!");
		}
	}
	return *this;
}

template <class T>
Node<T>* DoubleLinkedList<T>::getHead() const
{
	return m_head;
}

template <class T>
Node<T>* DoubleLinkedList<T>::getTail() const
{
	return m_tail;
}

template <class T>
void DoubleLinkedList<T>::setHead(Node<T>* head)
{
	m_head = head;
}

template <class T>
void DoubleLinkedList<T>::setTail(Node<T>* tail)
{
	m_tail = tail;
}

template <class T>
bool DoubleLinkedList<T>::isEmpty() const
{
	if (m_head == nullptr && m_tail == nullptr)
	{
		return true;
	}
	return false;
}

template <class T>
T& DoubleLinkedList<T>::First() const
{
	return m_head->getData();
}

template <class T>
const T& DoubleLinkedList<T>::Last()
{
	return m_tail->getData();
}

template <class T>
const T& DoubleLinkedList<T>::Last() const
{
	return m_tail->getData();
}

template <class T>
void DoubleLinkedList<T>::Prepend(const T& data)
{
	Node<T>* temp = new Node<T>(data);
	if (m_head == nullptr)
	{
		m_head = temp;
		m_tail = temp;
	}
	else
	{
		m_head->setPrev(temp);
		temp->setNext(m_head);
		m_head = temp;
	}
}

template <class T>
void DoubleLinkedList<T>::Append(const T& data)
{
	Node<T>* temp = new Node<T>(data);
	if (m_tail == nullptr)
	{
		m_head = temp;
		m_tail = temp;
	}
	else
	{
		m_tail->setNext(temp);
		temp->setPrev(m_tail);
		m_tail = temp;
	}
}

template <class T>
void DoubleLinkedList<T>::Purge() const
{
	Node<T> *temp = m_tail;
	while (temp != nullptr)
	{
		Node<T> *temp2 = temp;
		temp = temp->getPrev();
		delete temp2;
	}
	m_head = nullptr;
	m_tail = nullptr;
}

template<class T>
void DoubleLinkedList<T>::Extract(const T & data)
{
	Node<T> *currPtr = m_head;
	Node<T> *Prev;
	Node<T> *Next;

	while (currPtr != nullptr && currPtr->getData() != data)
	{
		currPtr = currPtr->getNext();
	}

	if (currPtr != nullptr)
	{
		if (currPtr == m_head && currPtr != m_tail)
		{
			Next = currPtr->getNext();
			Next->setPrev(nullptr);
			m_head = Next;

		}
		else if (currPtr == m_tail && currPtr != m_head)
		{
			Prev = currPtr->getPrev();
			Prev->setNext(nullptr);
			m_tail = Prev;

		}
		else if (currPtr == m_head && currPtr == m_tail)
		{
			m_head = nullptr;
			m_tail = nullptr;

		}
		else
		{
			Next = currPtr->getNext();
			Prev = currPtr->getPrev();
			Prev->setNext(Next);
			Next->setPrev(Prev);
		}

		delete currPtr;
	}
	else
	{
		throw Exception("Item to be extracted is not in the List!");
	}
}

template <class T>
void DoubleLinkedList<T>::InsertAfter(const T& data, const T& afterThis)
{
	Node<T> *currPtr = m_head;

	while (currPtr != nullptr && currPtr->getData() != afterThis)
	{
		currPtr = currPtr->getNext();
	}

	if (currPtr != nullptr)
	{
		Node<T>* insert = new Node<T>(data);

		if (currPtr == m_tail)
		{
			currPtr->setNext(insert);
			m_tail = insert;
			insert->setNext(nullptr);
			insert->setPrev(currPtr);
		}
		else
		{
			Node<T> *Next = currPtr->getNext();
			currPtr->setNext(insert);
			insert->setNext(Next);
			Next->setPrev(insert);
			insert->setPrev(currPtr);
		}
	}
	else
	{
		throw Exception("Item to be inserted is not in the List!");
	}
}

template<class T>
void DoubleLinkedList<T>::InsertBefore(const T & data, const T & beforeThis)
{
	Node<T> *currPtr = m_head;

	while (currPtr != nullptr && currPtr->getData() != beforeThis)
	{
		currPtr = currPtr->getNext();
	}

	if (currPtr != nullptr)
	{
		Node<T>* insert = new Node<T>(data);

		if (currPtr == m_head)
		{
			currPtr->setPrev(insert);
			m_head = insert;
			insert->setPrev(nullptr);
			insert->setNext(currPtr);
		}
		else
		{
			Node<T> *Prev = currPtr->getPrev();
			currPtr->setPrev(insert);
			insert->setPrev(Prev);
			Prev->setNext(insert);
			insert->setNext(currPtr);
		}
	}
	else
	{
		throw Exception("Item to be inserted is not in the List!");
	}
}

template <class T>
void DoubleLinkedList<T>::PrintForwards() const
{
	if (m_head == nullptr && m_tail == nullptr)
	{
		cout << "List is Empty!" << endl;
	}
	else
	{
		Node<T> *current = m_head;
		while (current != nullptr)
		{
			cout << current->getData() << endl;
			current = current->getNext();
		}
	}
	cout << endl;
}

template <class T>
void DoubleLinkedList<T>::PrintBackwards() const
{
	if (m_head == nullptr && m_tail == nullptr)
	{
		cout << "List is Empty!" << endl;
	}
	else
	{
		Node<T> *current = m_tail;
		while (current != nullptr)
		{
			cout << current->getData() << endl;
			current = current->getPrev();
		}
	}
	cout << endl;
}

template <class T>
void DoubleLinkedList<T>::RemoveLast()
{
	Node<T> *LastPtr = m_tail;

	m_tail = LastPtr->getPrev();

	LastPtr->setPrev(nullptr);

	m_tail->setNext(nullptr);


	delete LastPtr;

}

#endif