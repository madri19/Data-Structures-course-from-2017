#ifndef ARRAY2D_P_H
#define ARRAY2D_P_H

#include "Row_P.h"
#include "Exception.h"

template<class T>
class Row_P;

template<class T>
class Array2D_P 
{
public:
	Array2D_P();
	Array2D_P(int row, int col);
	Array2D_P(const Array2D_P& copy);
	~Array2D_P();
	Array2D_P &operator =(const Array2D_P & rhs);
	Row_P<T> operator [](int index);
	Row_P<T> operator [](int index) const;
	int getRow() const;
	void setRow(int rows);
	int getColumn() const;
	void setColumn(int columns);
	T & Select(int row, int column); 
private:
	T** m_array;
	int m_row;
	int m_col;
};

template<class T>
Array2D_P<T>::Array2D_P()
{
	m_row = 2;
	m_col = 4;
	m_array = new T*[m_row];

	for(auto i = 0; i < m_row; i++)
	{
		m_array[i] = new T[m_col];
	}
	cout << "Array2d_P Default Constructor Called" << endl;
}

template<class T>
Array2D_P<T>::Array2D_P(int row, int col)
{
	m_row = row;
	m_col = col;
	m_array = new T*[m_row];

	for (auto i = 0; i < m_row; i++)
	{
		m_array[i] = new T[m_col];
	}
	cout << "Array2D_P Overloaded Constructor Called" << endl;
}

template<class T>
Array2D_P<T>::Array2D_P(const Array2D_P & copy)
{
	m_row = copy.getRow();
	m_col = copy.getColumn();
	m_array = new T*[m_row];

	for (auto i = 0; i < m_row; i++)
	{
		m_array[i] = new T[m_col];
	}

	for (auto i = 0; i < m_row; i++) 
	{
		for (auto ii = 0; ii < m_col; ii++) 
		{
			m_array[i][ii] = copy.m_array[i][ii];
		}
	}
	cout << "Array2D_P Copy Constructor Called" << endl;
}

template<class T>
Array2D_P<T>::~Array2D_P()
{
	for (auto i = 0; i < m_row; i++)
	{
		delete [] m_array[i];
	}
	delete[] m_array;
	cout << "Array2D_P Deconstructor Called" << endl;
}

template<class T>
Array2D_P<T> & Array2D_P<T>::operator=(const Array2D_P & rhs)
{
	if (this == &rhs) 
	{
		return *this;
	}

	if (m_array != nullptr)
	{
		for (auto i = 0; i < m_row; i++)
		{
			delete[] m_array[i];
		}
		delete[] m_array;
	}

	m_array = new T*[rhs.getRow()];

	for (auto ii = 0; ii < rhs.getRow(); ii++)
	{
		m_array[ii] = new T[rhs.getColumn()];
	}

	m_row = rhs.getRow();
	m_col = rhs.getColumn();

	for (auto i = 0; i < m_row; i++) 
	{
		for (auto ii = 0; ii < m_col; ii++) 
		{
			m_array[i][ii] = rhs.m_array[i][ii];
		}
	}
	return *this;
}

template<class T>
Row_P<T> Array2D_P<T>::operator[](int index)
{
	if (index > m_row - 1 || index < 0)
	{
		throw Exception("***Exception Error: Row Index is out of Bounds!***\n");
	}
	return Row_P<T>(*this, index);
}

template<class T>
Row_P<T> Array2D_P<T>::operator[](int index) const
{
	if (index > m_row - 1 || index < 0)
	{
		throw Exception("***Exception Error: Row Index is out of Bounds!***\n");
	}
	return Row_P<T>(const_cast<Array2D_P&>(*this), index);
}

template<class T>
int Array2D_P<T>::getRow() const
{
	return m_row;
}

template<class T>
void Array2D_P<T>::setRow(int rows)
{
	if (rows <= 0)
	{
		throw Exception("***Exception Error: Rows Has to be greater than 0!***\n");
	}

	T** temp = new T*[m_row];

	for (auto i = 0; i < m_row; i++)
	{
		temp[i] = new T[m_col];
	}

	for (auto i = 0; i < m_row; i++) 
	{
		for (auto ii = 0; ii < m_col; ii++) 
		{
			temp[i][ii] = m_array[i][ii];
		}
	}

	for (auto i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	delete[] m_array;

	m_array = new T*[rows];

	for (auto i = 0; i < rows; i++)
	{
		m_array[i] = new T[m_col];
	}

	if (rows > m_row) 
	{
		for (auto i = 0; i < m_row; i++) 
		{
			for (auto ii = 0; ii < m_col; ii++) 
			{
				m_array[i][ii] = temp[i][ii];
			}
		}
	}
	else
	{
		for (auto i = 0; i < rows; i++) 
		{
			for (auto ii = 0; ii < m_col; ii++) 
			{
				m_array[i][ii] = temp[i][ii];
			}
		}
	}

	for (auto i = 0; i < m_row; i++)
	{
		delete[] temp[i];
	}

	delete[] temp;
	m_row = rows;
}

template<class T>
int Array2D_P<T>::getColumn() const
{
	return m_col;
}

template<class T>
void Array2D_P<T>::setColumn(int columns)
{
	if (columns <= 0)
	{
		throw Exception("***Exception Error: Columns Has to be greater than 0!***\n");
	}

	T** temp = new T*[m_row];

	for (auto i = 0; i < m_row; i++)
	{
		temp[i] = new T[m_col];
	}

	for (auto i = 0; i < m_row; i++)
	{
		for (auto ii = 0; ii < m_col; ii++) 
		{
			temp[i][ii] = m_array[i][ii];
		}
	}

	for (auto i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	delete[] m_array;

	m_array = new T*[m_row];

	for (auto i = 0; i < m_row; i++)
	{
		m_array[i] = new T[columns];
	}

	if (columns > m_col) 
	{		
		for (auto i = 0; i < m_row; i++) 
		{
			for (auto ii = 0; ii < m_col; ii++) 
			{
				m_array[i][ii] = temp[i][ii];
			}
		}
	}
	else
	{
		for (auto i = 0; i < m_row; i++) 
		{
			for (auto ii = 0; ii < columns; ii++) 
			{
				m_array[i][ii] = temp[i][ii];
			}
		}
	}

	for (auto i = 0; i < m_row; i++)
	{
		delete[] temp[i];
	}

	delete[] temp;
	m_col = columns;
}

template<class T>
T & Array2D_P<T>::Select(int row, int column)
{
	if (column > m_col - 1 || column < 0)
	{
		throw Exception("***Exception Error: Column Index is out of Bounds!***\n");
	}
	return m_array[row][column];
}

#endif