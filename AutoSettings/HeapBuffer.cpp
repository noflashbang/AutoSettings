#include "HeapBuffer.h"

HeapBuffer::HeapBuffer(unsigned bufferLength)
{
	m_BufferLength = bufferLength;
	m_Buffer = new char[m_BufferLength];
}

HeapBuffer::~HeapBuffer()
{
	delete[] m_Buffer;
}

unsigned HeapBuffer::GetBufferPos()
{
	return m_BufferPos;
}

void HeapBuffer::AdvanceBufferPos(unsigned advAmount)
{
	m_BufferPos += advAmount;
}

bool HeapBuffer::HasOverflowed()
{
	if (m_BufferPos >= m_BufferLength)
	{
		SignalOverflow();
	}
	return m_OverFlowed;
}

char* HeapBuffer::GetBufferPosPtr()
{
	if (m_BufferPos >= m_BufferLength)
	{
		SignalOverflow();
		return nullptr;
	}
	return &m_Buffer[m_BufferPos];
}

void HeapBuffer::SignalOverflow()
{
	m_OverFlowed = true;
}

bool HeapBuffer::CheckRead(unsigned readAmount)
{
	if ((m_BufferPos + readAmount) > m_BufferLength)
	{
		SignalOverflow();
		return false;
	}
	return true;
}

bool HeapBuffer::CheckWrite(unsigned writeAmount)
{
	if ((m_BufferPos + writeAmount) > m_BufferLength)
	{
		SignalOverflow();
		return false;
	}
	return true;
}

