#pragma once

#include "StandardLib.h"

#include "Util.h"
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

	AutoSetting(std::string iniContent)
	{
		LoadSettings(iniContent);
	};

	~AutoSetting()
	{
	};

	//sets a value -> if not found it will be added, if found the ini value will be updated
	void SetSetting(const std::string& group, const std::string& key, IDator* pDator);

	//retrives a value -> if not found it will be added, if found the dator value will be updated
	void GetSetting(const std::string& group, const std::string& key, IDator* pDator);

	//retrives a value -> if not found it will not be added, if found the dator value will be updated (true on found)
	bool FindSetting(const std::string& group, const std::string& key, IDator* pDator);

	void DeleteSetting(const std::string& group, const std::string& key);

	void DeleteGroup(const std::string& group);

	void LoadSettings(const std::string& iniContent);

	std::string GetIniContents();

	template<typename T>
	void SetSetting(const std::string& group, const std::string& key, T& Data)
	{
		Dator<T> typeDator(Data);
		SetSettingInternal(Group, Key, &typeDator, false);
	};

	template<typename T>
	void SetSetting(const std::string& group, const std::string& key, std::vector<T>& Data)
	{
		Dator<std::vector<T>> typeDator(Data);
		SetSettingInternal(Group, Key, &typeDator, false);
	};

	template<typename T>
	void GetSetting(const std::string& group, const std::string& key, T& Data)
	{
		Dator<T> typeDator(Data);
		GetSettingInternal(Group, Key, &typeDator, false);
	};

	template<typename T>
	void GetSetting(const std::string& group, const std::string& key, std::vector<T>& Data)
	{
		Dator<std::vector<T>> typeDator(Data);
		GetSettingInternal(Group, Key, &typeDator, false);
	};

	template<typename T>
	bool FindSetting(const std::string& group, const std::string& key, T& Data)
	{
		Dator<T> typeDator(Data);
		return FindSettingInternal(Group, Key, &typeDator, false);
	};

	template<typename T>
	bool FindSetting(const std::string& group, const std::string& key, std::vector<T>& Data)
	{
		Dator<std::vector<T>> typeDator(Data);
		return FindSettingInternal(Group, Key, &typeDator, false);
	};

protected:

	void SetSettingInternal(const std::string& group, const std::string& key, IDator* pDator, bool DatorPersists = false);
	void GetSettingInternal(const std::string& group, const std::string& key, IDator* pDator, bool DatorPersists = false);
	bool FindSettingInternal(const std::string& group, const std::string& key, IDator* pDator, bool DatorPersists = false);

	void LoadSettingsInternal(const std::string& iniContent);

	std::string GetIniContentsInternal();
	
	void AddKeyGroup(const std::string& group, const std::string& key, IDator* pDator, bool DatorPersists = false);
	
	bool FindGroupInternal(const std::string& group, AutoSettingGroup** ppGroup);
	void DeleteKeyGroup(const std::string& group, const std::string& key);
	
	void DeleteGroupInternal(const std::string& group);

private:
	std::vector<AutoSettingGroup> m_Groups;
};





