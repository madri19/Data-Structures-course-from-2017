#ifndef ISORTINGALGORITHM_H
#define ISORTINGALGORITHM_H
#include "Containers.h"
#include "SortResults.h"

template<class T>
class ISortingAlgorithm
{
public:
	virtual ~ISortingAlgorithm(){}
	virtual SortResults Sort() = 0;
	std::string getName() const;
protected:
	virtual double SortCArray() = 0;
	virtual double SortstlVector() = 0;
	virtual double SortMyArray() = 0;
	std::string m_name;
	size_t m_size;
	Containers<T> &m_containers;
	ISortingAlgorithm(Containers<T> &m_containers, size_t size, std::string name);
};

template <class T>
std::string ISortingAlgorithm<T>::getName() const
{
	return m_name;
}

template <class T>
ISortingAlgorithm<T>::ISortingAlgorithm(Containers<T>& containers, size_t size, std::string name)
: m_name(name), m_size(size), m_containers(containers){}

#endif