#pragma once

#include <string>
#include <vector>

#define SERIAL_BUFFER_LEN 20
#define DEFAULT_ARRAY_SEPERATOR ","

class ISerializer
{
public:
	virtual ~ISerializer() {};

	virtual void IO(int            &io) = 0;
	virtual void IO(double         &io) = 0;
	virtual void IO(bool           &io) = 0;
	virtual void IO(std::string    &io) = 0;

	//arrays
	virtual void IOA(std::vector<int> &io) = 0;
	virtual void IOA(std::vector<double> &io) = 0;
	virtual void IOA(std::vector<bool> &io) = 0;
	virtual void IOA(std::vector<std::string> &io) = 0;
};

