#ifndef SHELLSORT_H
#define SHELLSORT_H

template<class T>
class ShellSort: public ISortingAlgorithm<T>
{
public:
	ShellSort(Containers<T> &containers, size_t size) : ISortingAlgorithm(containers, size, "Shell Sort") {}
	~ShellSort() {}

	SortResults Sort() override;
	double SortCArray() override;
	double SortstlVector() override;
	double SortMyArray() override;
};

template <class T>
SortResults ShellSort<T>::Sort()
{
	double cArrayResults = SortCArray();
	double stlVectorResults = SortstlVector();
	double myArrayResults = SortMyArray();

	return SortResults(cArrayResults, stlVectorResults, myArrayResults);
}

template <class T>
double ShellSort<T>::SortCArray()
{
	T** cArray = ISortingAlgorithm<T>::m_containers.GetCArray();

	std::clock_t start = std::clock();
	int j;
	for (int h = m_size / 2; h > 0; h /= 2) {
		for (size_t i = h; i < m_size; i++) {
			T temp = *cArray[i];
			for (j = i; j >= h && temp < *cArray[j - h];
				j -= h) {
				*cArray[j] = *cArray[j - h];
			}
			*cArray[j] = temp;
		}
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
double ShellSort<T>::SortstlVector()
{
	vector<T>* stlVector = m_containers.GetStlVector();

	std::clock_t start = std::clock();
	int j;
	for (int h = m_size / 2; h > 0; h /= 2) {
		for (size_t i = h; i < m_size; i++) {
			T temp = (*stlVector)[i];
			for (j = i; j >= h && temp < (*stlVector)[j - h];
				j -= h) {
				(*stlVector)[j] = (*stlVector)[j - h];
			}
			(*stlVector)[j] = temp;
		}
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

template <class T>
double ShellSort<T>::SortMyArray()
{
	Array<T>* myArray = m_containers.GetMyArray();

	std::clock_t start = std::clock();
	int j;
	for (int h = m_size / 2; h > 0; h /= 2) {
		for (size_t i = h; i < m_size; i++) {
			T temp = (*myArray)[i];
			for (j = i; j >= h && temp < (*myArray)[j - h];
				j -= h) {
				(*myArray)[j] = (*myArray)[j - h];
			}
			(*myArray)[j] = temp;
		}
	}
	double duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	return duration;
}

#endif