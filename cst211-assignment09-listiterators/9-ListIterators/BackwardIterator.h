#ifndef BACKWARDITERATOR_H
#define BACKWARDITERATOR_H

#include "ListIterator.h"

template<class T>
class BackwardIterator : public ListIterator<T>
{
public:
	void Reset() override;
	bool IsDone() const override;
	void MoveNext() override;
	Node<T>* operator=(const Node<T>* rhs) override;
	Node<T>* operator=(const Node<T>* rhs) const override;
	BackwardIterator<T>& operator--();
	BackwardIterator<T> operator--(int);
};

template <class T>
void BackwardIterator<T>::Reset()
{
	while (ListIterator<T>::m_node->getNext() != nullptr)
	{
		ListIterator<T>::m_node = ListIterator<T>::m_node->getNext();
	}
	ListIterator<T>::m_done = false;
}

template <class T>
bool BackwardIterator<T>::IsDone() const
{
	return ListIterator<T>::m_done;
}

template <class T>
void BackwardIterator<T>::MoveNext()
{
	if (ListIterator<T>::isDone())
	{
		throw Exception("You are trying to pass the last Node!");
	}
	ListIterator<T>::m_node = ListIterator<T>::m_node->getPrev();

	if (ListIterator<T>::m_node->getPrev() == nullptr)
	{
		ListIterator<T>::m_done = true;
	}
}

template <class T>
Node<T>* BackwardIterator<T>::operator=(const Node<T>* rhs)
{
	ListIterator<T>::m_node = const_cast<Node<T>*>(rhs);
	return ListIterator<T>::m_node;
}

template <class T>
Node<T>* BackwardIterator<T>::operator=(const Node<T>* rhs) const
{
	ListIterator<T>::m_node = const_cast<Node<T>*>(rhs);
	return ListIterator<T>::m_node;
}

template <class T>
BackwardIterator<T>& BackwardIterator<T>::operator--()
{
	MoveNext();
	return *this;
}

template <class T>
BackwardIterator<T> BackwardIterator<T>::operator--(int)
{
	BackwardIterator<T> temp = *this;
	MoveNext();

	return temp;
}

#endif