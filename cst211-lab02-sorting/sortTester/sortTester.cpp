#include <crtdbg.h>
#include <cassert>
#include <stdlib.h>

#include "Sorting.h"

#define _CRTDBG_MAP_ALLOC

int main(int argc, char * argv[])
{
	assert(argc == 2);

	Sorting<int>::RunSort(atoi(argv[1]));

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}