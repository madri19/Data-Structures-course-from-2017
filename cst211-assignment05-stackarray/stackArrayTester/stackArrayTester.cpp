#include <crtdbg.h>
#include "Windows.h"
#include <cassert>
#include <iostream>
#include "Stack.h"
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

void underflowException();
void overflowException();
void noPeakException();

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

	//underflowException();
	//overflowException();
	noPeakException();
}

void noPeakException()
{
	const char * test = "Nothing to Peak Exception";
	PrintTestHeader(test);

	try
	{
		Stack<int> bList(5);

		bList.Peak();

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void overflowException()
{
	const char * test = "Overflow Exception";
	PrintTestHeader(test);

	try
	{
		Stack<int> bList(5);

		bList.Push(2);
		bList.Push(2);
		bList.Push(2);
		bList.Push(2);
		bList.Push(2);


		bList.Push(2);

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void underflowException()
{
	const char * test = "Underflow Exception";
	PrintTestHeader(test);

	try
	{
		Stack<int> bList(5);

		bList.Pop();

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