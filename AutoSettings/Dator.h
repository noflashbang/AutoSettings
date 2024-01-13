#pragma once

#include <String>
#include "IDator.h"
#include "SerialOut.h"
#include "SerialIn.h"

//T = type, I = input serializer, O = output serializer
template <class T, class I = SerializerIn, class O = SerializerOut>
class Dator : public IDator
{
public:
	Dator<T, I, O>(T& value) : m_Value(value) {};
	~Dator<T, I, O>() {};

	std::string GetValue()
	{
		std::string buffer;
		O out(buffer);
		out.IO(m_Value);
		return buffer;
	};
	void SetValue(std::string iVal)
	{
		I in(iVal);
		in.IO(m_Value);
	};

protected:
	Dator<T, I, O>() {};
private:
	T& m_Value;
};


