#ifndef ROW_P_H
#define ROW_P_H

template<class T>
class Array2D_P;

template<class T>
class Row_P 
{
public:
	Row_P(Array2D_P<T>& array, int row);
	T & operator[](int column);
	T & operator[](int column) const;
private:
	Array2D_P<T>& m_array2D_P;
	int m_row;
};

template<class T>
Row_P<T>::Row_P(Array2D_P<T>& array, int row): m_array2D_P(array), m_row(row) {}

template<class T>
T & Row_P<T>::operator[](int column)
{
	return m_array2D_P.Select(m_row, column);
}

template<class T>
T & Row_P<T>::operator[](int column) const
{
	return m_array2D_P.Select(m_row, column);
}

#endif