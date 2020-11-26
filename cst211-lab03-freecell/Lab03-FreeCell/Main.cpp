#include "FreeCell.h"
void start();
int main()
{
	start();
	return 0;
}

void start()
{
	char continu = 'y';
	do
	{
		try {
			FreeCell begin;
			begin.Logic();
		}
		catch (Exception &rhs)
		{
			cerr << rhs;
		}
		cout << "Would you like to play again?(y/n): ";
		cin >> continu;
	} while (continu == 'y');
}