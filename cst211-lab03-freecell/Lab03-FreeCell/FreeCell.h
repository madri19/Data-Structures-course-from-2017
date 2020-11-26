#ifndef FREECELL_H
#define FREECELL_H

#include "Deck.h"
#include "Array.h"
#include "StackArray.h"
#include "StackLinkedList.h"

class FreeCell
{

public:
	FreeCell();
	void PrintGame();
	void getChoice();
	void Logic();
	void setCurrentCard();
	void checkHomeCells();
	void checkCol();
	void putInFreeCell();
private:
	Deck m_deck;
	Array<Card> m_free_cells_array;
	StackArray<Card> m_home_cells_stack_array[4];
	StackLinkedList<Card> m_playable_cards[8];
	Card m_empty;
	Card m_currentCard;
	int col;
	char m_choice;
	bool m_winner;
};

inline FreeCell::FreeCell()
{
	cout << "\n                        Welcome to FreeCell \n                         by Juan Madrigal" << endl;

	cout << "A = Ace\nT = 10\nJ = Jack\nQ = Queen\nK = King\nS = Spades\nD = Diamonds\nC = Clubs\nH = Hearts\n" << endl;
	cout << "Get all the cards stacked in order for each Suit into Home Cells!\nGoodLuck!\n" << endl;

	m_winner = false;

	m_deck.shuffleDeck();

	m_free_cells_array.setLength(4);//set the 
	m_free_cells_array[0] = m_empty;
	m_free_cells_array[1] = m_empty;
	m_free_cells_array[2] = m_empty;
	m_free_cells_array[3] = m_empty;

	auto counter = 0;

	for(auto i = 0; i < 4; i++)//fill in first 4 columns
	{
		for(auto j = 0; j < 7; j++)
		{
			m_playable_cards[i].Push(m_deck.getCard(counter));
			counter++;
		}
	}


	for(auto i = 0; i < 4; i++)//filling in last 4 columns
	{
		for(auto j = 0; j < 6; j++)
		{
			m_playable_cards[i+4].Push(m_deck.getCard(counter));
			counter++;
		}
	}
	PrintGame();
}

inline void FreeCell::PrintGame()
{
	cout << "           Free Cells                         Home Cells"<< endl;

	cout << "      w     x     y     z                S     ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "D";
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "     C      ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "H";
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	cout << endl << endl;
	cout << "      ";
	
	for (auto i = 0; i < 4; i++)
	{
		if (m_free_cells_array[i] == m_empty)
		{
			cout << "__    ";
		}
		else
		{
			cout << m_free_cells_array[i] << "    ";
		}
	}
	cout << "           ";

	for (auto i = 0; i < 4; i++)
	{
		if (m_home_cells_stack_array[i].isEmpty())
		{
			cout << "__    ";
		}
		else
		{
			cout << m_home_cells_stack_array[i].Peak() << "    ";
		}
	}
	cout << endl << endl;
	cout << endl << "-----------------------------------------------------------------" << endl;

	//Print the Playable Cards
	auto trackRow = 0;

	//get the biggest size of stack
	// ReSharper disable once CppInitializedValueIsAlwaysRewritten
	auto biggest = 0;
	auto storeBig = 0;
	for(auto h = 1; h < 8; h++)
	{
		if(m_playable_cards[h].Size() > m_playable_cards[h-1].Size())
		{
			biggest = m_playable_cards[h].Size();
		}else
		{
			biggest = m_playable_cards[h-1].Size();
		}
		if(biggest > storeBig)
		{
			storeBig = biggest;
		}
		
	}

	for (auto j = 0; j < storeBig; j++)
	{
		for (auto i = 0; i < 8; i++)
		{
			if (m_playable_cards[i].Size() > trackRow)
			{
				if(m_playable_cards[i].isEmpty())
				{
					cout << "         ";
				}
				m_playable_cards[i].PrintIndex(j);
				cout << "       ";
			}
			else
			{
				cout << "         ";
			}
		}
		cout << endl;
		trackRow++;
	}
	cout << endl;
}

