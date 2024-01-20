#pragma once

#include "StandardLib.h"
#include "AS_String.h"
#include "IDator.h"

class AutoSettingEntry //Holds the Key and Value information for an ini entry
{
public:
	AutoSettingEntry() = default;
	AutoSettingEntry(const AS_String& key, const std::shared_ptr<IDator> pDator);
	~AutoSettingEntry();

	AutoSettingEntry(const AutoSettingEntry& other);
	AutoSettingEntry& operator=(const AutoSettingEntry& other);

	void SetKey(const AS_String& key);
	void SetValue(const std::shared_ptr<IDator> pDator);
	void SetValue(const std::string& value);

	AS_String GetKey();
	std::string GetValue();

	void Update();

private:
	AS_String m_Key;
	std::string m_Value;
	std::weak_ptr<IDator> m_pDator; //used in update on save
};

