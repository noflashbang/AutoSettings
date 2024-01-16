#include "SerialOut.h"

void SerializerOut::IO(int &io)
{
	Serialize(io);
}

void SerializerOut::IO(double &io)
{
	Serialize(io);
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
	m_Data->append(io);
}

void SerializerOut::IO(std::vector<int>& io)
{
	SerializeArray(io);
}

void SerializerOut::IO(std::vector<double>& io)
{
	SerializeArray(io);
}

void SerializerOut::IO(std::vector<bool>& io)
{
	SerializeArray(io);
}

void SerializerOut::IO(std::vector<std::string>& io)
{
	SerializeArray(io);
}



