#include <crtdbg.h>
#include "Windows.h"
#include <cassert>
#include <iostream>
#include "BinarySearchTree.h"
#include "Exception.h"
using namespace std;

#define _CRTDBG_MAP_ALLOC

const size_t GREEN = 10;
const size_t RED = 12;
const size_t WHITE = 23;
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int testArray[5];
int counter = 0;

void PrintTestHeader(const char *);
void PrintTestPass(const char *);
void PrintTestFail(const char *, const char *);

void DeleteTest();

template<class T>
void print(BSNode<T> * & root)
{
	cout << root->getData() << "  ";
	testArray[counter++] = root->getData();
}

void main()
{
	DeleteTest();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	system("pause");
}

inline void PrintTestHeader(const char * testName)
{
	std::cout << "\n************* " << testName << " *************" << std::endl;
}

inline void PrintTestPass(const char * test)
{
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << "\t" << test << ": TEST PASS" << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
}

inline void PrintTestFail(const char * test, const char * message)
{
	SetConsoleTextAttribute(hConsole, RED);
	std::cerr << message << std::endl;
	std::cerr << "\t" << test << ": TEST FAIL" << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
}

inline void DeleteTest()
{
	const char * test = "Delete Test";
	PrintTestHeader(test);

	try
	{
		BinarySearchTree<int> rootNode;

		rootNode.Insert(10);
		rootNode.Insert(45);
		rootNode.Insert(30);
		rootNode.Insert(6);
		rootNode.Insert(999);

		int compareArray[5] = { 6, 10, 30, 45, 999 };

		rootNode.InOrder(print<int>, rootNode.getRoot());

		for (int i = 0; i < rootNode.getCount(); i++)
		{
			assert(compareArray[i] == testArray[i]);
		}
		assert(rootNode.getCount() == 5);

		counter = 0;
		rootNode.Delete(6);
		//rootNode.Delete(999);

		//assert(rootNode.getCount() == 3);

		//int compareArrayOneMoreTime[5] = {6, 10, 30, 45, 999 };

		//rootNode.InOrder(print<int>, rootNode.getRoot());

		//for (int i = 0; i < rootNode.getCount(); i++)
		//{
		//	assert(compareArrayOneMoreTime[i] == testArray[i]);
		//}
		counter = 0;
		PrintTestPass(test);
	}
	catch (Exception & msg)
	{
		PrintTestFail(test, msg.getMessage());
	}
	
}