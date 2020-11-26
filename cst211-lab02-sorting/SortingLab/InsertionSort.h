#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

template<class T>
class InsertionSort : public ISortingAlgorithm<T>
{
public:
	InsertionSort(Containers<T> &containers, size_t size) : ISortingAlgorithm(containers, size, "Insertion Sort") {}
	~InsertionSort() {}

	SortResults Sort() override;
	double SortCArray() override;
	double SortstlVector() override;
	double SortMyArray() override;
};

template <class T>
SortResults InsertionSort<T>::Sort()
{
	double cArrayResults = SortCArray();
	double stlVectorResults = SortstlVector();
	double myArrayResults = SortMyArray();

	return SortResults(cArrayResults, stlVectorResults, myArrayResults);
}

template <class T>
double InsertionSort<T>::SortCArray()
{
	T** cArray = m_containers.GetCArray();

	std::clock_t start = std::clock();
	for (size_t i = 1; i < m_size; i++) {
		int next = *cArray[i];
		int j;

		for (j = i - 1; j >= 0 && *cArray[j] > next; j--) {
			*cArray[j + 1] = *cArray[j];
		}

		*cArray[j + 1] = next;
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
double InsertionSort<T>::SortstlVector()
{
	vector<T>* stlVector = m_containers.GetStlVector();

	std::clock_t start = std::clock();
	for (size_t i = 1; i < m_size; i++) {
		int next = (*stlVector)[i];
		int j;

		for (j = i - 1; j >= 0 && (*stlVector)[j] > next; j--) {
			(*stlVector)[j + 1] = (*stlVector)[j];
		}
		(*stlVector)[j + 1] = next;
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
double InsertionSort<T>::SortMyArray()
{
	Array<T>* myArray = m_containers.GetMyArray();

	std::clock_t start = std::clock();
	for (size_t i = 1; i < m_size; i++) {
		int next = (*myArray)[i];
		int j;

		for (j = i - 1; j >= 0 && (*myArray)[j] > next; j--) {
			(*myArray)[j + 1] = (*myArray)[j];
		}
		(*myArray)[j + 1] = next;
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

#endif