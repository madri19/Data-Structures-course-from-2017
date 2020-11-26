#ifndef CELL_H
#define CELL_H


class Cell
{
public:
	Cell();
	char getData() const;
	void setData(char data);
	bool isMine() const;
	void placeFlag();
	void setFlipped();
	bool getFlipped() const;
private:
	char m_data;
	bool flipped;
};


inline Cell::Cell(): m_data('T'), flipped(false){}

inline char Cell::getData() const
{
	return m_data;
}

inline void Cell::setData(char data)
{
	m_data = data;
}

inline bool Cell::isMine() const
{
	if(m_data == 'M')
	{
		return true;
	}
	return false;
}

inline void Cell::placeFlag()
{
	m_data = 'F';
}

inline void Cell::setFlipped()
{
	flipped = true;
}

inline bool Cell::getFlipped() const
{
	return flipped;
}

#endif
