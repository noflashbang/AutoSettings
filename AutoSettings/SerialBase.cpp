#include "SerialBase.h"

SerialBase::SerialBase(char* buffer, unsigned bufferLen)
{
	if (ArraySeperator == NULL)
	{
		ArraySeperator = DEFAULT_ARRAY_SEPERATOR;
	}
	m_BufferPos = 0;
	m_OverFlowed = false;
	SetBuffer(buffer, bufferLen);
}

unsigned SerialBase::GetBufferPos()
{
	return m_BufferPos;
}

bool SerialBase::HasOverflowed()
{
	return m_OverFlowed;
}

void SerialBase::SetBuffer(char* buffer, unsigned bufferLength)
{
	m_Buffer = buffer;
	m_BufferLength = bufferLength;
}

void SerialBase::AdvanceBufferPos(unsigned number)
{
	m_BufferPos += number;
}

void SerialBase::SignalOverflow()
{
	m_OverFlowed = true;
}