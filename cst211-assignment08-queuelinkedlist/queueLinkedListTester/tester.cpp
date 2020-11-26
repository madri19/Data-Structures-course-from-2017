#include <crtdbg.h>
#include "Windows.h"
#include <cassert>
#include <iostream>
#include "Queue.h"
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

void testConstructor();
void testCopyConstructor();
void testConstMethods();
void testAssignmentOperator();
void testAccessors();
void testEnqueueAndDequeue();
void testFront();
void testSize();
void testIsEmpty();
void testModifyFront();
void testUnderflowException();
void testChar();
void testString();

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

	testConstructor();
	testCopyConstructor();
	testConstMethods();
	testAssignmentOperator();
	testAccessors();
	testEnqueueAndDequeue();
	testFront();
	testSize();
	testIsEmpty();
	testModifyFront();
	//testUnderflowException();
	testChar();
	testString();
}

void testConstructor()
{
	const char * test = "Constructor Test";
	PrintTestHeader(test);

	try
	{
		Queue<int> list;

		assert(list.isEmpty() == true);
		assert(list.Size() == 0);

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}


void testCopyConstructor()
{
	const char * test = "Copy Constructor Test";
	PrintTestHeader(test);

	try
	{
		Queue<int> list;

		list.Enqueue(56);

		Queue<int> list2(list);

		assert(list2.isEmpty() == false);
		assert(list.Size() == list2.Size());
		assert(list.Front() == list2.Front());

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testConstMethods()
{
	const char * test = "Constant Method Test";
	PrintTestHeader(test);

	try
	{
		const Queue<int> list;

		assert(list.isEmpty() == true);
		assert(list.Size() == 0);

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testAssignmentOperator()
{
	const char * test = "Assignment Operator Test";
	PrintTestHeader(test);

	try
	{
		Queue<int> list;

		list.Enqueue(41);
		list.Enqueue(13);
		list.Enqueue(89);
		list.Enqueue(7);

		Queue<int> list2;

		list2 = list;

		assert(list.Front() == list2.Front());
		assert(list.Size() == list2.Size());
		assert(list.isEmpty() == list2.isEmpty());

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testAccessors()
{
	const char * test = "Accessor Test";
	PrintTestHeader(test);

	try
	{
		Queue<int> list;

		list.Enqueue(41);
		list.Enqueue(13);
		list.Enqueue(89);
		list.Enqueue(7);

		assert(list.Size() == 4);
		assert(list.Dequeue() == 41);

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testEnqueueAndDequeue()
{
	const char * test = "Enqueue and Dequeue Test";
	PrintTestHeader(test);

	try
	{
		Queue<int> list;

		list.Enqueue(41);
		list.Enqueue(13);
		list.Enqueue(89);
		list.Enqueue(7);

		assert(list.Dequeue() == 41);
		assert(list.Dequeue() == 13);
		assert(list.Dequeue() == 89);
		assert(list.Dequeue() == 7);
		assert(list.isEmpty() == true);

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testFront()
{
	const char * test = "Front Method Test";
	PrintTestHeader(test);

	try
	{
		Queue<int> list;

		list.Enqueue(41);
		list.Enqueue(13);
		list.Enqueue(89);
		list.Enqueue(7);

		assert(list.Front() == 41);

		list.Dequeue();

		assert(list.Front() == 13);

		list.Dequeue();

		assert(list.Front() == 89);

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testSize()
{
	const char * test = "Size Method Test";
	PrintTestHeader(test);

	try
	{
		Queue<int> list;

		assert(list.Size() == 0);

		list.Enqueue(41);
		list.Enqueue(13);
		list.Enqueue(89);
		list.Enqueue(7);
		list.Enqueue(41);
		list.Enqueue(13);
		list.Enqueue(89);
		list.Enqueue(7);
		list.Enqueue(41);
		list.Enqueue(13);
		list.Enqueue(89);
		list.Enqueue(7);
		list.Enqueue(41);
		list.Enqueue(13);
		list.Enqueue(89);
		list.Enqueue(7);

		assert(list.Size() == 16);

		list.Dequeue();

		assert(list.Size() == 15);


		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testIsEmpty()
{
	const char * test = "isEmpty Test";
	PrintTestHeader(test);

	try
	{
		Queue<int> list;

		assert(list.isEmpty() == true);

		list.Enqueue(41);
		list.Enqueue(13);
		list.Enqueue(89);
		list.Enqueue(7);

		assert(list.isEmpty() == false);

		list.Dequeue();
		list.Dequeue();
		list.Dequeue();
		list.Dequeue();

		assert(list.isEmpty() == true);


		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testModifyFront()
{
	const char * test = "Modify Front Method Test";
	PrintTestHeader(test);

	try
	{
		Queue<int> list;

		list.Enqueue(2);
		list.Enqueue(13);
		list.Enqueue(89);
		list.Enqueue(7);

		list.Front() = 700;
		assert(list.Front() == 700);

		list.Front() = 25;
		assert(list.Front() == 25);

		list.Front() = 75;
		assert(list.Front() == 75);

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testUnderflowException()
{
	const char * test = "Underflow Exception Test";
	PrintTestHeader(test);

	try
	{
		Queue<int> list;

		list.Dequeue();

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testChar()
{
	const char * test = "Char Type Test";
	PrintTestHeader(test);

	try
	{
		Queue<char> list;

		list.Enqueue('t');
		list.Enqueue('r');
		list.Enqueue('e');
		list.Enqueue('i');
		list.Enqueue('s');


		Queue<char> list2;

		list2 = list;

		assert(list.Front() == list2.Front());

		PrintTestPass(test);
	}
	catch (Exception exception)
	{
		PrintTestFail(test, exception.getMessage());
	}
}

void testString()
{
	const char * test = "String Type Test";
	PrintTestHeader(test);

	try
	{
		Queue<string> list;

		list.Enqueue("hello");
		list.Enqueue("My name is");
		list.Enqueue("Better");
		list.Enqueue("Than");
		list.Enqueue("Yours");

		Queue<string> list2;

		list2 = list;

		assert(list.Front() == list2.Front());

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