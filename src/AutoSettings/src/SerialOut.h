#pragma once

#include "StandardLib.h"
#include "SerialBase.h"

class SerializerOut : public SerialBase
{
public:
	SerializerOut(std::string* data) : SerialBase(data) {}
	virtual ~SerializerOut() {};

	virtual void IO(int            &io);
	virtual void IO(double         &io);
	virtual void IO(bool           &io);
	virtual void IO(std::string    &io);

	//arrays
	virtual void IO(std::vector<int> &io);
	virtual void IO(std::vector<double> &io);
	virtual void IO(std::vector<bool> &io);
	virtual void IO(std::vector<std::string> &io);

protected:

	SerializerOut() = delete;
	SerializerOut(const SerializerOut&) = delete;
	SerializerOut& operator=(const SerializerOut&) = delete;
};
