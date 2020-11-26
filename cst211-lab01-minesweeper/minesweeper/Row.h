//Juan Madrigal
#ifndef ROW_H
#define ROW_H

template<class T>
class Array2D;

template<class T>
class Row {

public:
	Row(Array2D<T>& array, int row);
	T & operator[](int column);
	T & operator[](int column) const;
private:
	Array2D<T>& m_array2D;
	int m_row;
};

template<class T>
Row<T>::Row(Array2D<T>& array, int row) : m_array2D(array), m_row(row) {}

template<class T>
T & Row<T>::operator[](int column)
{
	return m_array2D.Select(m_row, column);
}

template<class T>
T & Row<T>::operator[](int column) const
{
	return m_array2D.Select(m_row, column);
}

#endif