#ifndef ARRAY_H
#define ARRAY_H

#include "Exception.h"

template<class T>
class Array
{
public:
	Array();
	Array(int length, int start_index);
	Array(const Array & copy);
	~Array();
	Array<T>& operator =(const Array & rhs);
	T& operator[](int index);
	T& operator[](int index) const;
	int getStartIndex() const;
	void setStartIndex(int start_index);
	int getLength() const;
	void setLength(int length);
private:
	T* m_array;
	int m_length;
	int m_start_index;
};

template<class T>
Array<T>::Array()
{
	m_length = 1;
	m_start_index = 0;
	m_array = new T[m_length];
	cout << "Array Default Constructor Called" << endl;
}

template<class T>
Array<T>::Array(int length, int start_index)
{
	if (length < 1) {
		throw Exception("***Exception Error: Length is not valid!(Length needs to be greater than zero)***\n");
	}

	m_length = length;
	m_start_index = start_index;
	m_array = new T[m_length];
cout << "Array Overloaded Constructor Called" << endl;
}

template<class T>
Array<T>::Array(const Array & copy)
{
	m_array = new T[copy.getLength()];

	for (auto i = 0; i < copy.getLength(); ++i)
	{
		m_array[i] = copy[i+copy.getStartIndex()];
	}
	m_length = copy.getLength();
	m_start_index = copy.getStartIndex();
	cout << "Array Copy Constructor Called" << endl;
}

template<class T>
Array<T>::~Array()
{
	delete[] m_array;
	cout << "Array Deconstructor Called" << endl;
}

template<class T>
Array<T>& Array<T>::operator=(const Array & rhs)
{
	if (this == &rhs) {
		return *this;
	}
	if (m_array != nullptr) 
	{
		delete[] m_array;
	}
	m_array = new T[rhs.getLength()];

	for (auto i = 0; i < rhs.getLength(); ++i)
	{
		m_array[i] = rhs[i+rhs.getStartIndex()];
	}

	m_length = rhs.getLength();
	m_start_index = rhs.getStartIndex();

	return *this;
}

template<class T>
T& Array<T>::operator[](int index)
{
	if (index < m_start_index) 
	{
		throw Exception("***Exception Error: Index is Out of Bounds Lower!***\n");
	}
	if (index > m_start_index + m_length)
	{
		throw Exception("***Exception Error: Index is Out of Bounds Higher!***\n");
	}
	index = index - m_start_index;

	return m_array[index];
}

template<class T>
T& Array<T>::operator[](int index) const
{
	if (index < m_start_index)
	{
		throw Exception("***Exception Error: Index is Out of Bounds Lower!***\n");
	}
	if (index > m_start_index + m_length)
	{
		throw Exception("***Exception Error: Index is Out of Bounds Higher!***\n");
	}
	index = index - m_start_index;

	return m_array[index];
}

template<class T>
int Array<T>::getStartIndex() const
{
	return m_start_index;
}

template<class T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template<class T>
int Array<T>::getLength() const
{
	return m_length;
}

template<class T>
void Array<T>::setLength(int length)
{
	if (length < 1) 
	{
		throw Exception("***Exception Error: Length is not valid!***\n");
	}

	T* temp_array = new T[length];

	auto minToCopy = (length > m_length) ? m_length : length;

	for (auto i = 0; i < minToCopy; i++) 
	{
		temp_array[i] = m_array[i];
	}

	delete[] m_array;

	m_array = temp_array;
	m_length = length;
}

#endif