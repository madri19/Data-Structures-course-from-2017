#ifndef BST_H
#define BST_H

#include "BSNode.h"
#include "Exception.h"
#include "Queue.h"
using namespace std;

template<class T>
class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& copy);
	~BinarySearchTree();
	void SetFunction(void(*visit)(BSNode<T>*& node));
	BSNode<T>*& getRoot();
	void Purge();
	int getHeight();
	int getCount() const;
	bool IsEmpty();
	void Insert(T item);
	void Delete(T item);
	void DeleteFromTree(BSNode<T>*& node);
	void InOrder(void(*visit)(BSNode<T>*& node), BSNode<T>*& node);
	void PreOrder(void(*visit)(BSNode<T>*& node), BSNode<T>*& node);
	void PostOrder(void(*visit)(BSNode<T>*& node), BSNode<T>*& node);
	void BreadthFirst(void(*visit)(BSNode<T>*& node), BSNode<T>*& node);
private:
	BSNode<T>* m_root;
	int m_treeCount;
	void(*m_visit)(BSNode<T>*& node);
	BSNode<T>* m_lSpot;
	BSNode<T>* m_rSpot;
	BSNode<T>* m_curr;
	BSNode<T>* m_prev;
	bool m_found;
	bool m_leaf;
	Queue<BSNode<T>*> queue;
	BSNode<T>* hold_node;
	void Purge(BSNode<T>*& node);
	int Height(BSNode<T>*& node);
	void Insert(BSNode<T>*& root, T item);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree(): m_root(nullptr), m_treeCount(NULL), m_found(false), m_leaf(false){}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& copy)
{
	m_root = copy.m_root;
	m_treeCount = copy.m_treeCount;
	m_lSpot = copy.m_lSpot;
	m_rSpot = copy.m_rSpot;
	m_found = copy.m_found;
	m_leaf = copy.m_leaf;
	queue = copy.queue;
	hold_node = copy.hold_node;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	Purge(m_root);
}

template <class T>
void BinarySearchTree<T>::SetFunction(void(*visit)(BSNode<T>*& node))
{
	m_visit = visit;
}

template <class T>
BSNode<T>*& BinarySearchTree<T>::getRoot()
{
	return m_root;
}

template <class T>
void BinarySearchTree<T>::Purge()
{
	Purge(m_root);
	m_root = nullptr;
}

template <class T>
int BinarySearchTree<T>::getHeight()
{
	int i = Height(m_root);
	if(i == 0)
	{
		return i;
	}
	return i;
}

template <class T>
int BinarySearchTree<T>::getCount() const
{
	return m_treeCount;
}

template <class T>
bool BinarySearchTree<T>::IsEmpty()
{
	return m_root == nullptr;
}

template <class T>
void BinarySearchTree<T>::Insert(T item)
{
	Insert(m_root, item);
	m_treeCount++;
}

template <class T>
void BinarySearchTree<T>::Delete(T item)
{
	if(m_root == nullptr)
	{
		throw Exception("Empty!");
	}

	m_curr = m_root;
	m_prev = m_root;

	while(m_curr != nullptr && !m_found)
	{
		if(m_curr->getData() == item)
		{
			m_found = true;
		}else
		{
			m_prev = m_curr;

			if(m_curr->getData() > item)
			{
				m_curr = m_curr->getLeft();
			}else
			{
				m_curr = m_curr->getRight();
			}
		}
	}

	if(m_curr->getLeft() == nullptr && m_curr->getRight() == nullptr)
	{
		m_leaf = true;
	}

	if(m_curr == nullptr)
	{
		throw Exception("Error!");
	}

	if(m_found)
	{
		if(m_root == m_curr)
		{
			DeleteFromTree(m_root);
		}
		else if(m_prev->getData() > item)
		{
			DeleteFromTree(m_prev->getLeft());
		}
		else
		{
			DeleteFromTree(m_prev->getRight());
		}
	}

}

template <class T>
void BinarySearchTree<T>::DeleteFromTree(BSNode<T>*& parent)
{
	m_curr = parent;

	if(parent == nullptr)
	{
		throw Exception("Error Here");
	}
	
	if(m_leaf == true)
	{
		parent = nullptr;
	}
	else if (parent->getLeft() == nullptr)
	{
		parent = parent->getRight();
	}
	else if(parent->getRight() == nullptr)
	{
		parent = parent->getLeft();
	}else
	{
		m_curr = parent->getLeft();

		while(parent->getRight() != nullptr)
		{
			m_prev = m_curr;
			m_curr = m_curr->getRight();
		}

		parent->setData(m_curr->getData());

		if(m_prev == nullptr)
		{
			parent->setLeft(m_curr->getLeft());
		}else
		{
			parent->setRight(m_curr->getLeft());
		}
	}
	delete m_curr;
	m_treeCount--;
	m_curr = nullptr;
	m_prev = nullptr;
}


template <class T>
void BinarySearchTree<T>::Purge(BSNode<T>*& node)
{
	if(node != nullptr)
	{
		Purge(node->getLeft());
		Purge(node->getRight());
		delete node;
	}
}

template <class T>
int BinarySearchTree<T>::Height(BSNode<T>*& node)
{
	if(node != nullptr)
	{
		return 0;
	}
	int h_left = Height(node->getLeft());
	int h_right = Height(node->getRight());
	if(h_left > h_right)
	{
		return h_left + 1;
	}
	return h_right + 1;
}

template <class T>
void BinarySearchTree<T>::Insert(BSNode<T>*& root, T item)
{
	if (root == nullptr)
	{
		root = new BSNode<T>;
		root->setData(item);
	}
	else
	{
		if (item < root->getData())
		{
			Insert(root->getLeft(), item);
		}
		if (item > root->getData())
		{
			Insert(root->getRight(), item);
		}
	}
}

template <class T>
void BinarySearchTree<T>::InOrder(void(* visit)(BSNode<T>*& node), BSNode<T>*& node)
{
	if(node != nullptr)
	{
		InOrder(visit, node->getLeft());
		visit(node);
		InOrder(visit, node->getRight());
	}
}

template <class T>
void BinarySearchTree<T>::PreOrder(void(* visit)(BSNode<T>*& node), BSNode<T>*& node)
{
	if (node != nullptr)
	{
		visit(node);
		PreOrder(visit, node->getLeft());
		PreOrder(visit, node->getRight());
	}
}

template <class T>
void BinarySearchTree<T>::PostOrder(void(* visit)(BSNode<T>*& node), BSNode<T>*& node)
{
	if (node != nullptr)
	{
		PostOrder(visit, node->getLeft());
		PostOrder(visit, node->getRight());
		visit(node);
	}
}

template <class T>
void BinarySearchTree<T>::BreadthFirst(void(* visit)(BSNode<T>*& node), BSNode<T>*& node)
{
	if (node != nullptr)
	{
		queue.Enqueue(node);
		while (!queue.isEmpty())
		{
			hold_node = queue.Dequeue();
			visit(hold_node);
			if (hold_node->getLeft() != nullptr) 
			{
				queue.Enqueue(hold_node->getLeft());
			}
			if (hold_node->getRight() != nullptr)
			{
				queue.Enqueue(hold_node->getRight());
			}
		}
	}
}
#endif
