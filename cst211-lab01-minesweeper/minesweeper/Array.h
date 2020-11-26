//Juan Madrigal
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template<class T>
class Array{

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
inline Array<T>::Array()
{
	m_length = 1;
	m_start_index = 0;
	m_array = new T[m_length];
}

template<class T>
Array<T>::Array(int length, int start_index)
{
	m_length = length;
	m_start_index = start_index;
	m_array = new T[m_length];
}


template<class T>
Array<T>::Array(const Array & copy)
{
	m_array = new T[copy.getLength()];

	for (auto i = 0; i < copy.getLength(); ++i)
	{
		m_array[i] = copy[i + copy.getStartIndex()];
	}
	m_length = copy.getLength();
	m_start_index = copy.getStartIndex();
}


template<class T>
Array<T>::~Array()
{
	delete[] m_array;
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
		m_array[i] = rhs[i + rhs.getStartIndex()];
	}

	m_length = rhs.getLength();
	m_start_index = rhs.getStartIndex();

	return *this;
}


template<class T>
T& Array<T>::operator[](int index)
{
	index = index - m_start_index;

	return m_array[index];
}

template<class T>
T& Array<T>::operator[](int index) const
{
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
	T* temp_array = new T[m_length];

	for (auto i = 0; i < m_length; i++) {
		temp_array[i] = m_array[i];
	}

	delete[] m_array;

	m_array = new T[length];

	if (length > m_length) {

		for (auto idx = 0; idx < m_length; idx++) {
			m_array[idx] = temp_array[idx];
		}
	}
	else
	{
		for (auto idx = 0; idx < length; idx++) {
			m_array[idx] = temp_array[idx];
		}
	}

	m_length = length;

	delete[] temp_array;
}

#endif // !ARRAY_H