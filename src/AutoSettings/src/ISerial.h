#pragma once

#include "StandardLib.h"

#define DEFAULT_ARRAY_SEPERATOR ","

class ISerializer
{
public:
	virtual ~ISerializer() {};

	virtual void IO(int            &io) = 0;
	virtual void IO(double         &io) = 0;
	virtual void IO(bool           &io) = 0;
	virtual void IO(std::string    &io) = 0;
	virtual void IO(std::vector<int> &io) = 0;
	virtual void IO(std::vector<double> &io) = 0;
	virtual void IO(std::vector<bool> &io) = 0;
	virtual void IO(std::vector<std::string> &io) = 0;
};

