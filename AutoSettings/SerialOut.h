#pragma once

#include <string>
#include <vector>

#include "SerialBase.h"
#include "AutoPointer.h"
#include "AutoPointerBaseType.h"


class SerializerOut : public SerialBase
{
public:
	SerializerOut(std::string data) : SerialBase(data) {}
	virtual ~SerializerOut() {};

	virtual void IO(int            &io);
	virtual void IO(double         &io);
	virtual void IO(bool           &io);
	virtual void IO(std::string    &io);

	//arrays
	virtual void IOA(std::vector<int> &io);
	virtual void IOA(std::vector<double> &io);
	virtual void IOA(std::vector<bool> &io);
	virtual void IOA(std::vector<std::string> &io);

protected:

	SerializerOut() = delete;
};
