#ifndef CARD_H
#define CARD_H
#include <string>
#include "Windows.h"
#include "conio.h"

const size_t BLACK = 0;
const size_t RED = 12;
const size_t WHITE = 23;
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

enum cardRank
{
	Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
};

enum cardSuit
{
	Spade, Diamond, Club, Heart
};

char * rankText[] = { " ", "A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K" };

char * suitText[] = { "S", "D", "C", "H" };

class Card
{
public:
	Card();
	Card(int rank, int suit);
	~Card();
	int getRank() const;
	char* getTextRank() const;
	int getSuit() const;
	char* getTextSuit() const;
	bool getColor() const;
	void setRank(int rank);
	void setSuit(int suit);
	void setColor(bool color);
	friend std::ostream & operator<<(std::ostream & os, const Card & polynomial);
	bool operator==(const Card & rhs) const;
	bool operator!=(const Card & rhs) const;
private:
	int m_rank;
	int m_suit;
	bool m_color;//true = red;

};

inline Card::Card() : m_rank(0), m_suit(0), m_color(false)
{
}

inline Card::Card(int rank, int suit) : m_rank(rank), m_suit(suit), m_color(false)
{
}

inline Card::~Card() {}

inline int Card::getRank() const
{
	return m_rank;
}

inline char* Card::getTextRank() const
{
	for (auto i = 1; 1 < 14; i++)
	{
		if (m_rank == i)
		{
			return rankText[i];
		}
	}
}

inline int Card::getSuit() const
{
	return m_suit;
}

inline char* Card::getTextSuit() const
{
	for (auto i = 0; 1 < 4; i++)
	{
		if (m_suit == i)
		{
			return suitText[i];
		}
	}
}

inline bool Card::getColor() const
{
	return m_color;
}

inline void Card::setRank(int rank)
{
	m_rank = rank;
}

inline void Card::setSuit(int suit)
{
	m_suit = suit;
}

inline void Card::setColor(bool color)
{
	m_color = color;
}


inline std::ostream & operator<<(std::ostream & os, const Card &card)
{
	if (card.getColor() == true)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		os << card.getTextRank() << card.getTextSuit();
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	}
	else
	{
		os << card.getTextRank() << card.getTextSuit();
	}

	return os;
}


inline bool Card::operator==(const Card & rhs) const
{
	if(m_rank == rhs.getRank() && m_suit == rhs.getSuit())
	{
		return true;
	}
	return false;
}


inline bool Card::operator!=(const Card & rhs) const
{
	if (m_rank == rhs.getRank() && m_suit == rhs.getSuit())
	{
		return false;
	}
	return true;
}

#endif