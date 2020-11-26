#ifndef ABSTRACTITERATOR_H
#define ABSTRACTITERATOR_H

template<class T>
class AbstractIterator
{
public:
	virtual ~AbstractIterator() = default;
	virtual void MoveNext() = 0;
	virtual void Reset() = 0;
	virtual bool IsDone() const = 0;
	virtual const T& GetCurrent() const = 0;
};

#endif