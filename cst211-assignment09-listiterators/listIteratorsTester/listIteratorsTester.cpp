#include <crtdbg.h>
#include "Windows.h"
#include <cassert>
#include <iostream>
#include "DoubleLinkedList.h"
#include "ForwardIterator.h"
#include "BackwardIterator.h"
#include "Exception.h"

#define _CRTDBG_MAP_ALLOC

const size_t GREEN = 10;
const size_t RED = 12;
const size_t WHITE = 23;
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void RunTests();
void PrintTestHeader(const char *);
void PrintTestPass(const char *);
void PrintTestFail(const char *, const char *);

void testForwardIteratorAssignment();
void testBackwardIteratorAssignment();
void testForwardIteratorReset();
void testBackwardIteratorReset();
void testForwardIteratorMoveNextPre();
void testBackwardIteratorMoveNextPre(); 
void testForwardIteratorMoveNextPost();
void testBackwardIteratorMoveNextPost();
void testForwardIteratorBoundsException();
void testBackwardIteratorBoundsException();
void testIteratorIncrementDecrementFromUpdate();
void testIteratorConst();


int main()
{
	RunTests();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}

void RunTests()
{
	SetConsoleTextAttribute(hConsole, WHITE);

	testForwardIteratorAssignment();
	testBackwardIteratorAssignment();
	testForwardIteratorReset();
	testBackwardIteratorReset();
	testForwardIteratorMoveNextPre();
	testBackwardIteratorMoveNextPre();
	testForwardIteratorMoveNextPost();
	testBackwardIteratorMoveNextPost();
	//testForwardIteratorBoundsException();
	//testBackwardIteratorBoundsException();
	testIteratorIncrementDecrementFromUpdate();
	testIteratorConst();
}

