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
		static char buffer[DATOR_BUFFER_LEN];
		memset(buffer, 0, DATOR_BUFFER_LEN);

		O out(buffer, DATOR_BUFFER_LEN);
		out.IO(m_Value);
		std::string ret = buffer;
		return ret;
	};
	void SetValue(std::string iVal)
	{
		static char buffer[DATOR_BUFFER_LEN];
		memset(buffer, 0, DATOR_BUFFER_LEN);
		memcpy(buffer, iVal.c_str(), iVal.length());
		I in(buffer, DATOR_BUFFER_LEN);
		in.IO(m_Value);
	};

protected:
	Dator<T, I, O>() {};
private:
	T& m_Value;
};


