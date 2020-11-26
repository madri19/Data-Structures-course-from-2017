#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "Board.h"

class Minesweeper
{
	
public:
	Minesweeper();
	void prepareGame();
	void start();
	static void welcome();
private:
	Board m_board;
};

inline Minesweeper::Minesweeper(){}

inline void Minesweeper::prepareGame()
{
	m_board.inputDifficulty();
	m_board.setupGameStats();
	m_board.setupMines();
	m_board.setNumbers();
	m_board.setSpaces();
}

inline void Minesweeper::start()
{
	while (true)
	{
		m_board.printPlayable();
		m_board.inputIndex();
		if(m_board.getGameOver() == true)
		{
			cout << endl << endl << "GAME OVER BETTER LUCK NEXT TIME!!!!!!!!" << endl << endl;
			m_board.printSolution();
			cout << endl << "GAME OVER BETTER LUCK NEXT TIME!!!!!!!!" << endl << endl;
			break;
		}
		m_board.checkWin();

		if (m_board.getWin() == true)
		{
			cout << endl << endl << "YES YOU ARE A WINNER!!!!!!!!" << endl << endl;
			m_board.printSolution();
			cout << endl << "CONGRATULATIONS FOR WINNING!!!!!!!!!" << endl << endl;
			break;
		}
	}
}

inline void Minesweeper::welcome()
{
	cout << "Welcome to a game of Minesweeper by Juan Madrigal!" << endl
		<< "[?] is an unknown cell." << endl
		<< "[@] is a mine." << endl
		<< "[F] is a flag." << endl
		<< "[_] is an empty cell." << endl
		<< "[1-8] means that cell is touching that many mines." << endl
		<< "Selecting a mine explodes the game and you lose!" << endl
		<< "So try to avoid the mines at all cost!" << endl
		<< "HAVE FUN!" << endl << endl << endl;
}
#endif