void testForwardIteratorAssignment()
{
	const char * test = "Forward Iterator Test";
	PrintTestHeader(test);

	try
	{
		DoubleLinkedList<int> list;
		ForwardIterator<int> forwardIterator;

		for(size_t i = 0; i < 5; ++i)
		{
			list.Append(i*5);
		}

		forwardIterator = list.getHead();

		assert(*forwardIterator == list.First());

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testBackwardIteratorAssignment()
{
	const char * test = "Backward Iterator Test";
	PrintTestHeader(test);

	try
	{
		DoubleLinkedList<int> list;
		BackwardIterator<int> backwardIterator;

		for (size_t i = 0; i < 5; ++i)
		{
			list.Append(i * 5);
		}

		backwardIterator = list.getTail();

		assert(*backwardIterator == list.Last());

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testForwardIteratorReset()
{
	const char * test = "Forward Iterator Reset Test";
	PrintTestHeader(test);

	try
	{
		DoubleLinkedList<int> list;

		list.Append(10);
		list.Append(20);
		list.Append(30);
		list.Append(40);
		list.Append(50);
		list.Append(60);
		list.Append(70);

		ForwardIterator<int> forwardIterator;
		forwardIterator = list.getHead();

		for(auto i = 0; i < 3; i++)
		{
			for(auto j = 0; j < 3; j++)
			{
				forwardIterator++;
			}
			forwardIterator.Reset();
		}

		assert(forwardIterator.GetCurrent() == list.First());
		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testBackwardIteratorReset()
{
	const char * test = "Backward Iterator Reset Test";
	PrintTestHeader(test);

	try
	{
		DoubleLinkedList<int> list;

		list.Append(10);
		list.Append(20);
		list.Append(30);
		list.Append(40);
		list.Append(50);
		list.Append(60);
		list.Append(70);

		BackwardIterator<int> backwardIterator;
		backwardIterator = list.getTail();

		for (auto i = 0; i < 3; i++)
		{
			for (auto j = 0; j < 3; j++)
			{
				backwardIterator--;
			}
			backwardIterator.Reset();
		}

		assert(backwardIterator.GetCurrent() == list.Last());
		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testForwardIteratorMoveNextPre()
{
	const char * test = "Forward Iterator MoveNext Pre-Fix Test";
	PrintTestHeader(test);

	try
	{
		int values[] = { 1, 2, 3, 4, 5, 6, 7 };
		int i = 0;

		DoubleLinkedList<int> list;

		list.Append(1);
		list.Append(2);
		list.Append(3);
		list.Append(4);
		list.Append(5);
		list.Append(6);
		list.Append(7);

		ForwardIterator<int> forwardIterator;
		forwardIterator = list.getHead();

		while(!forwardIterator.IsDone())
		{
			assert(*++forwardIterator == values[++i]);
		}

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testBackwardIteratorMoveNextPre()
{
	const char * test = "Backward Iterator MoveNext Pre-Fix Test";
	PrintTestHeader(test);

	try
	{
		int values[] = { 1, 2, 3, 4, 5, 6, 7 };
		int i = 6;

		DoubleLinkedList<int> list;

		list.Append(1);
		list.Append(2);
		list.Append(3);
		list.Append(4);
		list.Append(5);
		list.Append(6);
		list.Append(7);

		BackwardIterator<int> backwardIterator;
		backwardIterator = list.getTail();

		while (!backwardIterator.IsDone())
		{
			assert(*--backwardIterator == values[--i]);
		}

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testForwardIteratorMoveNextPost()
{
	const char * test = "Forward Iterator MoveNext Post-Fix Test";
	PrintTestHeader(test);

	try
	{
		DoubleLinkedList<int> list;

		list.Append(10);
		list.Append(20);
		list.Append(30);
		list.Append(40);
		list.Append(50);
		list.Append(60);
		list.Append(70);

		ForwardIterator<int> forwardIterator;
		forwardIterator = list.getHead();

		forwardIterator++;
		forwardIterator++;
		forwardIterator++;

		assert(forwardIterator.GetCurrent() == 40);


		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testBackwardIteratorMoveNextPost()
{
	const char * test = "Backward Iterator MoveNext Post-Fix Test";
	PrintTestHeader(test);

	try
	{
		DoubleLinkedList<int> list;

		list.Append(10);
		list.Append(20);
		list.Append(30);
		list.Append(40);
		list.Append(50);
		list.Append(60);
		list.Append(70);

		BackwardIterator<int> backwardIterator;
		backwardIterator = list.getTail();

		backwardIterator--;
		backwardIterator--;
		backwardIterator--;
		backwardIterator--;
		backwardIterator--;


		assert(backwardIterator.GetCurrent() == 20);


		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testForwardIteratorBoundsException()
{
	const char * test = "Forward Iterator Out of Bounds Exception Test";
	PrintTestHeader(test);

	try
	{
		DoubleLinkedList<int> list;

		list.Append(10);
		list.Append(20);

		ForwardIterator<int> forwardIterator;
		forwardIterator = list.getHead();

		forwardIterator++;
		forwardIterator++;

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testBackwardIteratorBoundsException()
{
	const char * test = "Backward Iterator Out of Bounds Exception Test";
	PrintTestHeader(test);

	try
	{
		DoubleLinkedList<int> list;

		list.Append(10);
		list.Append(20);

		BackwardIterator<int> backwardIterator;
		backwardIterator = list.getTail();

		backwardIterator--;
		backwardIterator--;

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testIteratorIncrementDecrementFromUpdate()
{
	const char * test = "Test Code from Professor's Email for Increment and Decrement Test";
	PrintTestHeader(test);

	try
	{
		DoubleLinkedList<int> list;

		list.Append(1); list.Append(2); list.Append(3); list.Append(4); list.Append(5);

		ForwardIterator<int> forwardIterator;
		forwardIterator = list.getHead();

		int currentValue = *forwardIterator;
		assert(currentValue == 1);

		int valueWithPostIncrement = *forwardIterator++;
		assert(valueWithPostIncrement == 1);

		int valueAftePostIncrement = *forwardIterator;
		assert(valueAftePostIncrement == 2);

		int valueWithPreIncrement = *++forwardIterator;
		assert(valueWithPreIncrement == 3);

		int valueAfterPreIncrement = *forwardIterator;
		assert(valueAfterPreIncrement == 3);

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}


void testIteratorConst()
{
	const char * test = "Test Const Iterators Test";
	PrintTestHeader(test);

	try
	{
		DoubleLinkedList<int> list;

		int values[] = { 1, 2, 3, 4, 5, 6, 7 };
		int i = 0;

		for ( i = 0; i < 7; ++i)
		{
			list.Append(i * 5);
		}

		const ForwardIterator<int> forwardIterator;

		forwardIterator = list.getHead();

		assert(*forwardIterator == list.First());


		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}





void PrintTestHeader(const char *testName)
{
	std::cout << "\n********** " << testName << " **********" << std::endl;
}

void PrintTestPass(const char * test)
{
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << "\t" << test << ": TEST PASS" << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
}

void PrintTestFail(const char * test, const char * message)
{
	SetConsoleTextAttribute(hConsole, RED);
	std::cerr << message << std::endl;
	std::cerr << "\t" << test << ": TEST FAIL" << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
}