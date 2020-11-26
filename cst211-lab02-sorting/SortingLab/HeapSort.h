#ifndef HEAPSORT_H
#define HEAPSORT_H

template<class T>
class HeapSort : public ISortingAlgorithm<T>
{
public:
	HeapSort(Containers<T> &containers, size_t size) : ISortingAlgorithm(containers, size, "Heap Sort") {}
	~HeapSort() {}

	void heapifyCArray(T** cArray, int n, int i);
	void heapifyStlVector(vector<T>* stlVector, int n, int i);
	void heapifyMyArray(Array<T>* myArray, int n, int i);
	SortResults Sort() override;
	double SortCArray() override;
	double SortstlVector() override;
	double SortMyArray() override;
};

template <class T>
void HeapSort<T>::heapifyCArray(T** cArray, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2; 

	if (l < n && *cArray[l] > *cArray[largest])
		largest = l;

	if (r < n && *cArray[r] > *cArray[largest])
		largest = r;

	if (largest != i)
	{
		swap(*cArray[i], *cArray[largest]);
		heapifyCArray(cArray, n, largest);
	}
}

template <class T>
void HeapSort<T>::heapifyStlVector(vector<T>* stlVector, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && (*stlVector)[l] >(*stlVector)[largest])
		largest = l;

	if (r < n && (*stlVector)[r] >(*stlVector)[largest])
		largest = r;

	if (largest != i)
	{
		swap((*stlVector)[i], (*stlVector)[largest]);
		heapifyStlVector(stlVector, n, largest);
	}
}

template <class T>
void HeapSort<T>::heapifyMyArray(Array<T>* myArray, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && (*myArray)[l] >(*myArray)[largest])
		largest = l;

	if (r < n && (*myArray)[r] >(*myArray)[largest])
		largest = r;

	if (largest != i)
	{
		swap((*myArray)[i], (*myArray)[largest]);
		heapifyMyArray(myArray, n, largest);
	}
}

template <class T>
SortResults HeapSort<T>::Sort()
{
	double cArrayResults = SortCArray();
	double stlVectorResults = SortstlVector();
	double myArrayResults = SortMyArray();

	return SortResults(cArrayResults, stlVectorResults, myArrayResults);
}

template <class T>
double HeapSort<T>::SortCArray()
{
	T** cArray = m_containers.GetCArray();

	int n = m_size;

	std::clock_t start = std::clock();
	for (int i = n / 2 - 1; i >= 0; i--)
		heapifyCArray(cArray, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(*cArray[0], *cArray[i]);
		heapifyCArray(cArray, i, 0);
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
double HeapSort<T>::SortstlVector()
{
	vector<T>* stlVector = m_containers.GetStlVector();

	int n = m_size;

	std::clock_t start = std::clock();
	for (int i = n / 2 - 1; i >= 0; i--)
		heapifyStlVector(stlVector, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap((*stlVector)[0], (*stlVector)[i]);
		heapifyStlVector(stlVector, i, 0);
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
double HeapSort<T>::SortMyArray()
{
	Array<T>* myArray = m_containers.GetMyArray();

	int n = m_size;

	std::clock_t start = std::clock();
	for (int i = n / 2 - 1; i >= 0; i--)
		heapifyMyArray(myArray, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap((*myArray)[0], (*myArray)[i]);
		heapifyMyArray(myArray, i, 0);
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

#endif
