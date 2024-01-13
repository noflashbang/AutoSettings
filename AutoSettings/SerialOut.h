#pragma once

#include <string>
#include "SerialBase.h"
#include "AutoPointer.h"
#include "AutoPointerBaseType.h"


class SerializerOut : public SerialBase
{
public:
	SerializerOut(char* pBuffer, unsigned bufferLength) : SerialBase(pBuffer, bufferLength) {}
	virtual ~SerializerOut() {};

	virtual void IO(int            &io);
	virtual void IO(double         &io);
	virtual void IO(char           &io);
	virtual void IO(bool           &io);
	virtual void IO(std::string    &io);

	//arrays
	virtual void IOA(int*            io, int &len);
	virtual void IOA(double*         io, int &len);
	virtual void IOA(char*           io, int &len);
	virtual void IOA(bool*           io, int &len);
	virtual void IOA(std::string*    io, int &len);

protected:

	SerializerOut() = delete;
};
