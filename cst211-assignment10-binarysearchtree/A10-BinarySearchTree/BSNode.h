#ifndef BSNODE_H
#define BSNODE_H
#include <cstddef>

template<class T>
class BSNode
{
public:
	BSNode();
	explicit BSNode(const T& data, BSNode* left = nullptr, BSNode* right = nullptr);
	BSNode(const BSNode& copy);
	~BSNode();
	T& getData();
	BSNode*& getLeft();
	BSNode*& getRight();
	void setData(const T& data);
	void setLeft(BSNode* left);
	void setRight(BSNode* right);
private:
	T m_data;
	BSNode<T>* m_left;
	BSNode<T>* m_right;
};

template <class T>
BSNode<T>::BSNode() : m_data(NULL), m_left(nullptr), m_right(nullptr){}

template <class T>
BSNode<T>::BSNode(const T& data, BSNode* left = nullptr, BSNode* right = nullptr)
{
	m_data = data;
	m_left = left;
	m_right = right;
}

template <class T>
BSNode<T>::BSNode(const BSNode& copy)
{
	m_left = copy.m_left;
	m_right = copy.m_right;
}

template <class T>
BSNode<T>::~BSNode() {}

template <class T>
T& BSNode<T>::getData()
{
	return m_data;
}

template <class T>
BSNode<T>*& BSNode<T>::getLeft()
{
	return m_left;
}

template <class T>
BSNode<T>*& BSNode<T>::getRight()
{
	return m_right;
}

template <class T>
void BSNode<T>::setData(const T& data)
{
	m_data = data;
}

template <class T>
void BSNode<T>::setLeft(BSNode* left)
{
	m_left = left;
}

template <class T>
void BSNode<T>::setRight(BSNode* right)
{
	m_right = right;
}

#endif