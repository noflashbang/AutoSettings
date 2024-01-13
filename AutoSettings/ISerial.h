#pragma once

#include <string>

#define SERIAL_BUFFER_LEN 20
#define DEFAULT_ARRAY_SEPERATOR ','

class ISerializer
{
public:
	virtual ~ISerializer() {};

	virtual void SetBuffer(char* buffer, unsigned bufferLen) = 0;

	virtual void IO(int            &io) = 0;
	virtual void IO(double         &io) = 0;
	virtual void IO(char           &io) = 0;
	virtual void IO(bool           &io) = 0;
	virtual void IO(std::string    &io) = 0;

	//arrays
	virtual void IOA(int*            io, int &len) = 0;
	virtual void IOA(double*         io, int &len) = 0;
	virtual void IOA(char*           io, int &len) = 0;
	virtual void IOA(bool*           io, int &len) = 0;
	virtual void IOA(std::string*    io, int &len) = 0;
};

