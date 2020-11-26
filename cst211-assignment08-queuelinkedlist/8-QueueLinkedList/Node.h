#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
public:
	Node();
	explicit Node(const T& data, Node* next = nullptr, Node* prev = nullptr);
	Node(const Node& copy);
	~Node();
	T& getData();
	Node* getNext();
	Node* getPrev();
	void setData(T data);
	void setNext(Node* next);
	void setPrev(Node* prev);
private:
	T m_data;
	Node* m_nextPtr;
	Node* m_prevPtr;
};

template <class T>
Node<T>::Node() : m_data(NULL), m_nextPtr(nullptr), m_prevPtr(nullptr) {}

template <class T>
Node<T>::Node(const T& data, Node* next = nullptr, Node* prev = nullptr)
{
	m_data = data;
	m_nextPtr = next;
	m_prevPtr = prev;
}

template <class T>
Node<T>::Node(const Node& copy)
{
	m_data = copy.m_data;
	m_nextPtr = copy.m_nextPtr;
	m_prevPtr = copy.m_prevPtr;
}

template <class T>
Node<T>::~Node() {}

template <class T>
T& Node<T>::getData()
{
	return m_data;
}

template <class T>
Node<T>* Node<T>::getNext()
{
	return m_nextPtr;
}

template <class T>
Node<T>* Node<T>::getPrev()
{
	return m_prevPtr;
}

template <class T>
void Node<T>::setData(T data)
{
	m_data = data;
}

template <class T>
void Node<T>::setNext(Node* next)
{
	m_nextPtr = next;
}

template <class T>
void Node<T>::setPrev(Node* prev)
{
	m_prevPtr = prev;
}

#endif