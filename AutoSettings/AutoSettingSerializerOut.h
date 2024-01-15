#pragma once

#include "StandardLib.h"
#include "Util.h"
#include "SerialOut.h"
#include "AutoSettingEntry.h"
#include "AutoSettingGroup.h"

class AutoSettingSerializerOut : public SerializerOut
{
public:
	AutoSettingSerializerOut(std::string* data) :SerializerOut(data) {};
	virtual ~AutoSettingSerializerOut() {};

	virtual bool IO(AutoSettingEntry& io);
	virtual bool IO(AutoSettingGroup& io);

protected:
	AutoSettingSerializerOut() = delete;
	AutoSettingSerializerOut(const AutoSettingSerializerOut& other) = delete;
	AutoSettingSerializerOut& operator=(const AutoSettingSerializerOut& other) = delete;

};