inline void FreeCell::getChoice()
{
	m_choice = 'K';

	while (m_choice != '1' && m_choice != '2' && m_choice != '3' && m_choice != '4' && m_choice != '5' && m_choice != '6' && m_choice != '7' && m_choice != '8'
		&& m_choice != 'w' && m_choice != 'x' && m_choice != 'y' && m_choice != 'z')
	{
		cout << "Enter Column# or Free Cell position:   ";
		cin >> m_choice;

		if(m_choice == 'w' && m_free_cells_array[0] == m_empty)
		{
			cout << "This Cell is empty!" << endl;
			m_choice = 'K';
		}
		else if (m_choice == 'x' && m_free_cells_array[1] == m_empty)
		{
			cout << "This Cell is empty!" << endl;
			m_choice = 'K';
		}
		else if (m_choice == 'y' && m_free_cells_array[2] == m_empty)
		{
			cout << "This Cell is empty!" << endl;
			m_choice = 'K';
		}
		else if (m_choice == 'z' && m_free_cells_array[3] == m_empty)
		{
			cout << "This Cell is empty!" << endl;
			m_choice = 'K';
		}
		else if (m_choice == '1' && m_playable_cards[0].isEmpty())
		{
			cout << "This Column is empty!" << endl;
			m_choice = 'K';
		}
		else if (m_choice == '2' && m_playable_cards[1].isEmpty())
		{
			cout << "This Column is empty!" << endl;
			m_choice = 'K';
		}
		else if (m_choice == '3' && m_playable_cards[2].isEmpty())
		{
			cout << "This Column is empty!" << endl;
			m_choice = 'K';
		}
		else if (m_choice == '4' && m_playable_cards[3].isEmpty())
		{
			cout << "This Column is empty!" << endl;
			m_choice = 'K';
		}
		else if (m_choice == '5' && m_playable_cards[4].isEmpty())
		{
			cout << "This Column is empty!" << endl;
			m_choice = 'K';
		}
		else if (m_choice == '6' && m_playable_cards[5].isEmpty())
		{
			cout << "This Column is empty!" << endl;
			m_choice = 'K';
		}
		else if (m_choice == '7' && m_playable_cards[6].isEmpty())
		{
			cout << "This Column is empty!" << endl;
			m_choice = 'K';
		}
		else if (m_choice == '8' && m_playable_cards[7].isEmpty())
		{
			cout << "This Column is empty!" << endl;
			m_choice = 'K';
		}
	}
}

inline void FreeCell::Logic()
{
	while (true)
	{
		getChoice();
		setCurrentCard();

		checkHomeCells();

		if (m_currentCard != m_empty)
		{
			checkCol();
		}

		if (m_currentCard != m_empty && col < 8)
		{
			putInFreeCell();
		}

		if (m_currentCard != m_empty)
		{
			cout << endl << "Couldn't find a move for that card!" << endl << endl;
		}

		PrintGame();

		if(m_winner == true)
		{
			break;
		}
	}
}

inline void FreeCell::setCurrentCard()
{
	col = 123;

	if (m_choice == '1')
	{
		col = 0;
	}
	else if (m_choice == '2')
	{
		col = 1;
	}
	else if (m_choice == '3')
	{
		col = 2;
	}
	else if (m_choice == '4')
	{
		col = 3;
	}
	else if (m_choice == '5')
	{
		col = 4;
	}
	else if (m_choice == '6')
	{
		col = 5;

	}
	else if (m_choice == '7')
	{
		col = 6;
	}
	else if (m_choice == '8')
	{
		col = 7;
	}
	else if (m_choice == 'w')
	{
		m_currentCard = m_free_cells_array[0];
	}
	else if (m_choice == 'x')
	{
		m_currentCard = m_free_cells_array[1];
	}
	else if (m_choice == 'y')
	{
		m_currentCard = m_free_cells_array[2];
	}
	else if (m_choice == 'z')
	{
		m_currentCard = m_free_cells_array[3];
	}

	if (col < 8 && col > -1)
	{
		m_currentCard = m_playable_cards[col].Peak();
	}
}

inline void FreeCell::checkHomeCells()
{

	for (auto i = 0; i < 4; i++)
	{
		if (m_home_cells_stack_array[i].isEmpty() == false)
		{
			if (m_currentCard.getSuit() == m_home_cells_stack_array[i].Peak().getSuit() &&
				m_currentCard.getRank() == 1 + m_home_cells_stack_array[i].Peak().getRank())
			{

				m_home_cells_stack_array[i].Push(m_currentCard);

				if (col < 8)
				{
					m_playable_cards[col].Pop();
				}
				else if (m_choice == 'w')
				{
					m_free_cells_array[0] = m_empty;
				}
				else if (m_choice == 'x')
				{
					m_free_cells_array[1] = m_empty;
				}
				else if (m_choice == 'y')
				{
					m_free_cells_array[2] = m_empty;
				}
				else if (m_choice == 'z')
				{
					m_free_cells_array[3] = m_empty;
				}

				m_currentCard = m_empty;
			}
		}
		else
		{
			for (auto l = 0; l < 4; l++)
			{
				if (m_currentCard.getSuit() == l && m_currentCard.getRank() == 1)
				{
					m_home_cells_stack_array[l].Push(m_currentCard);

					if (col < 8)
					{
						m_playable_cards[col].Pop();
					}
					else if (m_choice == 'w')
					{
						m_free_cells_array[0] = m_empty;
					}
					else if (m_choice == 'x')
					{
						m_free_cells_array[1] = m_empty;
					}
					else if (m_choice == 'y')
					{
						m_free_cells_array[2] = m_empty;
					}
					else if (m_choice == 'z')
					{
						m_free_cells_array[3] = m_empty;
					}

					m_currentCard = m_empty;
				}

			}
		}
	}
	if (m_home_cells_stack_array[0].isFull() && m_home_cells_stack_array[1].isFull() && m_home_cells_stack_array[2].isFull() && m_home_cells_stack_array[3].isFull())
	{
		cout << endl << endl << "Congratualations you are a winner! See you next time!" << endl << endl;
		m_winner = true;
	}
}

