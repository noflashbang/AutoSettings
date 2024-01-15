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

enum AUTOSETTING_CODE
{
	AS_ALL = -1,
	AS_DATORED = 1,
	AS_LOADED = 2,
	AS_ADDED = 4,
	AS_UPDATE = 8
};

class AutoSetting
{
public:
	AutoSetting()
	{
		m_FilePath = "";
	};
	AutoSetting(char* path)
	{
		LoadSettings(path);
	};
	AutoSetting(std::string path)
	{
		LoadSettings(path);
	};
	~AutoSetting()
	{
	};

	//sets a value -> if not found it will be added, if found the ini value will be updated
	void SetSetting(std::string Group, std::string Key, IDator* pDator);

	//retrives a value -> if not found it will be added, if found the dator value will be updated
	void GetSetting(std::string Group, std::string Key, IDator* pDator);

	//retrives a value -> if not found it will not be added, if found the dator value will be updated (true on success)
	bool FindSetting(std::string Group, std::string Key, IDator* pDator);

	//removes a setting
	void DeleteSetting(std::string Group, std::string Key);

	//removes a group
	void DeleteGroup(std::string Group);

	//parses an ini file
	void LoadSettings(std::string path);

	//creates an ini file
	void SaveSettings(std::string path, int Mode = AS_ALL);

	//Add/replace a group
	void AddGroup(std::string Group, AutoSettingGroup* pGroup);

	//retrives a group (true on success)
	bool FindGroup(std::string Group, AutoSettingGroup* pGroup);

	//retrives all the groups
	void GetAllGroups(std::vector<AutoSettingGroup>* pGroups);

	template<typename T>
	void SetSettingDirect(std::string Group, std::string Key, T& Data)
	{
		Dator<T> typeDator(Data);
		Util::StringToUpper(&Group);
		Util::StringToUpper(&Key);
		SetSettingInternal(Group, Key, &typeDator, false);
	};

	template<typename T>
	void SetSettingDirect(std::string Group, std::string Key, std::vector<T>& Data)
	{
		Dator<std::vector<T>> typeDator(Data);
		Util::StringToUpper(&Group);
		Util::StringToUpper(&Key);
		SetSettingInternal(Group, Key, &typeDator, false);
	};

	template<typename T>
	void GetSettingDirect(std::string Group, std::string Key, T& Data)
	{
		Dator<T> typeDator(Data);
		Util::StringToUpper(&Group);
		Util::StringToUpper(&Key);
		GetSettingInternal(Group, Key, &typeDator, false);
	};

	template<typename T>
	void GetSettingDirect(std::string Group, std::string Key, std::vector<T>& Data)
	{
		Dator<std::vector<T>> typeDator(Data);
		Util::StringToUpper(&Group);
		Util::StringToUpper(&Key);
		GetSettingInternal(Group, Key, &typeDator, false);
	};

	template<typename T>
	bool FindSettingDirect(std::string Group, std::string Key, T& Data)
	{
		Dator<T> typeDator(Data);
		Util::StringToUpper(&Group);
		Util::StringToUpper(&Key);
		return FindSettingInternal(Group, Key, &typeDator, false);
	};

	template<typename T>
	bool FindSettingDirect(std::string Group, std::string Key, T* Data)
	{
		Dator<std::vector<T>> typeDator(Data);
		Util::StringToUpper(&Group);
		Util::StringToUpper(&Key);
		return FindSettingInternal(Group, Key, &typeDator, false);
	};

protected:
	void SetSettingInternal(std::string Group, std::string Key, IDator* pDator, bool DatorPersists = false);
	void GetSettingInternal(std::string Group, std::string Key, IDator* pDator, bool DatorPersists = false);
	bool FindSettingInternal(std::string Group, std::string Key, IDator* pDator, bool DatorPersists = false);
	void LoadSettingsInternal(std::string path);
	void SaveSettingsInternal(std::string path, int Mode);
	void AddKeyGroup(std::string Group, std::string Key, IDator* pDator, bool DatorPersists = false);
	bool FindGroupInternal(std::string Group, AutoSettingGroup** ppGroup);
	void DeleteKeyGroup(std::string Group, std::string Key);
	void AddGroupInternal(AutoSettingGroup* pGroup);
	void DeleteGroupInternal(std::string Group);

private:
	std::string m_FilePath;
	std::vector<AutoSettingGroup> m_Groups;
};





