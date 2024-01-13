#include "SerialIn.h"

void SerializerIn::IO(int &io)
{
	//assume that the buffer contains the whole integer
	unsigned len = m_BufferLength - m_BufferPos;
	if ((len + m_BufferPos) > m_BufferLength)
	{
		//only really happens if int rolls over
		SignalOverflow();
		return;
	}
	char* temp = &m_Buffer[m_BufferPos];

	//check for a null term
	if (m_Buffer[len] != '\0')
	{
		char* temp = new char[len + 1];
		memset(temp, 0, len + 1);
		memcpy(temp, &m_Buffer[m_BufferPos], len);
	}

	io = atoi(temp);

	//clean up if we allocated
	if (temp != &m_Buffer[m_BufferPos])
	{
		delete temp;
	}	
}

void SerializerIn::IO(double &io)
{
	//assume that the buffer contains the whole integer
	unsigned len = m_BufferLength - m_BufferPos;
	if ((len + m_BufferPos) > m_BufferLength)
	{
		//only really happens if int rolls over
		SignalOverflow();
		return;
	}
	char* temp = &m_Buffer[m_BufferPos];

	//check for a null term
	if (m_Buffer[len] != '\0')
	{
		char* temp = new char[len + 1];
		memset(temp, 0, len + 1);
		memcpy(temp, &m_Buffer[m_BufferPos], len);
	}

	io = atof(temp);

	//clean up if we allocated
	if (temp != &m_Buffer[m_BufferPos])
	{
		delete temp;
	}
}
void SerializerIn::IO(char &io)
{
	if ((1 + m_BufferPos) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy(&io, &m_Buffer[m_BufferPos], 1);
	m_BufferPos += 1;
}

void SerializerIn::IO(bool &io)
{
	static std::string TrueString = "TRUE";

	std::string hold;
	this->IO(hold);

	hold = Util::StringToUpper(hold);

	if ((strcmp(hold.c_str(), TrueString.c_str())) == 0)
	{
		io = true;
	}
	else
	{
		io = false;
	}
}
void SerializerIn::IO(std::string &io)
{
	//assume that the buffer contains the whole integer
	unsigned len = m_BufferLength - m_BufferPos;
	if ((len + m_BufferPos) > m_BufferLength)
	{
		//only really happens if int rolls over
		SignalOverflow();
		return;
	}
	char* temp = new char[len + 1];
	memset(temp, 0, len + 1);
	memcpy(temp, &m_Buffer[m_BufferPos], len);

	io = temp;
	
	delete [] temp;
}

void SerializerIn::IOA(int* io, int &len)
{
	ReadArray(io, len);
}

void SerializerIn::IOA(double* io, int &len)
{
	ReadArray(io, len);
}
void SerializerIn::IOA(char* io, int &len)
{
	ReadArray(io, len);
}
void SerializerIn::IOA(bool* io, int &len)
{
	ReadArray(io, len);
}

void SerializerIn::IOA(std::string* io, int &len)
{
	ReadArray(io, len);
}
