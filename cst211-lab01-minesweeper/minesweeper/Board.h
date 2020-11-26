#ifndef BOARD_H
#define BOARD_H

#include <ctime> 
#include <cstdlib>

#include "Array2D.h"
#include "Cell.h"

class Board
{
public:
	Board();
	void inputDifficulty();
	void setupGameStats();
	void printPlayable();
	int getMines() const;
	void setupMines();
	void printSolution();
	void setNumbers();
	void setSpaces();
	void inputIndex();
	bool getGameOver() const;
	void revealMore(int x, int y);
	void reveal(int x, int y);
	void checkWin();
	bool getWin() const;
private:
	Array2D<Cell> m_solution;
	Array2D<Cell> m_playable;
	char m_difficulty;
	int m_mines;
	int m_inputRow;
	int m_inputCol;
	int m_flagsLeft;
	char m_showOrFlag;
	bool m_gameOver;
	bool win;
};

inline Board::Board(): m_difficulty('x'), m_mines(0), m_inputRow(0), m_inputCol(0), m_flagsLeft(0), m_showOrFlag('x'), m_gameOver(false), win(false)
{
}

inline void Board::inputDifficulty()
{
	while (m_difficulty == 'x')
	{
		cout << "Enter your Difficulty (b)eginner, (i)ntermediate, or (e)xpert: " << endl;
		cin >> m_difficulty;

		if(m_difficulty == 'b' || m_difficulty == 'i' || m_difficulty == 'e')
		{
			break;
		}

		m_difficulty = 'x';
	}
}

inline void Board::setupGameStats()
{
	if(m_difficulty == 'b')
	{
		m_solution.setRow(10);
		m_solution.setColumn(10);
		m_mines = 10;
		m_flagsLeft = m_mines;

		for(auto i = 0; i < m_solution.getRow(); i++)
		{
			for(auto j = 0; j < m_solution.getColumn(); j++)
			{
				m_solution[i][j].setData('?');
			}
		}

		m_playable = m_solution;

	}else if (m_difficulty == 'i')
	{
		m_solution.setRow(16);
		m_solution.setColumn(16);
		m_mines = 40;
		m_flagsLeft = m_mines;

		for (auto i = 0; i < m_solution.getRow(); i++)
		{
			for (auto j = 0; j < m_solution.getColumn(); j++)
			{
				m_solution[i][j].setData('?');
			}
		}

		m_playable = m_solution;

	}else if (m_difficulty == 'e')
	{
		m_solution.setRow(16);
		m_solution.setColumn(30);
		m_mines = 100;
		m_flagsLeft = m_mines;

		for (auto i = 0; i < m_solution.getRow(); i++)
		{
			for (auto j = 0; j < m_solution.getColumn(); j++)
			{
				m_solution[i][j].setData('?');
			}
		}

		m_playable = m_solution;
	}
}

