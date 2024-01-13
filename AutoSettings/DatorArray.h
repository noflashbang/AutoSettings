#pragma once

#include "IDator.h"
#include "DatorConstants.h"
#include "SerialIn.h"
#include "SerialOut.h"

template <class T, class I = SerializerIn, class O = SerializerOut>
class DatorArray : public IDator
{
public:
	DatorArray<T, I, O>(T*& value, int numElements) : m_Value(value), m_NumElements(numElements)
	{
	};
	~DatorArray<T, I, O>()
	{
	};

	std::string GetValue()
	{
		static char buffer[DATOR_ARRAY_BUFFER_LEN];
		memset(buffer, 0, DATOR_ARRAY_BUFFER_LEN);

		O out(buffer, DATOR_ARRAY_BUFFER_LEN);
		out.IOA(m_Value, m_NumElements);
		std::string ret = buffer;
		return ret;
	};
	void SetValue(std::string iVal)
	{
		static char buffer[DATOR_ARRAY_BUFFER_LEN];
		memset(buffer, 0, DATOR_ARRAY_BUFFER_LEN);
		memcpy(buffer, iVal.c_str(), iVal.length());
		I in(buffer, DATOR_ARRAY_BUFFER_LEN);
		in.IOA(m_Value, m_NumElements);
	};

protected:
private:
	T*& m_Value;
	int m_NumElements;
};
