#pragma once

#include <string>
#include "ISerial.h"
#include "AutoPointer.h"
#include "AutoPointerBaseType.h"

class SerialBase : ISerializer
{
public:
	SerialBase(char* pBuffer, unsigned bufferLength);
	virtual ~SerialBase() {};

	virtual void SetBuffer(char* buffer, unsigned bufferLength);

	virtual void IO(int            &io) = 0;
	virtual void IO(double         &io) = 0;
	virtual void IO(char           &io) = 0;
	virtual void IO(bool           &io) = 0;
	virtual void IO(std::string    &io) = 0;

	//arrays
	virtual void IOA(int*            io, int &len) = 0;
	virtual void IOA(double*         io, int &len) = 0;
	virtual void IOA(char*           io, int &len) = 0;
	virtual void IOA(bool*           io, int &len) = 0;
	virtual void IOA(std::string*    io, int &len) = 0;

	unsigned GetBufferPos();
	void AdvanceBufferPos(unsigned number);

	bool HasOverflowed();
	void SignalOverflow();
	
	char ArraySeperator = NULL;

protected:

	template <typename T>
	void Serialize(T &io, char* pFormat)
	{
		//max length printed = 10
		char holder[SERIAL_BUFFER_LEN];
		unsigned len = sprintf_s(holder, SERIAL_BUFFER_LEN, pFormat, io);
		if ((len + m_BufferPos) > m_BufferLength)
		{
			m_OverFlowed = true;
			return;
		}
		memcpy_s(&m_Buffer[m_BufferPos], (m_BufferLength - m_BufferPos), holder, len);
		m_BufferPos += len;
	};

	template <typename T>
	void SerializeArray(T* io, int &len)
	{
		for (int ii = 0; ii < len; ii++)
		{
			if (!m_OverFlowed)
			{
				IO(io[ii]);
				if (ii != (len - 1))
				{
					IO(ArraySeperator);
				}
			}
			else
			{
				break;
			}
		}
	};

	char* m_Buffer = nullptr;
	unsigned m_BufferLength = 0;
	unsigned m_BufferPos = 0;
	bool m_OverFlowed = false;

	SerialBase() = delete;
};

