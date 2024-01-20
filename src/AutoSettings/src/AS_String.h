#pragma once

#include "StandardLib.h"
#include "Util.h"

class AS_String
{
	public:
	AS_String();
	~AS_String();

	AS_String(const AS_String& other);
	AS_String& operator=(const AS_String& other);
	AS_String(AS_String&& other);
	AS_String& operator=(AS_String&& other);

	//equality
	bool operator==(const AS_String& other) const;

	//build from string
	AS_String(const std::string& str);
	AS_String& operator=(const std::string& other);
	AS_String(std::string&& other);
	AS_String& operator=(std::string&& other);

	//implicit conversion to string
	operator std::string() const;

private:
	std::string m_String;
};