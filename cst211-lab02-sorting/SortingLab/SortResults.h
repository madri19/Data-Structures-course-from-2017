#ifndef SORTRESULTS_H
#define SORTRESULTS_H

#include <ostream>
#include <iomanip>
#include <string>

class SortResults
{
public:
	SortResults(double cArraySortTime, double stlVectorSortTime, double myArraySortTime);
	double getCArraySortTime() const;
	double getSltVectorSortTime() const;
	double getMyArraySortTime() const;
	std::string getSortType() const;
	void setSortType(std::string name);
private:
	double m_cArraySortTime = 0;
	double m_stlVectorSortTime = 0;
	double m_myArraySortTime = 0;
	std::string m_name;
	friend std::ostream& operator<<(std::ostream& stream, const SortResults& results);
};

inline std::ostream& operator<<(std::ostream& stream, const SortResults& results)
{
	stream << results.getSortType() << " C Array," << results.getCArraySortTime() << "\n";
	stream << results.getSortType() << " STL Vector," << results.getSltVectorSortTime() << "\n";
	stream << results.getSortType() << " MyArray," << results.getMyArraySortTime() << "\n";

	return stream;
}

inline SortResults::SortResults(double cArraySortTime, double stlVectorSortTime, double myArraySortTime)
	: m_cArraySortTime(cArraySortTime), m_stlVectorSortTime(stlVectorSortTime), m_myArraySortTime(myArraySortTime){}

inline double SortResults::getCArraySortTime() const
{
	return m_cArraySortTime;
}

inline double SortResults::getSltVectorSortTime() const
{
	return m_stlVectorSortTime;
}

inline double SortResults::getMyArraySortTime() const
{
	return m_myArraySortTime;
}

inline std::string SortResults::getSortType() const
{
	return m_name;
}

inline void SortResults::setSortType(std::string name)
{
	m_name = name;
}

#endif
