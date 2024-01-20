#include "AS_String.h"

AS_String::AS_String()
{
}

AS_String::~AS_String()
{
}

AS_String::AS_String(const AS_String& other)
{
	m_String = other.m_String;
}

AS_String& AS_String::operator=(const AS_String& other)
{
	if (this != &other)
	{
		m_String = other.m_String;
	}
	return (*this);
}

AS_String::AS_String(AS_String&& other)
{
	m_String = std::move(other.m_String);
}

AS_String& AS_String::operator=(AS_String&& other)
{
	if (this != &other)
	{
		m_String = std::move(other.m_String);
	}
	return (*this);
}

bool AS_String::operator==(const AS_String& other) const
{
	return (m_String == other.m_String);
}

AS_String::AS_String(const std::string& str)
{
	m_String = str;
	m_String = Util::StringToUpper(m_String);
	Util::StringTrim(m_String);
}

AS_String& AS_String::operator=(const std::string& other)
{
	m_String = other;
	m_String = Util::StringToUpper(m_String);
	Util::StringTrim(m_String);
	return (*this);
}

AS_String::AS_String(std::string&& other)
{
	m_String = std::move(other);
	m_String = Util::StringToUpper(m_String);
	Util::StringTrim(m_String);
}

AS_String& AS_String::operator=(std::string&& other)
{
	m_String = std::move(other);
	m_String = Util::StringToUpper(m_String);
	Util::StringTrim(m_String);
	return (*this);
}

AS_String::operator std::string() const
{
	return m_String;
}
