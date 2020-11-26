#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

template<class T>
class SelectionSort: public ISortingAlgorithm<T>
{
public:
	SelectionSort(Containers<T> &containers, size_t size) : ISortingAlgorithm(containers, size, "Selection Sort") {}
	~SelectionSort() {}

	SortResults Sort() override;
	double SortCArray() override;
	double SortstlVector() override;
	double SortMyArray() override;
};

template <class T>
SortResults SelectionSort<T>::Sort()
{
	double cArrayResults = SortCArray();
	double stlVectorResults = SortstlVector();
	double myArrayResults = SortMyArray();

	return SortResults(cArrayResults, stlVectorResults, myArrayResults);
}

template <class T>
double SelectionSort<T>::SortCArray()
{
	T** cArray = m_containers.GetCArray();

	std::clock_t start = std::clock();
	for (size_t i = m_size - 1; i >= 1; i--) {
		size_t index = i;
		for (size_t j = 0; j < i; j++) {
			if (*cArray[j] > *cArray[index])
				index = j;
		}
		T temp = *cArray[index];
		*cArray[index] = *cArray[i];
		*cArray[i] = temp;
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
double SelectionSort<T>::SortstlVector()
{
	vector<T>* stlVector = m_containers.GetStlVector();

	std::clock_t start = std::clock();
	for (size_t i = m_size - 1; i >= 1; i--) {
		size_t index = i;
		for (size_t j = 0; j < i; j++) {
			if ((*stlVector)[j] >(*stlVector)[index])
				index = j;
		}
		T temp = (*stlVector)[index];
		(*stlVector)[index] = (*stlVector)[i];
		(*stlVector)[i] = temp;
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
double SelectionSort<T>::SortMyArray()
{
	Array<T>* myArray = m_containers.GetMyArray();

	std::clock_t start = std::clock();
	for (size_t i = m_size - 1; i >= 1; i--) {
		size_t index = i;
		for (size_t j = 0; j < i; j++) {
			if ((*myArray)[j] >(*myArray)[index])
				index = j;
		}
		T temp = (*myArray)[index];
		(*myArray)[index] = (*myArray)[i];
		(*myArray)[i] = temp;
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

#endif