#pragma once

#include "StandardLib.h"
#include "Util.h"
#include "SerialIn.h"
#include "AutoSettingEntry.h"
#include "AutoSettingGroup.h"

class AutoSettingSerializerIn : public SerializerIn
{
public:
	AutoSettingSerializerIn(std::string* data) :SerializerIn(data) {};
	virtual ~AutoSettingSerializerIn() {};

	virtual bool IO(AutoSettingEntry& io);
	virtual bool IO(AutoSettingGroup& io);

protected:
	AutoSettingSerializerIn() = delete;
	AutoSettingSerializerIn(const AutoSettingSerializerIn& other) = delete;
	AutoSettingSerializerIn& operator=(const AutoSettingSerializerIn& other) = delete;
};

