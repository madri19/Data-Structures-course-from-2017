#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "AbstractIterator.h"
#include "Node.h"

template<class T>
class ListIterator : public AbstractIterator<T>
{
public:
	ListIterator(): m_node(nullptr), m_done(false){}

	void Reset() override = 0;
	virtual bool isDone() const;
	void MoveNext() override = 0;
	const T& GetCurrent() const override;
	virtual Node<T>* operator=(const Node<T>* rhs) = 0;
	virtual Node<T>* operator=(const Node<T>* rhs) const = 0;
	const T& operator*() const;
protected:
	mutable Node<T>* m_node;
	mutable bool m_done;
};

template <class T>
bool ListIterator<T>::isDone() const
{
	return m_done;
}

template <class T>
const T& ListIterator<T>::GetCurrent() const
{
	return m_node->getData();
}

template <class T>
const T& ListIterator<T>::operator*() const
{
	return GetCurrent();
}

#endif