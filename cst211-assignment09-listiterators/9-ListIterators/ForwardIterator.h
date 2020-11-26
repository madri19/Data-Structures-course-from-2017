#ifndef FORWARDITERATOR_H
#define FORWARDITERATOR_H

#include "ListIterator.h"

template<class T>
class ForwardIterator : public ListIterator<T>
{
public:
	void Reset() override;
	bool IsDone() const override;
	void MoveNext() override;
	Node<T>* operator=(const Node<T>* rhs) override;
	Node<T>* operator=(const Node<T>* rhs) const override;
	ForwardIterator<T>& operator++();
	ForwardIterator<T> operator++(int);
};

template <class T>
void ForwardIterator<T>::Reset()
{
	while(ListIterator<T>::m_node->getPrev() != nullptr)
	{
		ListIterator<T>::m_node = ListIterator<T>::m_node->getPrev();
	}
	ListIterator<T>::m_done = false;
}

template <class T>
bool ForwardIterator<T>::IsDone() const
{
	return ListIterator<T>::m_done;
}

template <class T>
void ForwardIterator<T>::MoveNext()
{
	if(ListIterator<T>::isDone())
	{
		throw Exception("You are trying to pass the last Node!");
	}
	ListIterator<T>::m_node = ListIterator<T>::m_node->getNext();

	if (ListIterator<T>::m_node->getNext() == nullptr)
	{
		ListIterator<T>::m_done = true;
	}
}

template <class T>
Node<T>* ForwardIterator<T>::operator=(const Node<T>* rhs)
{
	ListIterator<T>::m_node = const_cast<Node<T>*>(rhs);
	return ListIterator<T>::m_node;
}

template <class T>
Node<T>* ForwardIterator<T>::operator=(const Node<T>* rhs) const
{
	ListIterator<T>::m_node = const_cast<Node<T>*>(rhs);
	return ListIterator<T>::m_node;
}

template <class T>
ForwardIterator<T>& ForwardIterator<T>::operator++()
{
	MoveNext();
	return *this;
}

template <class T>
ForwardIterator<T> ForwardIterator<T>::operator++(int)
{
	ForwardIterator<T> temp = *this;
	MoveNext();

	return temp;
}

#endif