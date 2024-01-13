#pragma once

#include <string>
#include "Util.h"
#include "SerialBase.h"
#include "AutoPointer.h"
#include "AutoPointerBaseType.h"

class SerializerIn : public SerialBase
{
public:
	SerializerIn(std::string data) :  SerialBase(data) {}
	virtual ~SerializerIn() {};

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
	
	SerializerIn() = delete;
};
