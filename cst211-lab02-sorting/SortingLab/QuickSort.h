#ifndef QUICKSORT_H
#define QUICKSORT_H

template<class T>
class QuickSort : public ISortingAlgorithm<T>
{
public:
	QuickSort(Containers<T> &containers, size_t size) : ISortingAlgorithm(containers, size, "Quick Sort") {}
	~QuickSort() {}

	SortResults Sort() override;
	double SortCArray() override;
	void quickSortCArray(T** cArray, int left, int right);
	double SortstlVector() override;
	void quickSortStlVector(vector<T>* stlVector, int left, int right);
	double SortMyArray() override;
	void quickSortMyArray(Array<T>* myArray, int left, int right);
};

template <class T>
SortResults QuickSort<T>::Sort()
{
	double cArrayResults = SortCArray();
	double stlVectorResults = SortstlVector();
	double myArrayResults = SortMyArray();

	return SortResults(cArrayResults, stlVectorResults, myArrayResults);
}

template <class T>
double QuickSort<T>::SortCArray()
{
	T** cArray = m_containers.GetCArray();
	int left = 0;
	int right = m_size - 1;
	std::clock_t start = std::clock();
	quickSortCArray(cArray, left, right);
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;

}

template <class T>
void QuickSort<T>::quickSortCArray(T** cArray, int left, int right)
{
	int i = left, j = right;
	int pivot = *cArray[(left + right) / 2];

	while (i <= j)
	{
		while (*cArray[i] < pivot)
		{
			i++;
		}
		while (*cArray[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			T tmp = *cArray[i];
			*cArray[i] = *cArray[j];
			*cArray[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j)
	{
		quickSortCArray(cArray, left, j);
	}
	if (i < right)
	{
		quickSortCArray(cArray, i, right);
	}
}

template <class T>
double QuickSort<T>::SortstlVector()
{
	vector<T>* stlVector = m_containers.GetStlVector();
	int left = 0;
	int right = m_size - 1;
	std::clock_t start = std::clock();
	quickSortStlVector(stlVector, left, right);
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
void QuickSort<T>::quickSortStlVector(vector<T>* stlVector, int left, int right)
{
	int i = left, j = right;
	int pivot = (*stlVector)[(left + right) / 2];

	while (i <= j)
	{
		while ((*stlVector)[i] < pivot)
		{
			i++;
		}
		while ((*stlVector)[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			T tmp = (*stlVector)[i];
			(*stlVector)[i] = (*stlVector)[j];
			(*stlVector)[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j)
	{
		quickSortStlVector(stlVector, left, j);
	}
	if (i < right)
	{
		quickSortStlVector(stlVector, i, right);
	}
}

template <class T>
double QuickSort<T>::SortMyArray()
{
	Array<T>* myArray = m_containers.GetMyArray();
	int left = 0;
	int right = m_size - 1;
	std::clock_t start = std::clock();
	quickSortMyArray(myArray, left, right);
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
void QuickSort<T>::quickSortMyArray(Array<T>* myArray, int left, int right)
{
	int i = left, j = right;
	int pivot = (*myArray)[(left + right) / 2];

	while (i <= j)
	{
		while ((*myArray)[i] < pivot)
		{
			i++;
		}
		while ((*myArray)[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			T tmp = (*myArray)[i];
			(*myArray)[i] = (*myArray)[j];
			(*myArray)[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j)
	{
		quickSortMyArray(myArray, left, j);
	}
	if (i < right)
	{
		quickSortMyArray(myArray, i, right);
	}
}

#endif
