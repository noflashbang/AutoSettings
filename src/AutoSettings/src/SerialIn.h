#pragma once

#include "StandardLib.h"
#include "Util.h"
#include "SerialBase.h"


class SerializerIn : public SerialBase
{
public:
	SerializerIn(std::string* data) :  SerialBase(data) {}
	virtual ~SerializerIn() {};

	virtual void IO(int            &io);
	virtual void IO(double         &io);
	virtual void IO(bool           &io);
	virtual void IO(std::string    &io);
	virtual void IO(std::vector<int> &io);
	virtual void IO(std::vector<double> &io);
	virtual void IO(std::vector<bool> &io);
	virtual void IO(std::vector<std::string> &io);

	

protected:
	
	SerializerIn() = delete;
	SerializerIn(const SerializerIn&) = delete;
	SerializerIn& operator=(const SerializerIn&) = delete;
};
