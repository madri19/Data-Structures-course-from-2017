//Juan Madrigal

#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "Array.h"
#include "Row.h"

template<class T>
class Row;

template<class T>
class Array2D {

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
}

template<class T>
Array2D<T>::Array2D(int row, int col)
{
	m_row = row;
	m_col = col;
	m_array.setLength(m_row * m_col);
}

template<class T>
Array2D<T>::Array2D(const Array2D & copy)
{
	m_row = copy.getRow();
	m_col = copy.getColumn();

	m_array.setLength(m_row * m_col);
	m_array = copy.m_array;
}

template<class T>
Array2D<T>::~Array2D(){}


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
	return Row<T>(*this, index);
}

template<class T>
Row<T> Array2D<T>::operator[](int index) const
{
	return Row<T>(const_cast<Array2D&>(*this), index);
}

template<class T>
int Array2D<T>::getRow() const
{
	return m_row;
}

template<class T>
inline void Array2D<T>::setRow(int rows)
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
	return m_array[(row * m_col) + column];
}



#endif