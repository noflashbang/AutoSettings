#pragma once

#include <String>
#include "DatorConstants.h"

class IDator
{
public:
	virtual std::string GetValue() = 0;
	virtual void SetValue(std::string iVal) = 0;
	virtual ~IDator() {};
};
