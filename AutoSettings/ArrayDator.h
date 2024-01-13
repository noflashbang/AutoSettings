#pragma once

#include "SerialBase.h"
#include "SerialIn.h"
#include "SerialOut.h"

//T = type, I = input serializer, O = output serializer
template <class T, class I = SerializerIn, class O = SerializerOut>
class ArrayDator : public IDator
{
public:
	ArrayDator<T, I, O>(T*& value, int numElements) : m_Value(value), m_NumElements(numElements)
	{
	};
	~ArrayDator<T, I, O>()
	{
	};

	std::string GetValue()
	{
		char buffer[ARRAY_BUFFER_LEN];
		memset(buffer, 0, ARRAY_BUFFER_LEN);

		O out(buffer, ARRAY_BUFFER_LEN);
		out.IOA(m_Value, m_NumElements);
		std::string ret = buffer;
		return ret;
	};
	void SetValue(std::string iVal)
	{
		char buffer[ARRAY_BUFFER_LEN];
		memset(buffer, 0, ARRAY_BUFFER_LEN);
		memcpy(buffer, iVal.c_str(), iVal.length());
		I in(buffer, ARRAY_BUFFER_LEN);
		in.IOA(m_Value, m_NumElements);
	};

protected:
private:
	T*& m_Value;
	int m_NumElements;
};

