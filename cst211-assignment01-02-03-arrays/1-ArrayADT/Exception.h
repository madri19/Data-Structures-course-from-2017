#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <iostream>
using namespace std;

class Exception
{
public:
	Exception();
	explicit Exception(char * msg);
	Exception(const Exception & copy);
	~Exception();
	Exception& operator=(const Exception & rsh);
	const char * getMessage() const;
	void setMessage(char * msg);
	friend ostream& operator<<(ostream & stream, const Exception & except);
private:
	char m_msg[200];
};

#endif