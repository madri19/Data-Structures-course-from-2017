#define _CRT_SECURE_NO_WARNINGS

#include "Exception.h"
#include <string.h>

Exception::Exception()
{
	strcpy(m_msg, "Exception Error: ");
}

Exception::Exception(char * msg)
{
	strcpy(m_msg, msg);
}

Exception::Exception(const Exception & copy)
{
	strcpy(m_msg, copy.getMessage());
}

Exception::~Exception() {}

Exception& Exception::operator=(const Exception & rsh)
{
	strcpy(m_msg, rsh.getMessage());
	return *this;
}

const char * Exception::getMessage() const
{
	return m_msg;
}

void Exception::setMessage(char * msg)
{
	strcpy(m_msg, msg);
}

ostream& operator<<(ostream & stream, const Exception & except)
{
	stream << except.getMessage();
	return stream;
}