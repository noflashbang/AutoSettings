#pragma once

#include "IDator.h"
#include "DatorConstants.h"
#include "SerialIn.h"
#include "SerialOut.h"

template <class T, class I = SerializerIn, class O = SerializerOut>
class DatorArray : public IDator
{
public:
	DatorArray<T, I, O>(std::vector<T> value) : m_Value(value)
	{
	};
	~DatorArray<T, I, O>()
	{
	};

	std::string GetValue()
	{
		std::string buffer;
		O out(&buffer);
		out.IOA(m_Value);
		return buffer;
	};
	void SetValue(std::string iVal)
	{
		I in(&iVal);
		in.IOA(m_Value);
	};

protected:
private:
	std::vector<T> m_Value;
};
