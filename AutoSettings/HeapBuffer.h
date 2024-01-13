#pragma once

class HeapBuffer
{
public:

	HeapBuffer(unsigned bufferLength);
	~HeapBuffer();

	unsigned GetBufferPos();
	void AdvanceBufferPos(unsigned advAmount);
	bool HasOverflowed();
	
	unsigned GetBufferLength() { return m_BufferLength; }
	unsigned GetBufferRemaining() { return HasOverflowed() ? 0 : m_BufferLength - m_BufferPos; }

	char* GetBuffer() { return m_Buffer; }
	char* GetBufferPosPtr();
	
	bool CheckRead(unsigned readAmount);
	bool CheckWrite(unsigned writeAmount);

private:

	void SignalOverflow();

	char* m_Buffer = nullptr;
	unsigned m_BufferLength = 0;
	unsigned m_BufferPos = 0;
	bool m_OverFlowed = false;
};