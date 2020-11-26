#ifndef SORTING_H
#define SORTING_H

#include "ISortingAlgorithm.h"
#include "Containers.h"
#include "SortResults.h"

#include "BruteForceBubbleSort.h"
#include "FlaggedBubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

#include <fstream>

template<class T>
class Sorting
{
public:
	static void RunSort(size_t size);
};

template <class T>
void Sorting<T>::RunSort(size_t size)
{
	Containers<T> containers(size);
	//containers.DebugPrintContainers();

	vector<ISortingAlgorithm<T> *> algorithms;

	algorithms.push_back(new BruteForceBubbleSort<T>(containers, size));
	algorithms.push_back(new FlaggedBubbleSort<T>(containers, size));
	algorithms.push_back(new SelectionSort<T>(containers, size));
	algorithms.push_back(new InsertionSort<T>(containers, size));
	algorithms.push_back(new ShellSort<T>(containers, size));
	algorithms.push_back(new HeapSort<T>(containers, size));
	algorithms.push_back(new MergeSort<T>(containers, size));
	algorithms.push_back(new QuickSort<T>(containers, size));


	std::ofstream output;
	output.open("output.csv", std::ofstream::out);

	for(ISortingAlgorithm<T> * algorithm : algorithms)
	{
		SortResults results = algorithm->Sort();
		results.setSortType(algorithm->getName());

		output << results;

		delete algorithm;
	}
	output.close();
	//containers.DebugPrintContainers();
}

#endif