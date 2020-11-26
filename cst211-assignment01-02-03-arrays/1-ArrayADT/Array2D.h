#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "Array.h"
#include "Row.h"

template<class T>
class Row;

template<class T>
class Array2D 
{
public:
	Array2D();
	Array2D(int row, int col);
	Array2D(const Array2D& copy);
	~Array2D();
	Array2D &operator =(const Array2D & rhs);
	Row<T> operator [](int index);
	Row<T> operator [](int index) const;
	int getRow() const;
	void setRow(int rows);
	int getColumn() const;
	void setColumn(int columns);
	T & Select(int row, int column);
private:
	Array<T> m_array;
	int m_row;
	int m_col;
};

template<class T>
Array2D<T>::Array2D()
{
	m_row = 2;
	m_col = 4;
	m_array.setLength(m_row * m_col);
	cout << "Array2D Default Constructor Called" << endl;
}

template<class T>
Array2D<T>::Array2D(int row, int col)
{
	m_row = row;
	m_col = col;
	m_array.setLength(m_row * m_col);
	cout << "Array2D Overloaded Constructor Called" << endl;
}

template<class T>
Array2D<T>::Array2D(const Array2D & copy)
{
	m_row = copy.getRow();
	m_col = copy.getColumn();
	m_array = copy.m_array;
	cout << "Array2D Copy Constructor Called" << endl;
}

template<class T>
Array2D<T>::~Array2D()
{
	cout << "Array2D Deconstructor Called" << endl;
}

template<class T>
Array2D<T> & Array2D<T>::operator=(const Array2D & rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	m_row = rhs.getRow();
	m_col = rhs.getColumn();
	m_array.setLength(m_row * m_col);
	m_array = rhs.m_array;

	return *this;
}

template<class T>
Row<T> Array2D<T>::operator[](int index)
{
	if (index > m_row - 1 || index < 0) 
	{
		throw Exception("***Exception Error: Row Index is out of Bounds!***\n");
	}
	return Row<T>(*this, index);
}

template<class T>
Row<T> Array2D<T>::operator[](int index) const
{
	if (index > m_row - 1 || index < 0)
	{
		throw Exception("***Exception Error: Row Index is out of Bounds!***\n");
	}
	return Row<T>(const_cast<Array2D&>(*this), index);
}

template<class T>
int Array2D<T>::getRow() const
{
	return m_row;
}

template<class T>
void Array2D<T>::setRow(int rows)
{
	m_row = rows;
	m_array.setLength(m_row * m_col);
}

template<class T>
int Array2D<T>::getColumn() const
{
	return m_col;
}

template<class T>
void Array2D<T>::setColumn(int columns)
{
	m_array.setLength(m_row * columns);
	m_col = columns;
}

template<class T>
T & Array2D<T>::Select(int row, int column)
{
	if (column > m_col - 1 || column < 0)
	{
		throw Exception("***Exception Error: Column Index is out of Bounds!***\n");
	}

	auto element_idx = 0;
	element_idx = (row * m_col) + column;

	return m_array[element_idx];
}

#endif