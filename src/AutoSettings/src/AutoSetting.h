#pragma once

#include "StandardLib.h"

#include "AS_String.h"
#include "Dator.h"
#include "SerialIn.h"
#include "SerialOut.h"
#include "AutoSettingEntry.h"
#include "AutoSettingGroup.h"
#include "AutoSettingSerializerIn.h"
#include "AutoSettingSerializerOut.h"

class AutoSetting
{
public:
	AutoSetting()
	{
	};

	AutoSetting(const std::string& iniContent)
	{
		LoadSettings(iniContent);
	};

	~AutoSetting()
	{
	};

	template<typename T>
	std::shared_ptr<IDator> CreateDator(T& data)
	{
		return std::make_shared<Dator<T>>(data);
	}

	//sets a value -> if not found it will be added, if found the ini value will be updated
	void SetSetting(const AS_String& group, const AS_String& key, const std::shared_ptr<IDator> pDator);

	//retrives a value -> if not found it will be added, if found the dator value will be updated
	void GetSetting(const AS_String& group, const AS_String& key, const std::shared_ptr<IDator> pDator);

	//retrives a value -> if not found it will not be added, if found the dator value will be updated (true on found)
	bool FindSetting(const AS_String& group, const AS_String& key, const std::shared_ptr<IDator> pDator);

	void DeleteSetting(const AS_String& group, const AS_String& key);

	void DeleteGroup(const AS_String& group);

	void LoadSettings(const std::string& iniContent);

	std::string GetIniContents();

	template<typename T>
	void SetSetting(const AS_String& group, const AS_String& key, T& data)
	{
		std::shared_ptr<IDator> typeDator = std::make_shared<Dator<T>>(data);
		SetSettingInternal(group, key, &typeDator);
	};

	template<typename T>
	void GetSetting(const AS_String& group, const AS_String& key, T& data)
	{
		std::shared_ptr<IDator> typeDator = std::make_shared<Dator<T>>(data);
		GetSettingInternal(group, key, &typeDator);
	};

	template<typename T>
	bool FindSetting(const AS_String& group, const AS_String& key, T& data)
	{
		std::shared_ptr<IDator> typeDator = std::make_shared<Dator<T>>(data);
		return FindSettingInternal(group, key, &typeDator);
	};

protected:

	void LoadSettingsInternal(const std::string& iniContent);

	std::string GetIniContentsInternal();
	
	void AddKeyGroup(const AS_String& group, const AS_String& key, const std::shared_ptr<IDator> pDator);
	
	bool FindGroupInternal(const AS_String& group, AutoSettingGroup** ppGroup);
	void DeleteKeyGroup(const AS_String& group, const AS_String& key);
	
	void DeleteGroupInternal(const AS_String& group);

private:
	std::vector<AutoSettingGroup> m_Groups;
};





