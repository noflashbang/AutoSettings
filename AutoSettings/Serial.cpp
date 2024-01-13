//#include "stdafx.h"
//===============================================================
void CTextFBSerializerO::IO(short &io)
{
	//max length printed = 10
	char holder[11];
	unsigned len = sprintf_s(holder, 11, "%hd", io);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], holder, len);
	m_BytesWritten += len;
}
void CTextFBSerializerO::IO(unsigned short &io)
{
	//max length printed = 10
	char holder[11];
	unsigned len = sprintf_s(holder, 11, "%hu", io);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], holder, len);
	m_BytesWritten += len;
}
void CTextFBSerializerO::IO(int &io)
{
	//max length printed = 10
	char holder[11];
	unsigned len = sprintf_s(holder, 11, "%d", io);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], holder, len);
	m_BytesWritten += len;
}
void CTextFBSerializerO::IO(unsigned int &io)
{
	//max length printed = 10
	char holder[11];
	unsigned len = sprintf_s(holder, 11, "%u", io);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], holder, len);
	m_BytesWritten += len;
}
void CTextFBSerializerO::IO(long &io)
{
	//max length printed = 10
	char holder[11];
	unsigned len = sprintf_s(holder, 11, "%ld", io);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], holder, len);
	m_BytesWritten += len;
}
void CTextFBSerializerO::IO(unsigned long &io)
{
	//max length printed = 10
	char holder[11];
	unsigned len = sprintf_s(holder, 11, "%lu", io);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], holder, len);
	m_BytesWritten += len;
}
void CTextFBSerializerO::IO(float &io)
{
	char holder[255];
	unsigned len = sprintf_s(holder, 255, "%.10f", io);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], holder, len);
	m_BytesWritten += len;
}
void CTextFBSerializerO::IO(double &io)
{
	char holder[255];
	unsigned len = sprintf_s(holder, 255, "%.10Lf", io);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], holder, len);
	m_BytesWritten += len;
}
void CTextFBSerializerO::IO(std::string &io)
{
	unsigned len = io.size();
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], io.c_str(), len);
	m_BytesWritten += len;
}
void CTextFBSerializerO::IOA(short* io, int &len)
{
	static char delim = ',';

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
			if (ii != (len - 1))
				IO(delim);
		}
	}
}
void CTextFBSerializerO::IOA(unsigned short* io, int &len)
{
	static char delim = ',';

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
			if (ii != (len - 1))
				IO(delim);
		}
	}
}
void CTextFBSerializerO::IOA(int* io, int &len)
{
	static char delim = ',';

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
			if (ii != (len - 1))
				IO(delim);
		}
	}
}
void CTextFBSerializerO::IOA(unsigned int* io, int &len)
{
	static char delim = ',';

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
			if (ii != (len - 1))
				IO(delim);
		}
	}
}
void CTextFBSerializerO::IOA(long* io, int &len)
{
	static char delim = ',';

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
			if (ii != (len - 1))
				IO(delim);
		}
	}
}
void CTextFBSerializerO::IOA(unsigned long* io, int &len)
{
	static char delim = ',';

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
			if (ii != (len - 1))
				IO(delim);
		}
	}
}
void CTextFBSerializerO::IOA(float* io, int &len)
{
	static char delim = ',';

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
			if (ii != (len - 1))
				IO(delim);
		}
	}
}
void CTextFBSerializerO::IOA(double* io, int &len)
{
	static char delim = ',';

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
			if (ii != (len - 1))
				IO(delim);
		}
	}
}
void CTextFBSerializerO::IOA(char* io, int &len)
{
	static char delim = ',';

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CTextFBSerializerO::IOA(bool* io, int &len)
{
	static char delim = ',';

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
			if (ii != (len - 1))
				IO(delim);
		}
	}
}
//=============================================================
void CTextFBSerializerI::IO(short &io)
{
	//assume that the buffer contains the whole integer
	unsigned len = m_BufferLength - m_BytesRead;
	if ((len + m_BytesRead) > m_BufferLength)
	{
		//only really happens of int rolls over
		m_OverFlowed = true;
		return;
	}
	//copies onto local buffer for safty
	AutoPointer<char> buffer(len + 1);
	memset(buffer, 0, len + 1);
	memcpy(buffer, &m_Buffer[m_BytesRead], len);

	if (&buffer[0] != '\0')
		io = atoi(buffer);
}
void CTextFBSerializerI::IO(unsigned short &io)
{
	//assume that the buffer contains the whole integer
	unsigned len = m_BufferLength - m_BytesRead;
	if ((len + m_BytesRead) > m_BufferLength)
	{
		//only really happens of int rolls over
		m_OverFlowed = true;
		return;
	}
	//copies onto local buffer for safty
	AutoPointer<char> buffer(len + 1);
	memset(buffer, 0, len + 1);
	memcpy(buffer, &m_Buffer[m_BytesRead], len);

	if (&buffer[0] != '\0')
		io = (unsigned short)strtoul(buffer, 0, 10);
}
void CTextFBSerializerI::IO(int &io)
{
	//assume that the buffer contains the whole integer
	unsigned len = m_BufferLength - m_BytesRead;
	if ((len + m_BytesRead) > m_BufferLength)
	{
		//only really happens of int rolls over
		m_OverFlowed = true;
		return;
	}
	//copies onto local buffer for safty
	AutoPointer<char> buffer(len + 1);
	memset(buffer, 0, len + 1);
	memcpy(buffer, &m_Buffer[m_BytesRead], len);

	if (&buffer[0] != '\0')
		io = atoi(buffer);
}
void CTextFBSerializerI::IO(unsigned int &io)
{
	//assume that the buffer contains the whole integer
	unsigned len = m_BufferLength - m_BytesRead;
	if ((len + m_BytesRead) > m_BufferLength)
	{
		//only really happens of int rolls over
		m_OverFlowed = true;
		return;
	}
	//copies onto local buffer for safty
	AutoPointer<char> buffer(len + 1);
	memset(buffer, 0, len + 1);
	memcpy(buffer, &m_Buffer[m_BytesRead], len);

	if (&buffer[0] != '\0')
		io = strtoul(buffer, 0, 10);
}
void CTextFBSerializerI::IO(long &io)
{
	//assume that the buffer contains the whole integer
	unsigned len = m_BufferLength - m_BytesRead;
	if ((len + m_BytesRead) > m_BufferLength)
	{
		//only really happens of int rolls over
		m_OverFlowed = true;
		return;
	}
	//copies onto local buffer for safty
	AutoPointer<char> buffer(len + 1);
	memset(buffer, 0, len + 1);
	memcpy(buffer, &m_Buffer[m_BytesRead], len);

	if (&buffer[0] != '\0')
		io = strtol(buffer, 0, 10);
}
void CTextFBSerializerI::IO(unsigned long &io)
{
	//assume that the buffer contains the whole integer
	unsigned len = m_BufferLength - m_BytesRead;
	if ((len + m_BytesRead) > m_BufferLength)
	{
		//only really happens of int rolls over
		m_OverFlowed = true;
		return;
	}
	//copies onto local buffer for safty
	AutoPointer<char> buffer(len + 1);
	memset(buffer, 0, len + 1);
	memcpy(buffer, &m_Buffer[m_BytesRead], len);

	if (&buffer[0] != '\0')
		io = strtoul(buffer, 0, 10);
}
void CTextFBSerializerI::IO(float &io)
{
	//assume that the buffer contains the whole double
	unsigned len = m_BufferLength - m_BytesRead;
	if ((len + m_BytesRead) > m_BufferLength)
	{
		//only really happens of int rolls over
		m_OverFlowed = true;
		return;
	}
	//copies onto local buffer for safty
	AutoPointer<char> buffer(len + 1);
	memset(buffer, 0, len + 1);
	memcpy(buffer, &m_Buffer[m_BytesRead], len);

	if (&buffer[0] != '\0')
		io = (float)atof(buffer);
}
void CTextFBSerializerI::IO(double &io)
{
	//assume that the buffer contains the whole double
	unsigned len = m_BufferLength - m_BytesRead;
	if ((len + m_BytesRead) > m_BufferLength)
	{
		//only really happens of int rolls over
		m_OverFlowed = true;
		return;
	}
	//copies onto local buffer for safty
	AutoPointer<char> buffer(len + 1);
	memset(buffer, 0, len + 1);
	memcpy(buffer, &m_Buffer[m_BytesRead], len);

	if (&buffer[0] != '\0')
		io = atof(buffer);
}
void CTextFBSerializerI::IO(std::string &io)
{
	//assume that the buffer contains the whole string
	unsigned len = m_BufferLength - m_BytesRead;
	if ((len + m_BytesRead) > m_BufferLength)
	{
		//only really happens of int rolls over
		m_OverFlowed = true;
		return;
	}
	//copies onto local buffer for safty
	AutoPointer<char> buffer(len + 1);
	memset(buffer, 0, len + 1);
	memcpy(buffer, &m_Buffer[m_BytesRead], len);

	io = buffer;
}
void CTextFBSerializerI::IOA(short* io, int &len)
{
	unsigned startPos = m_BytesRead;
	unsigned endBufferSize = m_BufferLength;
	for (int ii = 0; ii < len; ii++)
	{
		while ((startPos < m_BufferLength) && (m_Buffer[startPos] != ','))
		{
			startPos++;
		}

		//found a delim
		m_BufferLength = (startPos);
		IO(io[ii]);

		startPos++;
		m_BytesRead = startPos;
		m_BufferLength = endBufferSize;
	}
}
void CTextFBSerializerI::IOA(unsigned short* io, int &len)
{
	unsigned startPos = m_BytesRead;
	unsigned endBufferSize = m_BufferLength;
	for (int ii = 0; ii < len; ii++)
	{
		while ((startPos < m_BufferLength) && (m_Buffer[startPos] != ','))
		{
			startPos++;
		}

		//found a delim
		m_BufferLength = (startPos);
		IO(io[ii]);

		startPos++;
		m_BytesRead = startPos;
		m_BufferLength = endBufferSize;
	}
}
void CTextFBSerializerI::IOA(int* io, int &len)
{
	unsigned startPos = m_BytesRead;
	unsigned endBufferSize = m_BufferLength;
	for (int ii = 0; ii < len; ii++)
	{
		while ((startPos < m_BufferLength) && (m_Buffer[startPos] != ','))
		{
			startPos++;
		}

		//found a delim
		m_BufferLength = (startPos);
		IO(io[ii]);

		startPos++;
		m_BytesRead = startPos;
		m_BufferLength = endBufferSize;
	}
}
void CTextFBSerializerI::IOA(unsigned int* io, int &len)
{
	unsigned startPos = m_BytesRead;
	unsigned endBufferSize = m_BufferLength;
	for (int ii = 0; ii < len; ii++)
	{
		while ((startPos < m_BufferLength) && (m_Buffer[startPos] != ','))
		{
			startPos++;
		}

		//found a delim
		m_BufferLength = (startPos);
		IO(io[ii]);

		startPos++;
		m_BytesRead = startPos;
		m_BufferLength = endBufferSize;
	}
}
void CTextFBSerializerI::IOA(long* io, int &len)
{
	unsigned startPos = m_BytesRead;
	unsigned endBufferSize = m_BufferLength;
	for (int ii = 0; ii < len; ii++)
	{
		while ((startPos < m_BufferLength) && (m_Buffer[startPos] != ','))
		{
			startPos++;
		}

		//found a delim
		m_BufferLength = (startPos);
		IO(io[ii]);

		startPos++;
		m_BytesRead = startPos;
		m_BufferLength = endBufferSize;
	}
}
void CTextFBSerializerI::IOA(unsigned long* io, int &len)
{
	unsigned startPos = m_BytesRead;
	unsigned endBufferSize = m_BufferLength;
	for (int ii = 0; ii < len; ii++)
	{
		while ((startPos < m_BufferLength) && (m_Buffer[startPos] != ','))
		{
			startPos++;
		}

		//found a delim
		m_BufferLength = (startPos);
		IO(io[ii]);

		startPos++;
		m_BytesRead = startPos;
		m_BufferLength = endBufferSize;
	}
}
void CTextFBSerializerI::IOA(float* io, int &len)
{
	unsigned startPos = m_BytesRead;
	unsigned endBufferSize = m_BufferLength;
	for (int ii = 0; ii < len; ii++)
	{
		while ((startPos < m_BufferLength) && (m_Buffer[startPos] != ','))
		{
			startPos++;
		}

		//found a delim
		m_BufferLength = (startPos);
		IO(io[ii]);

		startPos++;
		m_BytesRead = startPos;
		m_BufferLength = endBufferSize;
	}
}
void CTextFBSerializerI::IOA(double* io, int &len)
{
	unsigned startPos = m_BytesRead;
	unsigned endBufferSize = m_BufferLength;
	for (int ii = 0; ii < len; ii++)
	{
		while ((startPos < m_BufferLength) && (m_Buffer[startPos] != ','))
		{
			startPos++;
		}

		//found a delim
		m_BufferLength = (startPos);
		IO(io[ii]);

		startPos++;
		m_BytesRead = startPos;
		m_BufferLength = endBufferSize;
	}
}
void CTextFBSerializerI::IOA(char* io, int &len)
{
	for (int ii = 0; ii < len; ii++)
	{
		IO(io[ii]);
	}
}
void CTextFBSerializerI::IOA(bool* io, int &len)
{
	unsigned startPos = m_BytesRead;
	unsigned endBufferSize = m_BufferLength;
	for (int ii = 0; ii < len; ii++)
	{
		while ((startPos < m_BufferLength) && (m_Buffer[startPos] != ','))
		{
			startPos++;
		}

		//found a delim
		m_BufferLength = (startPos);
		IO(io[ii]);

		startPos++;
		m_BytesRead = startPos;
		m_BufferLength = endBufferSize;
	}
}
//===================================================================
CBinarySerializerO::CBinarySerializerO(char* pBuffer, unsigned bufferLength)
{
	m_Buffer = pBuffer;
	m_BufferLength = bufferLength;
	m_BytesWritten = 0;
	m_OverFlowed = false;
};
void CBinarySerializerO::IO(short &io)
{
	unsigned len = sizeof(short);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], (char*)&io, len);
	m_BytesWritten += len;
}
void CBinarySerializerO::IO(unsigned short &io)
{
	unsigned len = sizeof(unsigned short);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], (char*)&io, len);
	m_BytesWritten += len;
}
void CBinarySerializerO::IO(int &io)
{
	unsigned len = sizeof(int);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], (char*)&io, len);
	m_BytesWritten += len;
}
void CBinarySerializerO::IO(unsigned int &io)
{
	unsigned len = sizeof(unsigned int);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], (char*)&io, len);
	m_BytesWritten += len;
}
void CBinarySerializerO::IO(long &io)
{
	unsigned len = sizeof(long);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], (char*)&io, len);
	m_BytesWritten += len;
}
void CBinarySerializerO::IO(unsigned long &io)
{
	unsigned len = sizeof(unsigned long);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], (char*)&io, len);
	m_BytesWritten += len;
}
void CBinarySerializerO::IO(float &io)
{
	unsigned len = sizeof(float);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], (char*)&io, len);
	m_BytesWritten += len;
}
void CBinarySerializerO::IO(double &io)
{
	unsigned len = sizeof(double);
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], (char*)&io, len);
	m_BytesWritten += len;
}
void CBinarySerializerO::IO(char &io)
{
	unsigned len = 1;
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], &io, len);
	m_BytesWritten += len;
}
void CBinarySerializerO::IO(unsigned char &io)
{
	unsigned len = 1;
	if ((len + m_BytesWritten) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&m_Buffer[m_BytesWritten], &io, len);
	m_BytesWritten += len;
}
void CBinarySerializerO::IO(bool &io)
{
	//write out T or F, why not?
	static char TrueChar = 'T';
	static char FalseChar = 'F';
	if (io)
		this->IO(TrueChar);
	else
		this->IO(FalseChar);
}
void CBinarySerializerO::IO(std::string &io)
{
	int len = io.size();
	if ((len + m_BytesWritten + sizeof(int)) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	this->IO(len);

	if (m_OverFlowed)
		return;

	memcpy(&m_Buffer[m_BytesWritten], io.c_str(), len);
	m_BytesWritten += len;
}
void CBinarySerializerO::IOA(short* io, int &len)
{
	IO(len);

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerO::IOA(unsigned short* io, int &len)
{
	IO(len);

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerO::IOA(int* io, int &len)
{
	IO(len);

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerO::IOA(unsigned int* io, int &len)
{
	IO(len);

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerO::IOA(long* io, int &len)
{
	IO(len);

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerO::IOA(unsigned long* io, int &len)
{
	IO(len);

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerO::IOA(float* io, int &len)
{
	IO(len);

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerO::IOA(double* io, int &len)
{
	IO(len);

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerO::IOA(char* io, int &len)
{
	IO(len);

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerO::IOA(bool* io, int &len)
{
	IO(len);

	for (int ii = 0; ii < len; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
unsigned CBinarySerializerO::GetBytesWritten()
{
	return m_BytesWritten;
}
bool CBinarySerializerO::HasOverflowed()
{
	if (!m_OverFlowed)
	{
		m_OverFlowed = (m_BytesWritten > m_BufferLength);
	}
	return m_OverFlowed;
}

//============================================================

CBinarySerializerI::CBinarySerializerI(char* pBuffer, unsigned bufferLength)
{
	m_Buffer = pBuffer;
	m_BufferLength = bufferLength;
	m_BytesRead = 0;
	m_OverFlowed = false;
};
void CBinarySerializerI::IO(short &io)
{
	unsigned len = sizeof(short);
	if ((len + m_BytesRead) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy((char*)&io, &m_Buffer[m_BytesRead], len);
	m_BytesRead += len;
}
void CBinarySerializerI::IO(unsigned short &io)
{
	unsigned len = sizeof(unsigned short);
	if ((len + m_BytesRead) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy((char*)&io, &m_Buffer[m_BytesRead], len);
	m_BytesRead += len;
}
void CBinarySerializerI::IO(int &io)
{
	unsigned len = sizeof(int);
	if ((len + m_BytesRead) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy((char*)&io, &m_Buffer[m_BytesRead], len);
	m_BytesRead += len;
}
void CBinarySerializerI::IO(unsigned int &io)
{
	unsigned len = sizeof(unsigned int);
	if ((len + m_BytesRead) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy((char*)&io, &m_Buffer[m_BytesRead], len);
	m_BytesRead += len;
}
void CBinarySerializerI::IO(long &io)
{
	unsigned len = sizeof(long);
	if ((len + m_BytesRead) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy((char*)&io, &m_Buffer[m_BytesRead], len);
	m_BytesRead += len;
}
void CBinarySerializerI::IO(unsigned long &io)
{
	unsigned len = sizeof(unsigned long);
	if ((len + m_BytesRead) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy((char*)&io, &m_Buffer[m_BytesRead], len);
	m_BytesRead += len;
}
void CBinarySerializerI::IO(float &io)
{
	unsigned len = sizeof(float);
	if ((len + m_BytesRead) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy((char*)&io, &m_Buffer[m_BytesRead], len);
	m_BytesRead += len;
}
void CBinarySerializerI::IO(double &io)
{
	unsigned len = sizeof(double);
	if ((len + m_BytesRead) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy((char*)&io, &m_Buffer[m_BytesRead], len);
	m_BytesRead += len;
}
void CBinarySerializerI::IO(char &io)
{
	if ((1 + m_BytesRead) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&io, &m_Buffer[m_BytesRead], 1);
	m_BytesRead += 1;
}
void CBinarySerializerI::IO(unsigned char &io)
{
	if ((1 + m_BytesRead) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&io, &m_Buffer[m_BytesRead], 1);
	m_BytesRead += 1;
}
void CBinarySerializerI::IO(bool &io)
{
	static char TrueChar = 'T';
	static char FalseChar = 'F';

	char hold;
	this->IO(hold);

	if (m_OverFlowed)
		return;

	if (hold == TrueChar)
		io = true;
	else if (hold == FalseChar)
		io = false;
}
void CBinarySerializerI::IO(std::string &io)
{
	int len = 0;
	this->IO(len);

	if ((len + m_BytesRead) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}

	if (m_OverFlowed)
		return;

	AutoPointer<char> temp(len + 1);
	temp[len] = '\0';
	memcpy(temp, &m_Buffer[m_BytesRead], len);
	m_BytesRead += len;
	io = temp;
}
void CBinarySerializerI::IOA(short* io, int &len)
{
	int lenin;
	IO(lenin);

	if (lenin > len)
	{
		m_OverFlowed = true;
		return;
	}

	for (int ii = 0; ii < lenin; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerI::IOA(unsigned short* io, int &len)
{
	int lenin;
	IO(lenin);

	if (lenin > len)
	{
		m_OverFlowed = true;
		return;
	}

	for (int ii = 0; ii < lenin; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerI::IOA(int* io, int &len)
{
	int lenin;
	IO(lenin);

	if (lenin > len)
	{
		m_OverFlowed = true;
		return;
	}

	for (int ii = 0; ii < lenin; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerI::IOA(unsigned int* io, int &len)
{
	int lenin;
	IO(lenin);

	if (lenin > len)
	{
		m_OverFlowed = true;
		return;
	}

	for (int ii = 0; ii < lenin; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerI::IOA(long* io, int &len)
{
	int lenin;
	IO(lenin);

	if (lenin > len)
	{
		m_OverFlowed = true;
		return;
	}

	for (int ii = 0; ii < lenin; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerI::IOA(unsigned long* io, int &len)
{
	int lenin;
	IO(lenin);

	if (lenin > len)
	{
		m_OverFlowed = true;
		return;
	}

	for (int ii = 0; ii < lenin; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerI::IOA(float* io, int &len)
{
	int lenin;
	IO(lenin);

	if (lenin > len)
	{
		m_OverFlowed = true;
		return;
	}

	for (int ii = 0; ii < lenin; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerI::IOA(double* io, int &len)
{
	int lenin;
	IO(lenin);

	if (lenin > len)
	{
		m_OverFlowed = true;
		return;
	}

	for (int ii = 0; ii < lenin; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerI::IOA(char* io, int &len)
{
	int lenin;
	IO(lenin);

	if (lenin > len)
	{
		m_OverFlowed = true;
		return;
	}

	for (int ii = 0; ii < lenin; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
void CBinarySerializerI::IOA(bool* io, int &len)
{
	int lenin;
	IO(lenin);

	if (lenin > len)
	{
		m_OverFlowed = true;
		return;
	}

	for (int ii = 0; ii < lenin; ii++)
	{
		if (!m_OverFlowed)
		{
			IO(io[ii]);
		}
	}
}
unsigned CBinarySerializerI::GetBytesRead()
{
	return m_BytesRead;
}
bool CBinarySerializerI::HasOverflowed()
{
	if (!m_OverFlowed)
	{
		m_OverFlowed = (m_BytesRead > m_BufferLength);
	}
	return m_OverFlowed;
}
//===============================================================