#ifndef DECK_H
#define DECK_H

#include <ctime>
#include <algorithm>


#include "Card.h"
#include <iostream>
using namespace std;

class Deck
{
public:
	Deck();
	~Deck();
	void shuffleDeck();
	Card getCard(int index);

	void Print() const;

private:
	Card m_card[52];
};

inline Deck::Deck()
{
	auto counter = 0;

	for (auto i = 0; i < 4; i++)
	{
		for (auto j = 1; j < 14; j++)
		{
			if (i == 1 || i == 3)
			{
				m_card[counter].setColor(true);
			}
			m_card[counter].setSuit(i);
			m_card[counter].setRank(j);
			counter++;
		}
	}
}

inline Deck::~Deck() {}

inline void Deck::shuffleDeck()
{
	srand(time(nullptr));
	std::random_shuffle(&m_card[0], &m_card[51]);
}

inline Card Deck::getCard(int index)
{
	return m_card[index];
}

inline void Deck::Print() const
{
	char * cards[] = { " ", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	const char * okayy[] = { "Spades", "Diamonds", "Clubs", "Hearts" };


	for (auto i = 0; i < 52; i++)
	{
		cout << cards[m_card[i].getRank()] << " of " << okayy[m_card[i].getSuit()] << endl;
	}
}

#endif
