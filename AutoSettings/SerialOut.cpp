#include "SerialOut.h"

void SerializerOut::IO(int &io)
{
	Serialize(io, "%d");
}

void SerializerOut::IO(double &io)
{
	Serialize(io, "%.10Lf");
}
void SerializerOut::IO(char &io)
{
	Serialize(io, "%c");
}
void SerializerOut::IO(bool &io)
{
	static std::string TrueString = "True";
	static std::string FalseString = "False";
	if (io)
		this->IO(TrueString);
	else
		this->IO(FalseString);
}
void SerializerOut::IO(std::string &io)
{
	unsigned len = io.size();
	if ((len + m_BufferPos) > m_BufferLength)
	{
		m_OverFlowed = true;
		return;
	}
	memcpy_s(&m_Buffer[m_BufferPos], (m_BufferLength - m_BufferPos), io.c_str(), len);
	m_BufferPos += len;
}

void SerializerOut::IOA(int* io, int &len)
{
	SerializeArray(io, len);
}
void SerializerOut::IOA(double* io, int &len)
{
	SerializeArray(io, len);
}
void SerializerOut::IOA(char* io, int &len)
{
	SerializeArray(io, len);
}
void SerializerOut::IOA(bool* io, int &len)
{
	SerializeArray(io, len);
}
void SerializerOut::IOA(std::string* io, int &len)
{
	SerializeArray(io, len);
}

