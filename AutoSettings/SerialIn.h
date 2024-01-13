#pragma once

#include <string>
#include "Util.h"
#include "SerialBase.h"
#include "AutoPointer.h"
#include "AutoPointerBaseType.h"

class SerializerIn : public SerialBase
{
public:
	SerializerIn(char* pBuffer, unsigned bufferLength) :  SerialBase(pBuffer, bufferLength) {}
	virtual ~SerializerIn() {};

	virtual void IO(int            &io);
	virtual void IO(double         &io);
	virtual void IO(char           &io);
	virtual void IO(bool           &io);
	virtual void IO(std::string    &io);

	//arrays
	virtual void IOA(int*            io, int &len);
	virtual void IOA(double*         io, int &len);
	virtual void IOA(char*           io, int &len);
	virtual void IOA(bool*           io, int &len);
	virtual void IOA(std::string*    io, int &len);

	template <typename T>
	void ReadArray(T* io, int &len)
	{
		unsigned startPos = m_BufferPos;
		unsigned endBufferSize = m_BufferLength;
		for (int ii = 0; ii < len; ii++)
		{
			while ((startPos < m_BufferLength) && (m_Buffer[startPos] != ArraySeperator))
			{
				startPos++;
			}
			//found a delim
			m_BufferLength = (startPos);
			IO(io[ii]);

			startPos++;
			m_BufferPos = startPos;
			m_BufferLength = endBufferSize;
		}
	};

protected:
	
	SerializerIn() = delete;
};
