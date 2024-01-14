#include "SerialIn.h"

void SerializerIn::IO(int &io)
{
	io = stoi(*m_Data);
}

void SerializerIn::IO(double &io)
{
	io = stod(*m_Data);
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
	io = *m_Data;
}

void SerializerIn::IOA(std::vector<int>& io)
{
	ReadArray<int, SerializerIn>(io);
}

void SerializerIn::IOA(std::vector<double>& io)
{
	ReadArray<double, SerializerIn>(io);
}

void SerializerIn::IOA(std::vector<bool> &io)
{
	ReadArray<bool, SerializerIn>(io);
}

void SerializerIn::IOA(std::vector<std::string> &io)
{
	ReadArray<std::string, SerializerIn>(io);
}
