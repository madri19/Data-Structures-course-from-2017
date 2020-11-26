#include "Minesweeper.h"

void startGame();

int main()
{
	auto again = 'y';

	while (again == 'y')
	{
		startGame();

		cout << "Would you like to play again?(y/n): ";
		cin >> again;

		if(again != 'y')
		{
			cout << "Thanks for playing! Good-bye!" << endl;
		}
	}
	return 0;
}

void startGame()
{
	Minesweeper test;
	test.welcome();
	test.prepareGame();
	test.start();
}