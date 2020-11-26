#ifndef MERGESORT_H
#define MERGESORT_H

template<class T>
class MergeSort : public ISortingAlgorithm<T>
{
public:
	MergeSort(Containers<T> &containers, size_t size) : ISortingAlgorithm(containers, size, "Merge Sort") {}
	~MergeSort() {}

	SortResults Sort() override;
	double SortCArray() override;
	void mergeSortCArray(T** cArray, int i, int j);
	void mergeCArray(T** cArray, int i, int mid, int j);
	double SortstlVector() override;
	void mergeSortStlVector(vector<T>* stlVector, int i, int j);
	void mergeStlVector(vector<T>* stlVector, int i, int mid, int j);
	double SortMyArray() override;
	void mergeSortMyArray(Array<T>* myArray, int i, int j);
	void mergeMyArray(Array<T>* myArray, int i, int mid, int j);
};

template <class T>
SortResults MergeSort<T>::Sort()
{
	double cArrayResults = SortCArray();
	double stlVectorResults = SortstlVector();
	double myArrayResults = SortMyArray();

	return SortResults(cArrayResults, stlVectorResults, myArrayResults);
}

template <class T>
double MergeSort<T>::SortCArray()
{
	T** cArray = m_containers.GetCArray();

	std::clock_t start = std::clock();
	int i = 0;
	int j = m_size - 1;
	mergeSortCArray(cArray, i, j);
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
void MergeSort<T>::mergeSortCArray(T** cArray, int i, int j)
{
	if (i < j) {
		int mid = (i + j) / 2;
		mergeSortCArray(cArray, i, mid);
		mergeSortCArray(cArray, mid + 1, j);
		mergeCArray(cArray, i, mid, j);
	}
}

template <class T>
void MergeSort<T>::mergeCArray(T** cArray, int i, int mid, int j)
{
	int sizeOfTemp = j - i + 1;
	T* temp = new T[sizeOfTemp];
	int left = i, right = mid + 1, it = 0;

	while (left <= mid && right <= j) 
	{
		if (*cArray[left] <= *cArray[right])
			temp[it++] = *cArray[left++];
		else
			temp[it++] = *cArray[right++];
	}
	while (left <= mid) 
	{
		temp[it++] = *cArray[left++];
	}
	while (right <= j)
	{
		temp[it++] = *cArray[right++];
	}

	for (int k = 0; k < sizeOfTemp; k++)
	{
		*cArray[i + k] = temp[k];
	}
	delete[] temp;
}

template <class T>
double MergeSort<T>::SortstlVector()
{
	vector<T>* stlVector = m_containers.GetStlVector();

	std::clock_t start = std::clock();
	int i = 0;
	int j = m_size - 1;
	mergeSortStlVector(stlVector, i, j);
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
void MergeSort<T>::mergeSortStlVector(vector<T>* stlVector, int i, int j)
{
	if (i < j) {
		int mid = (i + j) / 2;
		mergeSortStlVector(stlVector, i, mid);
		mergeSortStlVector(stlVector, mid + 1, j);
		mergeStlVector(stlVector, i, mid, j);
	}
}

template <class T>
void MergeSort<T>::mergeStlVector(vector<T>* stlVector, int i, int mid, int j)
{
	int sizeOfTemp = j - i + 1;
	T* temp = new T[sizeOfTemp];
	int left = i, right = mid + 1, it = 0;

	while (left <= mid && right <= j)
	{
		if ((*stlVector)[left] <= (*stlVector)[right])
			temp[it++] = (*stlVector)[left++];
		else
			temp[it++] = (*stlVector)[right++];
	}
	while (left <= mid)
	{
		temp[it++] = (*stlVector)[left++];
	}
	while (right <= j)
	{
		temp[it++] = (*stlVector)[right++];
	}

	for (int k = 0; k < sizeOfTemp; k++)
	{
		(*stlVector)[i + k] = temp[k];
	}
	delete[] temp;
}

template <class T>
double MergeSort<T>::SortMyArray()
{
	Array<T>* myArray = m_containers.GetMyArray();

	std::clock_t start = std::clock();
	int i = 0;
	int j = m_size - 1;
	mergeSortMyArray(myArray, i, j);
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
void MergeSort<T>::mergeSortMyArray(Array<T>* myArray, int i, int j)
{
	if (i < j) {
		int mid = (i + j) / 2;
		mergeSortMyArray(myArray, i, mid);
		mergeSortMyArray(myArray, mid + 1, j);
		mergeMyArray(myArray, i, mid, j);
	}
}

template <class T>
void MergeSort<T>::mergeMyArray(Array<T>* myArray, int i, int mid, int j)
{
	int sizeOfTemp = j - i + 1;
	T* temp = new T[sizeOfTemp];
	int left = i, right = mid + 1, it = 0;

	while (left <= mid && right <= j)
	{
		if ((*myArray)[left] <= (*myArray)[right])
			temp[it++] = (*myArray)[left++];
		else
			temp[it++] = (*myArray)[right++];
	}
	while (left <= mid)
	{
		temp[it++] = (*myArray)[left++];
	}
	while (right <= j)
	{
		temp[it++] = (*myArray)[right++];
	}

	for (int k = 0; k < sizeOfTemp; k++)
	{
		(*myArray)[i + k] = temp[k];
	}
	delete[] temp;
}

#endif
