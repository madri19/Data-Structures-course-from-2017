#ifndef CONTAINERS_H
#define CONTAINERS_H
#include "Array.h"
#include <vector>

template<class T>
class Containers 
{
public:
	Containers(size_t size);
	Containers(const Containers<T>& containers);
	~Containers();
	void DebugPrintContainers();
	size_t GetSize() const;
	T** GetCArray() const;
	vector<T>* GetStlVector() const;
	Array<T>* GetMyArray() const;
	void LoadContainers();
private:
	size_t m_size;
	T ** m_cArray;
	vector<T>* m_stlVector;
	Array<T>* m_myArray;
	
};

template <class T>
Containers<T>::Containers(size_t size) : m_size(size), m_cArray(new T*[size]), m_stlVector(new vector<T>(size)), m_myArray(new Array<T>(size, 0))
{
	for(size_t i = 0; i < m_size; ++i)
	{
		m_cArray[i] = new T;
	}
	LoadContainers();
}

template <class T>
Containers<T>::Containers(const Containers<T>& containers) : m_size(containers.GetSize()), m_cArray(new T[containers.GetSize()]),
m_stlVector(new vector<T>(*containers.GetStlVector())), m_myArray(new Array<T>(containers.GetMyArray()))
{
	for (size_t i = 0; i < m_size; ++i)
	{
		m_cArray[i] = containers.GetCArray()[i];
	}
}

template <class T>
Containers<T>::~Containers()
{
	delete m_stlVector;
	for (size_t i = 0; i < m_size; ++i)
	{
		delete m_cArray[i];
	}
	delete m_cArray;
	delete m_myArray;
}

template <class T>
void Containers<T>::DebugPrintContainers()
{
	for (size_t i = 0; i < m_size; ++i)
	{
		cout << (*m_stlVector)[i] << " " << *m_cArray[i] << " " << (*m_myArray)[i] << endl;
	}
}

template <class T>
size_t Containers<T>::GetSize() const
{
	return m_size;
}

template <class T>
T** Containers<T>::GetCArray() const
{
	return m_cArray;
}

template <class T>
vector<T>* Containers<T>::GetStlVector() const
{
	return m_stlVector;
}

template <class T>
Array<T>* Containers<T>::GetMyArray() const
{
	return m_myArray;
}

template <class T>
void Containers<T>::LoadContainers()
{
	srand(1);
	for (size_t i = 0; i < m_size; ++i)
	{
		T number = rand();
		(*m_stlVector)[i] = number;
		*m_cArray[i] = number;
		(*m_myArray)[i] = number;
	}
}

#endif