inline void Board::printPlayable()
{
	cout << endl << "Flags Left: " << m_flagsLeft << endl;

	cout << endl << "      ";

	for (auto k = 0; k < m_playable.getColumn(); k++)
	{
		if (k < 10) {
			cout << " " << k << "    ";
		}
		else { cout << " " << k << "   "; }
	}

	if (m_difficulty == 'b') {
		cout << endl << "    -------------------------------------------------------------";
	}else if (m_difficulty == 'i')
	{
		cout << endl << "    -------------------------------------------------------------------------------------------------";
	}else if (m_difficulty == 'e')
	{
		cout << endl << "    -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	}

	cout << endl;

	for (auto i = 0; i < m_playable.getRow(); i++)
	{
		if (i < 10) {
			cout << " " << i << "  |  ";
		}
		else { cout << i << "  |  "; }

		for (auto j = 0; j < m_playable.getColumn(); j++)
		{
			cout << m_playable[i][j].getData() << "  |  ";
		}

		if (m_difficulty == 'b') {
			cout << endl << "    -------------------------------------------------------------";
		}
		else if (m_difficulty == 'i')
		{
			cout << endl << "    -------------------------------------------------------------------------------------------------";
		}
		else if (m_difficulty == 'e')
		{
			cout << endl << "    -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
		}
		cout << endl;
	}
	cout << endl;
}

inline int Board::getMines() const
{
	return m_mines;
}

inline void Board::setupMines()
{
	srand(static_cast<unsigned>(time(nullptr)));

	auto highest_row = m_solution.getRow();
	auto highest_col = m_solution.getColumn();

	for(auto i = 0; i < m_mines; i++)
	{
		while (true)
		{
			auto rand_row = (rand() % highest_row);
			auto rand_col = (rand() % highest_col);

			if (m_solution[rand_row][rand_col].getData() != '@') {
				m_solution[rand_row][rand_col].setData('@');
				break;
			}
		}
	}
}

inline void Board::printSolution()
{
	cout << endl << "      ";

	for (auto k = 0; k < m_playable.getColumn(); k++)
	{
		if (k < 10) {
			cout << " " << k << "    ";
		}
		else { cout << " " << k << "   "; }
	}

	if (m_difficulty == 'b') {
		cout << endl << "    -------------------------------------------------------------";
	}
	else if (m_difficulty == 'i')
	{
		cout << endl << "    -------------------------------------------------------------------------------------------------";
	}
	else if (m_difficulty == 'e')
	{
		cout << endl << "    -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	}

	cout << endl;

	for (auto i = 0; i < m_solution.getRow(); i++)
	{
		if (i < 10) {
			cout << " " << i << "  |  ";
		}
		else { cout << i << "  |  "; }


		for (auto j = 0; j < m_solution.getColumn(); j++)
		{
			cout << m_solution[i][j].getData() << "  |  ";
		}

		if (m_difficulty == 'b') {
			cout << endl << "    -------------------------------------------------------------";
		}
		else if (m_difficulty == 'i')
		{
			cout << endl << "    -------------------------------------------------------------------------------------------------";
		}
		else if (m_difficulty == 'e')
		{
			cout << endl << "    -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
		}
		cout << endl;
	}
	cout << endl;
}

inline void Board::setNumbers()
{

	for (auto i = 0; i < m_solution.getRow(); i++)
	{
		for (auto j = 0; j < m_solution.getColumn(); j++)
		{
			if(m_solution[i][j].getData() == '@')
			{
				if (i - 1 >= 0 && j - 1 >= 0)
				{
					//top left
					if (m_solution[i - 1][j - 1].getData() == '?')
					{
						m_solution[i - 1][j - 1].setData('1');
					}
					else if (m_solution[i - 1][j - 1].getData() == '1')
					{
						m_solution[i - 1][j - 1].setData('2');
					}
					else if (m_solution[i - 1][j - 1].getData() == '2')
					{
						m_solution[i - 1][j - 1].setData('3');
					}
					else if (m_solution[i - 1][j - 1].getData() == '3')
					{
						m_solution[i - 1][j - 1].setData('4');
					}
					else if (m_solution[i - 1][j - 1].getData() == '4')
					{
						m_solution[i - 1][j - 1].setData('5');
					}
					else if (m_solution[i - 1][j - 1].getData() == '5')
					{
						m_solution[i - 1][j - 1].setData('6');
					}
					else if (m_solution[i - 1][j - 1].getData() == '6')
					{
						m_solution[i - 1][j - 1].setData('7');
					}
					else if (m_solution[i - 1][j - 1].getData() == '7')
					{
						m_solution[i - 1][j - 1].setData('8');
					}
				}

				if (i - 1 >= 0)
				{
					//top center
					if (m_solution[i - 1][j].getData() == '?')
					{
						m_solution[i - 1][j].setData('1');
					}
					else if (m_solution[i - 1][j].getData() == '1')
					{
						m_solution[i - 1][j].setData('2');
					}
					else if (m_solution[i - 1][j].getData() == '2')
					{
						m_solution[i - 1][j].setData('3');
					}
					else if (m_solution[i - 1][j].getData() == '3')
					{
						m_solution[i - 1][j].setData('4');
					}
					else if (m_solution[i - 1][j].getData() == '4')
					{
						m_solution[i - 1][j].setData('5');
					}
					else if (m_solution[i - 1][j].getData() == '5')
					{
						m_solution[i - 1][j].setData('6');
					}
					else if (m_solution[i - 1][j].getData() == '6')
					{
						m_solution[i - 1][j].setData('7');
					}
					else if (m_solution[i - 1][j].getData() == '7')
					{
						m_solution[i - 1][j].setData('8');
					}
				}

				if (i - 1 >= 0 && j + 1 < m_solution.getColumn())
				{
					//top right
					if (m_solution[i - 1][j + 1].getData() == '?')
					{
						m_solution[i - 1][j + 1].setData('1');
					}
					else if (m_solution[i - 1][j + 1].getData() == '1')
					{
						m_solution[i - 1][j + 1].setData('2');
					}
					else if (m_solution[i - 1][j + 1].getData() == '2')
					{
						m_solution[i - 1][j + 1].setData('3');
					}
					else if (m_solution[i - 1][j + 1].getData() == '3')
					{
						m_solution[i - 1][j + 1].setData('4');
					}
					else if (m_solution[i - 1][j + 1].getData() == '4')
					{
						m_solution[i - 1][j + 1].setData('5');
					}
					else if (m_solution[i - 1][j + 1].getData() == '5')
					{
						m_solution[i - 1][j + 1].setData('6');
					}
					else if (m_solution[i - 1][j + 1].getData() == '6')
					{
						m_solution[i - 1][j + 1].setData('7');
					}
					else if (m_solution[i - 1][j + 1].getData() == '7')
					{
						m_solution[i - 1][j + 1].setData('8');
					}
				}

				if (j + 1 < m_solution.getColumn())
				{
					//mid right
					if (m_solution[i][j + 1].getData() == '?')
					{
						m_solution[i][j + 1].setData('1');
					}
					else if (m_solution[i][j + 1].getData() == '1')
					{
						m_solution[i][j + 1].setData('2');
					}
					else if (m_solution[i][j + 1].getData() == '2')
					{
						m_solution[i][j + 1].setData('3');
					}
					else if (m_solution[i][j + 1].getData() == '3')
					{
						m_solution[i][j + 1].setData('4');
					}
					else if (m_solution[i][j + 1].getData() == '4')
					{
						m_solution[i][j + 1].setData('5');
					}
					else if (m_solution[i][j + 1].getData() == '5')
					{
						m_solution[i][j + 1].setData('6');
					}
					else if (m_solution[i][j + 1].getData() == '6')
					{
						m_solution[i][j + 1].setData('7');
					}
					else if (m_solution[i][j + 1].getData() == '7')
					{
						m_solution[i][j + 1].setData('8');
					}
				}

				if (i + 1 < m_solution.getRow() && j + 1 < m_solution.getColumn())
				{
					//bot right
					if (m_solution[i + 1][j + 1].getData() == '?')
					{
						m_solution[i + 1][j + 1].setData('1');
					}
					else if (m_solution[i + 1][j + 1].getData() == '1')
					{
						m_solution[i + 1][j + 1].setData('2');
					}
					else if (m_solution[i + 1][j + 1].getData() == '2')
					{
						m_solution[i + 1][j + 1].setData('3');
					}
					else if (m_solution[i + 1][j + 1].getData() == '3')
					{
						m_solution[i + 1][j + 1].setData('4');
					}
					else if (m_solution[i + 1][j + 1].getData() == '4')
					{
						m_solution[i + 1][j + 1].setData('5');
					}
					else if (m_solution[i + 1][j + 1].getData() == '5')
					{
						m_solution[i + 1][j + 1].setData('6');
					}
					else if (m_solution[i + 1][j + 1].getData() == '6')
					{
						m_solution[i + 1][j + 1].setData('7');
					}
					else if (m_solution[i + 1][j + 1].getData() == '7')
					{
						m_solution[i + 1][j + 1].setData('8');
					}
				}

				if (i + 1 < m_solution.getRow())
				{
					//bot center
					if (m_solution[i + 1][j].getData() == '?')
					{
						m_solution[i + 1][j].setData('1');
					}
					else if (m_solution[i + 1][j].getData() == '1')
					{
						m_solution[i + 1][j].setData('2');
					}
					else if (m_solution[i + 1][j].getData() == '2')
					{
						m_solution[i + 1][j].setData('3');
					}
					else if (m_solution[i + 1][j].getData() == '3')
					{
						m_solution[i + 1][j].setData('4');
					}
					else if (m_solution[i + 1][j].getData() == '4')
					{
						m_solution[i + 1][j].setData('5');
					}
					else if (m_solution[i + 1][j].getData() == '5')
					{
						m_solution[i + 1][j].setData('6');
					}
					else if (m_solution[i + 1][j].getData() == '6')
					{
						m_solution[i + 1][j].setData('7');
					}
					else if (m_solution[i + 1][j].getData() == '7')
					{
						m_solution[i + 1][j].setData('8');
					}
				}

				if (i + 1 < m_solution.getRow() && j - 1 >= 0)
				{
					//bot left
					if (m_solution[i + 1][j - 1].getData() == '?')
					{
						m_solution[i + 1][j - 1].setData('1');
					}
					else if (m_solution[i + 1][j - 1].getData() == '1')
					{
						m_solution[i + 1][j - 1].setData('2');
					}
					else if (m_solution[i + 1][j - 1].getData() == '2')
					{
						m_solution[i + 1][j - 1].setData('3');
					}
					else if (m_solution[i + 1][j - 1].getData() == '3')
					{
						m_solution[i + 1][j - 1].setData('4');
					}
					else if (m_solution[i + 1][j - 1].getData() == '4')
					{
						m_solution[i + 1][j - 1].setData('5');
					}
					else if (m_solution[i + 1][j - 1].getData() == '5')
					{
						m_solution[i + 1][j - 1].setData('6');
					}
					else if (m_solution[i + 1][j - 1].getData() == '6')
					{
						m_solution[i + 1][j - 1].setData('7');
					}
					else if (m_solution[i + 1][j - 1].getData() == '7')
					{
						m_solution[i + 1][j - 1].setData('8');
					}
				}

				if (j - 1 >= 0)
				{
					//mid left
					if (m_solution[i][j - 1].getData() == '?')
					{
						m_solution[i][j - 1].setData('1');
					}
					else if (m_solution[i][j - 1].getData() == '1')
					{
						m_solution[i][j - 1].setData('2');
					}
					else if (m_solution[i][j - 1].getData() == '2')
					{
						m_solution[i][j - 1].setData('3');
					}
					else if (m_solution[i][j - 1].getData() == '3')
					{
						m_solution[i][j - 1].setData('4');
					}
					else if (m_solution[i][j - 1].getData() == '4')
					{
						m_solution[i][j - 1].setData('5');
					}
					else if (m_solution[i][j - 1].getData() == '5')
					{
						m_solution[i][j - 1].setData('6');
					}
					else if (m_solution[i][j - 1].getData() == '6')
					{
						m_solution[i][j - 1].setData('7');
					}
					else if (m_solution[i][j - 1].getData() == '7')
					{
						m_solution[i][j - 1].setData('8');
					}
				}
			}
		}
	}
}

inline void Board::setSpaces()
{
	for (auto i = 0; i < m_solution.getRow(); i++)
	{
		for (auto j = 0; j < m_solution.getColumn(); j++)
		{
			if(m_solution[i][j].getData() == '?')
			{
				m_solution[i][j].setData('_');
			}
		}
	}
}

inline void Board::inputIndex()
{
	while (true)
	{
		cout << "Enter the Row#: ";
		cin >> m_inputRow;

		if(m_inputRow >= 0 && m_inputRow < m_playable.getRow()){break;}
	}

	while (true)
	{
		cout << "Enter the Column#: ";
		cin >> m_inputCol;

		if(m_inputCol < m_playable.getColumn() && m_inputCol >= 0){break;}
	}

	while (true)
	{
		cout << "Show cell or place/remove a flag here? (s/f): ";
		cin >> m_showOrFlag;

		if (m_showOrFlag == 's' || m_showOrFlag == 'f') { break; }
	}

	if(m_showOrFlag == 'f')
	{
		if (m_playable[m_inputRow][m_inputCol].getData() != 'F') {
			m_playable[m_inputRow][m_inputCol].placeFlag();
			--m_flagsLeft;
		}
		else if (m_playable[m_inputRow][m_inputCol].getData() == 'F')
		{
			if(m_playable[m_inputRow][m_inputCol].getFlipped() == false)
			{
				m_playable[m_inputRow][m_inputCol].setData('?');
				++m_flagsLeft;
			}else if (m_playable[m_inputRow][m_inputCol].getFlipped() == true)
			{
				m_playable[m_inputRow][m_inputCol] = m_solution[m_inputRow][m_inputCol];
				++m_flagsLeft;
			}
		}
	}

	if(m_showOrFlag == 's')
	{
		reveal(m_inputRow, m_inputCol);

		if(m_playable[m_inputRow][m_inputCol].getData() == '@')
		{
			m_gameOver = true;
		}else if (m_playable[m_inputRow][m_inputCol].getData() == '_')
		{
			revealMore(m_inputRow, m_inputCol);
		}
	}
}

inline bool Board::getGameOver() const
{
	return m_gameOver;
}

inline void Board::revealMore(int x, int y)
{
	auto minx = (x <= 0 ? 0 : x - 1);
	auto miny = (y <= 0 ? 0 : y - 1);
	auto maxx = (x >= m_solution.getColumn() - 1 ? m_solution.getColumn() : x + 2);
	auto maxy = (y >= m_solution.getRow() - 1 ? m_solution.getRow() : y + 2);

	for (auto i = minx; i < maxx; i++) {
		for (auto j = miny; j < maxy; j++) {
			if (m_playable[i][j].getData() != '@' && m_playable[i][j].getFlipped() == false) {
				reveal(i, j);
				if (m_solution[i][j].getData() == '_') {
					revealMore(i, j);
				}
			}
		}
	}
}

inline void Board::reveal(int x, int y)
{
	m_playable[x][y] = m_solution[x][y];
	m_playable[x][y].setFlipped();
}

inline void Board::checkWin()
{
	auto counter = 0;
	for (auto i = 0; i < m_solution.getRow(); i++)
	{
		for (auto j = 0; j < m_solution.getColumn(); j++)
		{
			if(m_playable[i][j].getFlipped() == true)
			{
				++counter;
			}
		}
	}

	if(counter == m_playable.getRow() * m_playable.getColumn() - m_mines)
	{
		win = true;
	}
}

inline bool Board::getWin() const
{
	return win;
}

#endif
