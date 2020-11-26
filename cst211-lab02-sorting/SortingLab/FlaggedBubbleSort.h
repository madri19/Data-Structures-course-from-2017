#ifndef FLAGGEDBUBBLESORT_H
#define FLAGGEDBUBBLESORT_H

template<class T>
class FlaggedBubbleSort: public ISortingAlgorithm<T>
{
public:
	FlaggedBubbleSort(Containers<T> &containers, size_t size) : ISortingAlgorithm(containers, size, "Flagged Bubble Sort") {}
	~FlaggedBubbleSort() {}

	SortResults Sort() override;
	double SortCArray() override;
	double SortstlVector() override;
	double SortMyArray() override;
};

template <class T>
SortResults FlaggedBubbleSort<T>::Sort()
{
	double cArrayResults = SortCArray();
	double stlVectorResults = SortstlVector();
	double myArrayResults = SortMyArray();

	return SortResults(cArrayResults, stlVectorResults, myArrayResults);
}

template <class T>
double FlaggedBubbleSort<T>::SortCArray()
{
	T** cArray = m_containers.GetCArray();

	std::clock_t start = std::clock();
	for (size_t i = 1; i < m_size; i++) {
		bool isSorted = true; // isSorted = true if a[] is sorted
		for (size_t j = 0; j < m_size - i; j++) {
			if (*cArray[j] > *cArray[j + 1]) { // the larger item bubbles up 
				T temp = *cArray[j];   // and isSorted is set to false,
				*cArray[j] = *cArray[j + 1];     // i.e. the data was not sorted
				*cArray[j + 1] = temp;
				isSorted = false;
			}
		}
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
double FlaggedBubbleSort<T>::SortstlVector()
{
	vector<T>* stlVector = m_containers.GetStlVector();

	std::clock_t start = std::clock();
	for (size_t i = 1; i < m_size; i++) {
		bool isSorted = true; // isSorted = true if a[] is sorted
		for (size_t j = 0; j < m_size - i; j++) {
			if ((*stlVector)[j] >(*stlVector)[j + 1]) { // the larger item bubbles up 
				T temp = (*stlVector)[j];   // and isSorted is set to false,
				(*stlVector)[j] = (*stlVector)[j + 1];     // i.e. the data was not sorted
				(*stlVector)[j + 1] = temp;
				isSorted = false;
			}
		}
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
double FlaggedBubbleSort<T>::SortMyArray()
{
	Array<T>* myArray = m_containers.GetMyArray();

	std::clock_t start = std::clock();
	for (size_t i = 1; i < m_size; i++) {
		bool isSorted = true; // isSorted = true if a[] is sorted
		for (size_t j = 0; j < m_size - i; j++) {
			if ((*myArray)[j] >(*myArray)[j + 1]) { // the larger item bubbles up 
				T temp = (*myArray)[j];   // and isSorted is set to false,
				(*myArray)[j] = (*myArray)[j + 1];     // i.e. the data was not sorted
				(*myArray)[j + 1] = temp;
				isSorted = false;
			}
		}
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

#endif