inline void FreeCell::checkCol()
{

		if (m_currentCard.getColor() == true)
		{
			for (auto j = 1; j < 14; j++)
			{
				if (m_currentCard.getRank() == j)
				{
					for (auto i = 0; i < 8; i++)
					{
						if (i != col && !m_playable_cards[i].isEmpty())
						{
							if (m_playable_cards[i].Peak().getRank() == m_currentCard.getRank() + 1 && m_playable_cards[i].Peak().getColor() == false)
							{
								m_playable_cards[i].Push(m_currentCard);

								if (col < 8 && !m_playable_cards[col].isEmpty())
								{
									m_playable_cards[col].Pop();
								}
								else if (m_choice == 'w')
								{
									m_free_cells_array[0] = m_empty;
								}
								else if (m_choice == 'x')
								{
									m_free_cells_array[1] = m_empty;
								}
								else if (m_choice == 'y')
								{
									m_free_cells_array[2] = m_empty;
								}
								else if (m_choice == 'z')
								{
									m_free_cells_array[3] = m_empty;
								}
								m_currentCard = m_empty;
								break;
							}
						}
						else if(i != col && m_playable_cards[i].isEmpty() && m_currentCard != m_empty)
						{
							m_playable_cards[i].Push(m_currentCard);

							if (col < 8 && !m_playable_cards[col].isEmpty())
							{
								m_playable_cards[col].Pop();
							}
							else if (m_choice == 'w')
							{
								m_free_cells_array[0] = m_empty;
							}
							else if (m_choice == 'x')
							{
								m_free_cells_array[1] = m_empty;
							}
							else if (m_choice == 'y')
							{
								m_free_cells_array[2] = m_empty;
							}
							else if (m_choice == 'z')
							{
								m_free_cells_array[3] = m_empty;
							}
							m_currentCard = m_empty;
						}
					}
				}
			}
		}
		else if (m_currentCard.getColor() == false)
		{
			for (auto j = 1; j < 14; j++)
			{
				if (m_currentCard.getRank() == j)
				{
					for (auto i = 0; i < 8; i++)
					{
						if (i != col && !m_playable_cards[i].isEmpty())
						{
							if (m_playable_cards[i].Peak().getRank() == m_currentCard.getRank() + 1 && m_playable_cards[i].Peak().getColor() == true)
							{
								m_playable_cards[i].Push(m_currentCard);
								
								if (col < 8)
								{
									m_playable_cards[col].Pop();
								}
								else if (m_choice == 'w')
								{
									m_free_cells_array[0] = m_empty;
								}
								else if (m_choice == 'x')
								{
									m_free_cells_array[1] = m_empty;
								}
								else if (m_choice == 'y')
								{
									m_free_cells_array[2] = m_empty;
								}
								else if (m_choice == 'z')
								{
									m_free_cells_array[3] = m_empty;
								}
								m_currentCard = m_empty;
								break;
							}
						}
						else if (i != col && m_playable_cards[i].isEmpty() && m_currentCard != m_empty)
						{
							m_playable_cards[i].Push(m_currentCard);

							if (col < 8 && !m_playable_cards[col].isEmpty())
							{
								m_playable_cards[col].Pop();
							}
							else if (m_choice == 'w')
							{
								m_free_cells_array[0] = m_empty;
							}
							else if (m_choice == 'x')
							{
								m_free_cells_array[1] = m_empty;
							}
							else if (m_choice == 'y')
							{
								m_free_cells_array[2] = m_empty;
							}
							else if (m_choice == 'z')
							{
								m_free_cells_array[3] = m_empty;
							}
							m_currentCard = m_empty;
						}
					}
				}

			}
		}
}

inline void FreeCell::putInFreeCell()
{
	for(auto i = 0; i < 4; i++)
	{
		if(m_free_cells_array[i] == m_empty)
		{
			m_free_cells_array[i] = m_currentCard;

			if (col < 8)
			{
				m_playable_cards[col].Pop();
			}
			else if (m_choice == 'w')
			{
				m_free_cells_array[0] = m_empty;
			}
			else if (m_choice == 'x')
			{
				m_free_cells_array[1] = m_empty;
			}
			else if (m_choice == 'y')
			{
				m_free_cells_array[2] = m_empty;
			}
			else if (m_choice == 'z')
			{
				m_free_cells_array[3] = m_empty;
			}

			m_currentCard = m_empty;
			break;
		}
	}
}

#endif
