#ifndef BRUTEFORCEBUBBLESORT_H
#define BRUTEFORCEBUBBLESORT_H

#include <ctime>

template<class T>
class BruteForceBubbleSort: public ISortingAlgorithm<T>
{
public:
	BruteForceBubbleSort(Containers<T> &containers, size_t size) : ISortingAlgorithm(containers, size, "Brute Force Bubble Sort"){}
	~BruteForceBubbleSort(){}

	SortResults Sort() override;
	double SortCArray() override;
	double SortstlVector() override;
	double SortMyArray() override;
};

template <class T>
SortResults BruteForceBubbleSort<T>::Sort()
{
	double cArrayResults = SortCArray();
	double stlVectorResults = SortstlVector();
	double myArrayResults = SortMyArray();

	return SortResults(cArrayResults, stlVectorResults, myArrayResults);
}

template <class T>
double BruteForceBubbleSort<T>::SortCArray()
{
	T** cArray = m_containers.GetCArray();

	std::clock_t start = std::clock();
	for(size_t i = 1; i < m_size; i++)
	{
		for(size_t j = 0; j < m_size - 1; j++)
		{
			if(*cArray[j] > *cArray[j + 1])
			{
				T temp = *cArray[j];
				*cArray[j] = *cArray[j + 1];
				*cArray[j + 1] = temp;
			}
		}
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
double BruteForceBubbleSort<T>::SortstlVector()
{
	vector<T>* stlVector = m_containers.GetStlVector();

	std::clock_t start = std::clock();
	for (size_t i = 1; i < m_size; i++)
	{
		for (size_t j = 0; j < m_size - 1; j++)
		{
			if ((*stlVector)[j] >(*stlVector)[j + 1])
			{
				T temp = (*stlVector)[j];
				(*stlVector)[j] = (*stlVector)[j + 1];
				(*stlVector)[j + 1] = temp;
			}
		}
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);


	return duration;
}

template <class T>
double BruteForceBubbleSort<T>::SortMyArray()
{
	Array<T>* myArray = m_containers.GetMyArray();

	std::clock_t start = std::clock();
	for (size_t i = 1; i < m_size; i++)
	{
		for (size_t j = 0; j < m_size - 1; j++)
		{
			if ((*myArray)[j] >(*myArray)[j + 1])
			{
				T temp = (*myArray)[j];
				(*myArray)[j] = (*myArray)[j + 1];
				(*myArray)[j + 1] = temp;
			}
		}
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);


	return duration;
}

#endif